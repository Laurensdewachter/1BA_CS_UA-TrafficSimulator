// ===========================================================
// Name         : ElementParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is used to parse an XML file that contains either a `Street`, `TrafficLight`, `Vehicle`
//                or `VehicleGenerator` element
// ===========================================================

#ifndef PSE_ELEMENTPARSER_H
#define PSE_ELEMENTPARSER_H

#include <iostream>
#include <vector>
#include <map>
#include "tinyxml/tinyxml.h"
#include "../DesignByContract.h"
#include "StreetParser.h"
#include "TrafficLightParser.h"
#include "VehicleParser.h"
#include "VehicleGeneratorParser.h"
#include "CrossroadParser.h"

enum EParserSucces {
    Success,
    PartialImport,
    ImportAborted
};

class Street;
class TrafficLight;
class Vehicle;
class VehicleGenerator;
class Crossroad;

class ElementParser {
    TiXmlElement* root;
    TiXmlDocument doc;
    ElementParser* _initCheck;

    std::vector<Street*> fStreets;
    std::vector<TrafficLight*> fTrafficLights;
    std::vector<Vehicle*> fVehicles;
    std::vector<VehicleGenerator*> fVehicleGenerators;

public:
    /*
     * ENSURE(properlyInitialized(), "ElementParser constructor did not end in an initialized state")
     */
    ElementParser();

    ~ElementParser();

    bool properlyInitialized() const;

    /*
     * This method loads an XML file and immediately parses it using the individual parsers for each element type.
     * Returns true when the file was loaded successfully.
     * REQUIRE(properlyInitialized(), "ElementParser wasn't initialized when calling parseFile()")
     * REQUIRE(errStream.good(), "The errorStream wasn't good")
     */
    EParserSucces parseFile(const std::string &filename, std::ostream &errStream);

    /*
     * ENSURE(properlyInitialized(), "ElementParser wasn't initialized when calling getStreets()")
     */
    std::vector<Street*> getStreets() const;

    /*
     * ENSURE(properlyInitialized(), "ElementParser wasn't initialized when calling getTrafficLights()")
     */
    std::vector<TrafficLight*> getTrafficLights() const;

    /*
     * ENSURE(properlyInitialized(), "ElementParser wasn't initialized when calling getVehicles()")
     */
    std::vector<Vehicle*> getVehicles() const;

    /*
     * ENSURE(properlyInitialized(), "ElementParser wasn't initialized when calling getVehicleGenerators()")
     */
    std::vector<VehicleGenerator*> getVehicleGenerators() const;



};


#endif
