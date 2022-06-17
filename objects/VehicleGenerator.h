// ===========================================================
// Name         : VehicleGenerator.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `VehicleGenerator` class
// ===========================================================

#ifndef PSE_VEHICLEGENERATOR_H
#define PSE_VEHICLEGENERATOR_H

#include <iostream>

class VehicleGenerator {
    VehicleGenerator* _initCheck;

    std::string fStreet;
    int fFrequency;
    std::string fType;
    double fTimeSinceLastSpawn;

public:
    /*
     * ENSURE(properlyInitialized(), "VehicleGenerator constructor did not end in an initialized state")
     */
    VehicleGenerator(const std::string &street, int frequency, const std::string &type);

    virtual ~VehicleGenerator();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setStreet()")
     *
     * ENSURE(VehicleGenerator::fStreet == s, "setStreet() postcondition")
     */
    void setStreet(const std::string &s);

    /*
     * REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setFrequency()")
     *
     * ENSURE(VehicleGenerator::fFrequency == f, "setFrequency() postcondition")
     */
    void setFrequency(int f);

    /*
     * REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setTimeSinceLastSpawn()")
     *
     * ENSURE(VehicleGenerator::fTimeSinceLastSpawn == 0, "setTimeSinceLastSpawn() postcondition")
     */
    void setTimeSinceLastSpawn(double t);

    /*
     * REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getStreet()")
     */
    const std::string &getStreet() const;

    /*
     * REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getFrequency()")
     */
    int getFrequency() const;

    /*
     * REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getType()")
     */
    const std::string &getType() const;

    /*
     * REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getTimeSinceLastSpawn()")
     */
    double getTimeSinceLastSpawn() const;
};


#endif
