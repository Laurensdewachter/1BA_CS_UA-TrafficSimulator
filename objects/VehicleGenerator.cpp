// ===========================================================
// Name         : VehicleGenerator.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `VehicleGenerator` class
// ===========================================================

#include "VehicleGenerator.h"
#include "../DesignByContract.h"

VehicleGenerator::VehicleGenerator(const std::string &street, int frequency, const std::string &type) :
            fStreet(street), fFrequency(frequency), fType(type), fTimeSinceLastSpawn(0) {
    VehicleGenerator::_initCheck = this;

    ENSURE(properlyInitialized(), "VehicleGenerator constructor did not end in an initialized state");
}

VehicleGenerator::~VehicleGenerator() {}

bool VehicleGenerator::properlyInitialized() const {
    return VehicleGenerator::_initCheck == this;
}

void VehicleGenerator::setStreet(const std::string &s) {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setStreet()");

    fStreet = s;

    ENSURE(fStreet == s, "setStreet() postcondition");
}

void VehicleGenerator::setFrequency(int f) {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setFrequency()");

    fFrequency = f;

    ENSURE(fFrequency == f, "setFrequency() postcondition");
}

void VehicleGenerator::setTimeSinceLastSpawn(double t) {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setTimeSinceLastSpawn()");
    REQUIRE(t >= 0, "time was negative at setTimeSinceLastSpawn()");

    fTimeSinceLastSpawn = t;

    ENSURE(fTimeSinceLastSpawn == t, "setTimeSinceLastSpawn() postcondition");
}

const std::string &VehicleGenerator::getStreet() const {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getStreet()");

    return fStreet;
}

int VehicleGenerator::getFrequency() const {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getFrequency()");

    return fFrequency;
}

const std::string &VehicleGenerator::getType() const {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getType()");

    return fType;
}

double VehicleGenerator::getTimeSinceLastSpawn() const {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getTimeSinceLastSpawn()");

    return fTimeSinceLastSpawn;
}
