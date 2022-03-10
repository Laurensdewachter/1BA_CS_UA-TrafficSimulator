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

void ElementParser::parseFile(const std::string &filename) {
    REQUIRE(properlyInitialized(), "ElementParser wasn't initialized when calling parseFile()");

    if (!doc.LoadFile(filename.c_str())) {
        throw ParseException(doc.ErrorDesc());
    }
    root = doc.FirstChildElement();
    if (root == NULL) {
        throw ParseException("Failed to load file: No root element.");
    }
  
    for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        // strcmp: https://stackoverflow.com/questions/15050766/comparing-the-values-of-char-arrays-in-c
        if (strcmp(elem->Value(), "BAAN") == 0) {
            StreetParser parser;
            parser.parseStreet(elem);
            fStreets.push_back(parser.getStreet());
        } else if (strcmp(elem->Value(), "VERKEERSLICHT") == 0) {
            TrafficLightParser parser;
            parser.parseTrafficLight(elem);
            fTrafficLights.push_back(parser.getTrafficLight());
        } else if (strcmp(elem->Value(), "VOERTUIG") == 0) {
            VehicleParser parser;
            parser.parseVehicle(elem);
            fVehicles.push_back(parser.getVehicle());
        } else if (strcmp(elem->Value(), "VOERTUIGGENERATOR") == 0) {
            VehicleGeneratorParser parser;
            parser.parseVehicleGenerator(elem);
            fVehicleGenerators.push_back(parser.getVehicleGenerator());
        }
    }
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