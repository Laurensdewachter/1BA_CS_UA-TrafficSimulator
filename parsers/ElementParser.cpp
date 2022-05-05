// ===========================================================
// Name         : ElementParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is used to parse an XML file that contains either a `Street`, `TrafficLight`, `Vehicle`
//                or `VehicleGenerator` element
// ===========================================================

#include "ElementParser.h"
#include "StreetParser.h"
#include "TrafficLightParser.h"
#include "VehicleParser.h"
#include "VehicleGeneratorParser.h"
#include "BusStopParser.h"
#include "CrossroadParser.h"

ElementParser::ElementParser() {
    _initCheck = this;
    ENSURE(properlyInitialized(), "ElementParser constructor did not end in an initialized state");
}

ElementParser::~ElementParser() {}

bool ElementParser::properlyInitialized() const {
    return ElementParser::_initCheck == this;
}

EParserSucces ElementParser::parseFile(const std::string &filename, std::ostream &errStream) {
    REQUIRE(properlyInitialized(), "ElementParser wasn't initialized when calling parseFile()");
    REQUIRE(errStream.good(), "The errorStream wasn't good");

    EParserSucces endResult = Success;

    if (!doc.LoadFile(filename.c_str())) {
        errStream << "XML IMPORT ABORTED: " << doc.ErrorDesc() << std::endl;
        return ImportAborted;
    }
    root = doc.FirstChildElement();
    if (root == NULL) {
        errStream << "XML PARTIAL IMPORT: No root element." << std::endl;
        endResult = PartialImport;
    } else {
        TiXmlElement *elem = root->FirstChildElement();
        while (elem != NULL) {
            try {
                std::string type = elem->Value();

                if (type == "BAAN") {
                    StreetParser sParser;
                    if (sParser.parseStreet(elem, errStream)) {
                        fStreets.push_back(sParser.getStreet());
                    } else {
                        endResult = PartialImport;
                    }
                    elem = elem->NextSiblingElement();
                    continue;
                }
                if (type == "VERKEERSLICHT") {
                    TrafficLightParser tlParser;
                    if (tlParser.parseTrafficLight(elem, errStream)) {
                        fTrafficLights.push_back(tlParser.getTrafficLight());
                    } else {
                        endResult = PartialImport;
                    }
                    elem = elem->NextSiblingElement();
                    continue;
                }
                if (type == "VOERTUIG") {
                    VehicleParser vParser;
                    if (vParser.parseVehicle(elem, errStream)) {
                        fVehicles.push_back(vParser.getVehicle());
                    } else {
                        endResult = PartialImport;
                    }
                    elem = elem->NextSiblingElement();
                    continue;
                }
                if (type == "VOERTUIGGENERATOR") {
                    VehicleGeneratorParser vgParser;
                    if (vgParser.parseVehicleGenerator(elem, errStream)) {
                        fVehicleGenerators.push_back(vgParser.getVehicleGenerator());
                    } else {
                        endResult = PartialImport;
                    }
                    elem = elem->NextSiblingElement();
                    continue;
                }
                if (type == "BUSHALTE") {
                    BusStopParser bsParser;
                    if (bsParser.parseBusStop(elem, errStream)) {
                        fBusStops.push_back(bsParser.getBusStop());
                    } else {
                        endResult = PartialImport;
                    }
                        elem = elem->NextSiblingElement();
                        continue;
                }
                if (type == "KRUISPUNT") {
                    CrossroadParser cParser;
                    if (cParser.parseCrossroad(elem, errStream)) {
                        std::pair<std::pair<std::string, unsigned int>, std::pair<std::string, unsigned int> > crossroadPair;
                        crossroadPair.first = cParser.getStreet1();
                        crossroadPair.second = cParser.getStreet2();
                        fCrossroads.push_back(crossroadPair);
                    } else {
                        endResult = PartialImport;
                    }
                    elem = elem->NextSiblingElement();
                    continue;
                }
                errStream << "XML IMPORT: Unexpected element <" << type << ">." << std::endl;

            } catch (std::exception & e) {
                    errStream << "XML PARTIAL IMPORT: " << e.what() << "." << std::endl;
                    endResult = PartialImport;
                }

                elem = elem->NextSiblingElement();
            }
        }
    doc.Clear();

    return endResult;
}

std::vector<Street*> ElementParser::getStreets() const {
    REQUIRE(properlyInitialized(), "ElementParser wasn't initialized when calling getStreets()");

    return fStreets;
}

std::vector<TrafficLight*> ElementParser::getTrafficLights() const {
    REQUIRE(properlyInitialized(), "ElementParser wasn't initialized when calling getTrafficLights()");

    return fTrafficLights;
}

std::vector<Vehicle*> ElementParser::getVehicles() const {
    REQUIRE(properlyInitialized(), "ElementParser wasn't initialized when calling getVehicles()");

    return fVehicles;
}

std::vector<VehicleGenerator*> ElementParser::getVehicleGenerators() const {
    REQUIRE(properlyInitialized(), "ElementParser wasn't initialized when calling getVehicleGenerators()");

    return fVehicleGenerators;
}

std::vector<BusStop *> ElementParser::getBusStops() const {
    REQUIRE(properlyInitialized(), "ElementParser wasn't initialized when calling getBusStops()");

    return fBusStops;
}

const std::vector<std::pair<std::pair<std::string, unsigned int>, std::pair<std::string, unsigned int> > > &ElementParser::getCrossroads() const {
    REQUIRE(properlyInitialized(), "ElementParser wasn't initialized when calling getCrossroads()");

    return fCrossroads;
}
