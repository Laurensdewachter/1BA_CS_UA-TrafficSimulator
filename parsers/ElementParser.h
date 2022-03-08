// ===========================================================
// Name         : ElementParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is used to parse an XML file that contains either a `Street`, `TrafficLight` or `Vehicle` element
// ===========================================================

#ifndef PSE_ELEMENTPARSER_H
#define PSE_ELEMENTPARSER_H

#include <iostream>
#include <vector>
#include "tinyxml/tinyxml.h"
#include "StreetParser.h"
#include "TrafficLightParser.h"
#include "VehicleParser.h"
#include "VehicleGeneratorParser.h"

class Street;
class TrafficLight;
class Vehicle;
class VehicleGenerator;

class ElementParser {
    TiXmlElement* root;
    TiXmlDocument doc;

    std::vector<Street*> streets;
    std::vector<TrafficLight*> trafficLights;
    std::vector<Vehicle*> vehicles;
    std::vector<VehicleGenerator*> vehicleGenerators;

public:
    ElementParser() {}
    ~ElementParser() {}

    /*
     * This method loads an XML file and immediately parses it using the individual parsers for each element type.
     * Returns true when the file was loaded successfully.
     */
    bool parseFile(const std::string &filename);
};


#endif
