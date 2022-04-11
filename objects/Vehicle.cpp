// ===========================================================
// Name         : Vehicle.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is contains the `Vehicle` class
// ===========================================================

#include "Vehicle.h"
#include "../DesignByContract.h"
#include "../Variables.h"

#include <cmath>

Vehicle::Vehicle() : fSpeed(0), fAcceleration(0), fMaxSpeed(0) {
    _initCheck = this;

    ENSURE(properlyInitialized(), "Vehicle constructor did not end in an initialized state");
}

Vehicle::Vehicle(const std::string &street, double position, double length, double maxSpeed, bool hasPriority) :
            fStreet(street), fPosition(position), fHasPriority(hasPriority), fLength(length), fSpeed(0), fAcceleration(0),
            fMaxSpeed(maxSpeed) {
    _initCheck = this;

    ENSURE(properlyInitialized(), "Vehicle constructor did not end in an initialized state");
}

Vehicle::~Vehicle() {}

bool Vehicle::properlyInitialized() const {
    return _initCheck == this;
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

double Vehicle::getLength() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getLength()");

    return fLength;
}

bool Vehicle::hasPriority() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling hasPriority()");

    return fHasPriority;
}
