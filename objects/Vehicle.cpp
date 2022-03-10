// ===========================================================
// Name         : Vehicle.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Vehicle` class
// ===========================================================

#include "Vehicle.h"

Vehicle::Vehicle() {
    Vehicle::_initCheck = this;
    ENSURE(properlyInitialized(), "Vehicle constructor did not end in an initialized state");
}

Vehicle::~Vehicle() {}

bool Vehicle::properlyInitialized() const {
    return Vehicle::_initCheck == this;
}

void Vehicle::setStreet(const std::string &s) {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setStreet()");
    Vehicle::fStreet = s;
    ENSURE(Vehicle::fStreet == s, "setStreet() postcondition");
}

void Vehicle::setPosition(int p) {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setPosition()");
    Vehicle::fPosition = p;
    ENSURE(Vehicle::fPosition == p, "setPosition() postcondition");
}

const std::string &Vehicle::getStreet() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getStreet()");
    return Vehicle::fStreet;
}

int Vehicle::getPosition() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getPosition()");
    return Vehicle::fPosition;
}
