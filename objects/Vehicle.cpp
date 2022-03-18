// ===========================================================
// Name         : Vehicle.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Vehicle` class
// ===========================================================

#include "Vehicle.h"

Vehicle::Vehicle() {
    Vehicle::fPosition = 0;
    Vehicle::fSpeed = 0;
    Vehicle::fAcceleration = 0;
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

double Vehicle::getPosition() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getPosition()");
    return Vehicle::fPosition;
}

double Vehicle::getSpeed() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getSpeed()");
    return Vehicle::fSpeed;
}

void Vehicle::drive(Vehicle* vehicleInFront) {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling drive()");
    if (fSpeed + (fAcceleration*gSimulationTime) < 0) {
        fPosition -= pow(fSpeed, 2)/(2*fAcceleration);
        fSpeed = 0;
    }
    else {
        fSpeed += fAcceleration*gSimulationTime;
        fPosition += fSpeed*gSimulationTime + fAcceleration*(pow(gSimulationTime, 2)/2);
    }
    double delta = 0;
    if (vehicleInFront != NULL) {
        double deltaX = vehicleInFront->getPosition() - fPosition - gLength;
        double deltaV = fSpeed - vehicleInFront->getSpeed();
        delta = (gMinFollowDistance + std::max(0.0, (fSpeed+((fSpeed*deltaV)/(2*sqrt(gMaxAcceleration*gMaxBrakeFactor))))))/deltaX;
    }
    fAcceleration = gMaxAcceleration*(1 - pow(fSpeed/gMaxSpeed, 4) - pow(delta, 2));
}