// ===========================================================
// Name         : VehicleGeneratorParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `VehicleGenerator`.
// ===========================================================

#ifndef PSE_VEHICLEGENERATORPARSER_H
#define PSE_VEHICLEGENERATORPARSER_H

#include <iostream>
#include <sstream>
#include "ParseException.h"
#include "tinyxml/tinyxml.h"

class VehicleGenerator;

class VehicleGeneratorParser {
    VehicleGenerator* vehicleGenerator;
    VehicleGeneratorParser* _initCheck;

public:
    /*
     * ENSURE(properlyInitialized(), "VehicleGeneratorParser constructor did not end in an initialized state")
     */
    VehicleGeneratorParser();

    virtual ~VehicleGeneratorParser();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "VehicleGeneratorParser wasn't initialized when calling parseVehicleGenerator()")
     * ENSURE(vehicleGenerator->getStreet() == street, "parseVehicleGenerator() postcondition")
     * ENSURE(vehicleGenerator->getFrequency() == frequency, "parseVehicleGenerator() postcondition")
     */
    void parseVehicleGenerator(TiXmlElement* VOERTUIGGENERATOR);

    /*
     * REQUIRE(properlyInitialized(), "VehicleGeneratorParser wasn't initialized when calling getVehicleGenerator()")
     */
    VehicleGenerator* getVehicleGenerator() const;
};


#endif
