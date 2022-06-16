// ===========================================================
// Name         : VehicleParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.2
// Description  : This code is used to parse an XML file that contains a `Vehicle`.
// ===========================================================

#ifndef PSE_VEHICLEPARSER_H
#define PSE_VEHICLEPARSER_H

#include <iostream>
#include "tinyxml/tinyxml.h"

class Vehicle;

class VehicleParser {
    VehicleParser* _initCheck;

    Vehicle* fVehicle;

public:
    /*
     * ENSURE(properlyInitialized(), "VehicleParser constructor did not end in an initialized state")
     */
    VehicleParser();

    virtual ~VehicleParser();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "VehicleParser wasn't initialized when calling parseVehicle()")
     * REQUIRE(errStream.good(), "The errorStream wasn't good at the beginning of parseVehicle()")
     *
     * ENSURE(fVehicle != NULL, "VehicleParser could not create a Vehicle")
     * ENSURE(fVehicle->getStreet() == fStreet, "parseVehicle() postcondition")
     * ENSURE(fVehicle->getPosition() == fPosition, "parseVehicle() postcondition")
     * ENSURE(errStream.good(), "The errorStream wasn't good at the end of parseVehicle()")
     */
    bool parseVehicle(TiXmlElement* VOERTUIG, std::ostream &errStream);

    /*
     * REQUIRE(properlyInitialized(), "VehicleParser wasn't initialized when calling getVehicle()")
     * REQUIRE(fVehicle != NULL, "VehicleParser had no vehicle when calling getVehicle()")
     */
    Vehicle *getVehicle() const;
};


#endif