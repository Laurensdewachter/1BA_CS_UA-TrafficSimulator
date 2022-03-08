// ===========================================================
// Name         : ElementParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is used to parse an XML file that contains either a `Street`, `TrafficLight` or `Vehicle` element
// ===========================================================

#include "ElementParser.h"


bool ElementParser::parseFile(const std::string &filename) {
    if (!doc.LoadFile(filename.c_str())) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return false;
    }
    root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return false;
    }
    // strcmp: https://stackoverflow.com/questions/15050766/comparing-the-values-of-char-arrays-in-c
    if (strcmp(root->Value(), "BAAN") == 0) {
        StreetParser parser;
        parser.parseStreet(root);
        streets.push_back(parser.getStreet());
    }
    else if (strcmp(root->Value(), "VERKEERSLICHT") == 0) {
        TrafficLightParser parser;
        parser.parseTrafficLight(root);
        trafficLights.push_back(parser.getTrafficLight());
    }
    else if (strcmp(root->Value(), "VOERTUIG") == 0) {
        VehicleParser parser;
        parser.parseVehicle(root);
        vehicles.push_back(parser.getVehicle());
    }
    else if (strcmp(root->Value(), "VOERTUIGGENERATOR") == 0) {
        VehicleGeneratorParser parser;
        parser.parseVehicleGenerator(root);
        vehicleGenerators.push_back(parser.getVehicleGenerator());
    }
    doc.Clear();
    return true;
}