// ===========================================================
// Name         : VehicleGenerator.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `VehicleGenerator` class
// ===========================================================

#ifndef PSE_VEHICLEGENERATOR_H
#define PSE_VEHICLEGENERATOR_H

#include <iostream>
#include "../DesignByContract.h"

class VehicleGenerator {
    VehicleGenerator* _initCheck;
    std::string street;
    int frequency;

public:
    /*
     * ENSURE(properlyInitialized(), "VehicleGenerator constructor did not end in an initialized state")
     */
    VehicleGenerator();

    virtual ~VehicleGenerator();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setStreet()")
     * ENSURE(VehicleGenerator::street == s, "setStreet() postcondition")
     */
    void setStreet(const std::string &s);

    /*
     * REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setFrequency()")
     * ENSURE(VehicleGenerator::frequency == f, "setFrequency() postcondition")
     */
    void setFrequency(int f);

    /*
     * REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getStreet()")
     */
    const std::string &getStreet() const;

    /*
     * REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getFrequency()")
     */
    int getFrequency() const;
};


#endif
