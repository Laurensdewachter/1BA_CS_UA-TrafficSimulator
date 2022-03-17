// ===========================================================
// Name         : ElementParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is used to parse an XML file that contains either a `Street`, `TrafficLight`, `Vehicle`
//                or `VehicleGenerator` element
// ===========================================================

#include "ElementParser.h"

ElementParser::ElementParser() {
    ElementParser::_initCheck = this;
    ENSURE(properlyInitialized(), "ElementParser constructor did not end in an initialized state");
}

ElementParser::~ElementParser() {}

bool ElementParser::properlyInitialized() const {
    return ElementParser::_initCheck == this;
}

void ElementParser::parseFile(const std::string &filename, std::ostream &errStream) {
    REQUIRE(properlyInitialized(), "ElementParser wasn't initialized when calling parseFile()");
    REQUIRE(errStream.good(), "The errorStream wasn't good");

    if (!doc.LoadFile(filename.c_str())) {
        errStream << doc.ErrorDesc() << std::endl;
        return;
    }
    root = doc.FirstChildElement();
    if (root == NULL) {
        errStream << "Failed to load file: No root element" << std::endl;
    }

    TiXmlElement* elem = root->FirstChildElement();
    while (elem != NULL) {
        try {
            std::string type = elem->Value();

            if (type == "BAAN") {
                StreetParser sParser;
                sParser.parseStreet(elem, errStream);
                fStreets.push_back(sParser.getStreet());
            }
            else if (type == "VERKEERSLICHT") {

            }
            else if (type == "VOERTUIG") {

            }
            else if (type == "VOERTUIGGENERATOR") {

            }
            else {
                errStream << "Het element " << type << "bestaat niet in de simulatie" << std::endl;
            }
        }
        catch (std::exception &e) {
            errStream << e.what() << std::endl;
        }

        elem = elem->NextSiblingElement();
    }
/*
    for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        // strcmp: https://stackoverflow.com/questions/15050766/comparing-the-values-of-char-arrays-in-c
        if (strcmp(elem->Value(), "BAAN") == 0) {
            StreetParser parser;
            parser.parseStreet(elem, errStream);
            fStreets.push_back(parser.getStreet());
        }
        else if (strcmp(elem->Value(), "VERKEERSLICHT") == 0) {
            TrafficLightParser parser;
            parser.parseTrafficLight(elem);
            fTrafficLights.push_back(parser.getTrafficLight());
        }
        else if (strcmp(elem->Value(), "VOERTUIG") == 0) {
            VehicleParser parser;
            parser.parseVehicle(elem);
            fVehicles.push_back(parser.getVehicle());
        }
        else if (strcmp(elem->Value(), "VOERTUIGGENERATOR") == 0) {
            VehicleGeneratorParser parser;
            parser.parseVehicleGenerator(elem);
            fVehicleGenerators.push_back(parser.getVehicleGenerator());
        }
        else {
            errStream << "";
        }
    }
    */
    doc.Clear();
}

std::vector<Street*> ElementParser::getStreets() const {
    ENSURE(properlyInitialized(), "ElementParser wasn't initialized when calling getStreets()");
    return ElementParser::fStreets;
}

std::vector<TrafficLight*> ElementParser::getTrafficLights() const {
    ENSURE(properlyInitialized(), "ElementParser wasn't initialized when calling getTrafficLights()");
    return ElementParser::fTrafficLights;
}

std::vector<Vehicle*> ElementParser::getVehicles() const {
    ENSURE(properlyInitialized(), "ElementParser wasn't initialized when calling getVehicles()");
    return ElementParser::fVehicles;
}

std::vector<VehicleGenerator*> ElementParser::getVehicleGenerators() const {
    ENSURE(properlyInitialized(), "ElementParser wasn't initialized when calling getVehicleGenerators()");
    return ElementParser::fVehicleGenerators;
}