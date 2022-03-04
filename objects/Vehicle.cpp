// ===========================================================
// Name         : Vehicle.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Vehicle` class
// ===========================================================

#include "Vehicle.h"

Vehicle::Vehicle() {
    Vehicle::_initCheck = this;
    ENSURE(properlyInitialized(), "Vehicle constructor dit not end in a initialized state.");
}

Vehicle::~Vehicle() {}

bool Vehicle::properlyInitialized() const {
    return Vehicle::_initCheck == this;
}

void Vehicle::setStreet(const std::string &s) {
    REQUIRE(Vehicle::properlyInitialized(), "Vehicle wasn't initialized when calling `setStreet()`.");
    Vehicle::street = s;
    ENSURE(Vehicle::street == s, "`setStreet()` postcondition failed.");
}

void Vehicle::setPosition(int p) {
    REQUIRE(Vehicle::properlyInitialized(), "Vehicle wasn't initialized when calling `setPosition()`.");
    Vehicle::position = p;
    ENSURE(Vehicle::position == p, "`setPosition()` postcondition failed.");
}

const std::string &Vehicle::getStreet() const {
    REQUIRE(Vehicle::properlyInitialized(), "Vehicle wasn't initialized when calling `getStreet()`.");
    return Vehicle::street;
}

int Vehicle::getPosition() const {
    REQUIRE(Vehicle::properlyInitialized(), "Vehicle wasn't initialized when calling `getPosition()`.");
    return Vehicle::position;
}
