// ===========================================================
// Name         : Ambulance.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Ambulance` subclass
// ===========================================================

#include <cmath>
#include "Ambulance.h"
#include "../../DesignByContract.h"
#include "../../Variables.h"

Ambulance::Ambulance(const std::string &street, double position) : Vehicle(street, position) {
    Ambulance::_initCheck = this;
    Ambulance::fMaxSpeed = ambulanceMaxSpeed;

    ENSURE(properlyInitialized(), "Ambulance constructor did not end in an initialized state");
}

Ambulance::~Ambulance() {}

bool Ambulance::properlyInitialized() const {
    return Ambulance::_initCheck == this;
}

double Ambulance::getLength() const {
    REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling getLength()");

    return ambulanceLength;
}

std::string Ambulance::getType() const {
    REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling getType()");

    return "Ambulance";
}

char Ambulance::getAcronym() const {
    REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling getAcronym()");

    return 'Z';
}

void Ambulance::drive(Vehicle *vehicleInFront) {
    REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling drive()");

    unsigned int startPosition = fPosition;
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
        delta = (ambulanceMinFollowDistance + std::max(0.0, (fSpeed + ((fSpeed * deltaV) / (2 * sqrt(ambulanceMaxAcceleration * ambulanceMaxBrakeFactor)))))) / deltaX;
    }
    fAcceleration = ambulanceMaxAcceleration * (1 - pow(fSpeed / fMaxSpeed, 4) - pow(delta, 2));

    ENSURE(fPosition >= startPosition || std::abs(fPosition-startPosition) < 0.001, "drive() postcondition");
}

void Ambulance::brake() {
    REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling brake()");

    double startMaxSpeed = fMaxSpeed;
    fMaxSpeed = gSlowFactor * ambulanceMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }


    ENSURE(fMaxSpeed <= ambulanceMaxSpeed, "brake() postcondition");
    ENSURE(fMaxSpeed <= startMaxSpeed, "brake() postcondition");
}

void Ambulance::stop() {
    REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling stop()");

    double startAcceleration = fAcceleration;
    fAcceleration = -((ambulanceMaxBrakeFactor * fSpeed) / fMaxSpeed);

    ENSURE (fAcceleration <= startAcceleration, "stop() postcondition");
}

void Ambulance::setMaxSpeed() {
    REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling setMaxSpeed()");

    fMaxSpeed = ambulanceMaxSpeed;
}

bool Ambulance::hasPriority() const {
    REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling hasPriority()");

    return true;
}
