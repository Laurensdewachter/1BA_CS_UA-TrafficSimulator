// ===========================================================
// Name         : Vehicle.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is contains the `Vehicle` class
// ===========================================================

#include "Vehicle.h"
#include "../DesignByContract.h"

Vehicle::Vehicle(const std::string &street, double position) :
    fStreet(street), fPosition(position), fSpeed(0), fAcceleration(0) {
    Vehicle::_initCheck = this;

    ENSURE(properlyInitialized(), "Vehicle constructor did not end in an initialized state");
}

Vehicle::~Vehicle() {}

bool Vehicle::properlyInitialized() const {
    return Vehicle::_initCheck == this;
}

const std::string &Vehicle::getStreet() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getStreet()");

    return fStreet;
}

double Vehicle::getPosition() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getPosition()");

    return fPosition;
}

double Vehicle::getSpeed() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getSpeed()");

    return fSpeed;
}
