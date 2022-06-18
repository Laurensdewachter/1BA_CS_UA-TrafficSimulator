// ===========================================================
// Name         : Bus.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Bus` subclass
// ===========================================================

#include "Bus.h"
#include "../../DesignByContract.h"
#include "../../Variables.h"
#include <cmath>

Bus::Bus(const std::string &street, double position) : Vehicle(street, position) {
    Bus::_initCheck = this;
    Bus::fMaxSpeed = busMaxSpeed;

    ENSURE(properlyInitialized(), "Bus constructor did not end in an initialized state");
}

Bus::~Bus() {}

bool Bus::properlyInitialized() const {
    return Bus::_initCheck == this;
}

double Bus::getLength() const {
    REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling getLength()");

    return busLength;
}

double Bus::getWaitTime() const {
    REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling getWaitTime()");

    return fWaitTime;
}

void Bus::addWaitTime(double time) {
    REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling addWaitTime()");

    fWaitTime += time;
}

void Bus::clearWaitTime() {
    REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling clearWaitTime()");

    fWaitTime = 0;
}

std::string Bus::getType() const {
    REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling getType()");

    return "Bus";
}

char Bus::getAcronym() const {
    REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling getAcronym()");

    return 'B';
}

void Bus::drive(Vehicle *vehicleInFront) {
    REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling drive()");

    double startPosition = fPosition;
    if (fSpeed + (fAcceleration*gSimulationTime) < 0) {
        fPosition -= pow(fSpeed, 2)/(2*fAcceleration);
        fSpeed = 0;
    }
    else {
        fSpeed += fAcceleration * gSimulationTime;
        fPosition += fSpeed * gSimulationTime + fAcceleration*(pow(gSimulationTime, 2)/2);
    }
    double delta = 0;
    if (vehicleInFront != NULL) {
        double deltaX = vehicleInFront->getPosition() - fPosition - vehicleInFront->getLength();
        double deltaV = fSpeed - vehicleInFront->getSpeed();
        delta = (busMinFollowDistance + std::max(0.0, (fSpeed + ((fSpeed * deltaV) / (2 * sqrt(busMaxAcceleration * busMaxBrakeFactor)))))) / deltaX;
    }
    fAcceleration = busMaxAcceleration * (1 - pow(fSpeed / fMaxSpeed, 4) - pow(delta, 2));

    ENSURE(fPosition >= startPosition || std::abs(fPosition-startPosition) < 0.001, "drive() postcondition");
}

void Bus::brake() {
    REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling brake()");

    double startMaxSpeed = fMaxSpeed;
    fMaxSpeed = gSlowFactor * busMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }

    ENSURE(fMaxSpeed <= busMaxSpeed, "brake() postcondition");
    ENSURE(fMaxSpeed <= startMaxSpeed, "brake() postcondition");
}

void Bus::stop() {
    REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling stop()");

    double startAcceleration = fAcceleration;
    fAcceleration = -((busMaxBrakeFactor * fSpeed) / fMaxSpeed);

    ENSURE(fAcceleration <= startAcceleration, "stop() postcondition");
}

void Bus::setMaxSpeed() {
    REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling setMaxSpeed()");

    fMaxSpeed = busMaxSpeed;
}

bool Bus::hasPriority() const {
    REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling hasPriority()");

    return false;
}
