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
    // strcmp: https://stackoverflow.com/questions/15050766/comparing-the-values-of-char-arrays-in-c
    if (strcmp(root->Value(), "BAAN") == 0) {
        StreetParser parser;
        parser.parseStreet(root);
        fStreets.push_back(parser.getStreet());
    }
    else if (strcmp(root->Value(), "VERKEERSLICHT") == 0) {
        TrafficLightParser parser;
        parser.parseTrafficLight(root);
        fTrafficLights.push_back(parser.getTrafficLight());
    }
    else if (strcmp(root->Value(), "VOERTUIG") == 0) {
        VehicleParser parser;
        parser.parseVehicle(root);
        fVehicles.push_back(parser.getVehicle());
    }
    else if (strcmp(root->Value(), "VOERTUIGGENERATOR") == 0) {
        VehicleGeneratorParser parser;
        parser.parseVehicleGenerator(root);
        fVehicleGenerators.push_back(parser.getVehicleGenerator());
    }
    doc.Clear();
}