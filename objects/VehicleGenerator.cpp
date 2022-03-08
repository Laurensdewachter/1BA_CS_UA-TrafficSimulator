// ===========================================================
// Name         : VehicleGenerator.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `VehicleGenerator` class
// ===========================================================

#include "VehicleGenerator.h"

VehicleGenerator::VehicleGenerator() {
    VehicleGenerator::_initCheck = this;
    ENSURE(properlyInitialized(), "VehicleGenerator constructor did not end in an initialized state");
}

VehicleGenerator::~VehicleGenerator() {}

bool VehicleGenerator::properlyInitialized() const {
    return VehicleGenerator::_initCheck == this;
}

void VehicleGenerator::setStreet(const std::string &s) {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setStreet()");
    VehicleGenerator::street = s;
    ENSURE(VehicleGenerator::street == s, "setStreet() postcondition");
}

void VehicleGenerator::setFrequency(int f) {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling setFrequency()");
    VehicleGenerator::frequency = f;
    ENSURE(VehicleGenerator::frequency == f, "setFrequency() postcondition");
}

const std::string &VehicleGenerator::getStreet() const {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getStreet()");
    return VehicleGenerator::street;
}

int VehicleGenerator::getFrequency() const {
    REQUIRE(properlyInitialized(), "VehicleGenerator wasn't initialized when calling getFrequency()");
    return VehicleGenerator::frequency;
}
