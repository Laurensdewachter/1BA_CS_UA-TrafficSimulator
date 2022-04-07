// ===========================================================
// Name         : VehicleGenerator.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `VehicleGenerator` class
// ===========================================================

#include "VehicleGenerator.h"

VehicleGenerator::VehicleGenerator() {
    VehicleGenerator::fTimeSinceLastSpawn = 0;
    VehicleGenerator::_initCheck = this;

    ENSURE(properlyInitialized(), "VehicleGenerator constructor did not end in an initialized state");
}

VehicleGenerator::~VehicleGenerator() {}

bool VehicleGenerator::properlyInitialized() const {
    return VehicleGenerator::_initCheck == this;
}

void VehicleGenerator::setStreet(const std::string &s) {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setStreet()");

    VehicleGenerator::fStreet = s;

    ENSURE(VehicleGenerator::fStreet == s, "setStreet() postcondition");
}

void VehicleGenerator::setFrequency(int f) {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setFrequency()");

    VehicleGenerator::fFrequency = f;

    ENSURE(VehicleGenerator::fFrequency == f, "setFrequency() postcondition");
}

void VehicleGenerator::setTimeSinceLastSpawn(double t) {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setTimeSinceLastSpawn()");

    VehicleGenerator::fTimeSinceLastSpawn = t;

    ENSURE(VehicleGenerator::fTimeSinceLastSpawn == t, "setTimeSinceLastSpawn() postcondition");
}

const std::string &VehicleGenerator::getStreet() const {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getStreet()");

    return VehicleGenerator::fStreet;
}

int VehicleGenerator::getFrequency() const {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getFrequency()");

    return VehicleGenerator::fFrequency;
}

double VehicleGenerator::getTimeSinceLastSpawn() const {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getTimeSinceLastSpawn()");

    return fTimeSinceLastSpawn;
}
