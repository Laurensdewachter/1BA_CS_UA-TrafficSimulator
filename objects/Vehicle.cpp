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

Vehicle::Vehicle(const std::string &street, double position) :
            fStreet(street), fPosition(position), fSpeed(0), fAcceleration(0),fTookTurn(0) {

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

void Vehicle::setPosition(double newPosition) {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setPosition()");

    this->fPosition = newPosition;
}

void Vehicle::setStreet(std::string newStreet) {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setStreet()");

    this->fStreet = newStreet;
}

bool Vehicle::hasTurned() {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling hasTurned()");

    return fTookTurn;
}
void Vehicle::setTurn(bool state) {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setTurn()");

    fTookTurn = state;
}

