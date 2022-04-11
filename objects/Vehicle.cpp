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

Vehicle::Vehicle(const std::string &street, double position, double length, double maxSpeed) : fStreet(street),
            fPosition(position), fLength(length), fSpeed(0), fAcceleration(0), fMaxSpeed(maxSpeed) {
    _initCheck = this;

    ENSURE(properlyInitialized(), "Vehicle constructor did not end in an initialized state");
}

Vehicle::~Vehicle() {}

bool Vehicle::properlyInitialized() const {
    return _initCheck == this;
}

void Vehicle::setStreet(const std::string &s) {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setStreet()");

    fStreet = s;

    ENSURE(fStreet == s, "setStreet() postcondition");
}

void Vehicle::setPosition(int p) {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setPosition()");

    fPosition = p;

    ENSURE(fPosition == p, "setPosition() postcondition");
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
