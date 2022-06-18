// ===========================================================
// Name         : PoliceCar.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `PoliceCar` subclass
// ===========================================================

#include <cmath>
#include "PoliceCar.h"
#include "../../DesignByContract.h"
#include "../../Variables.h"

PoliceCar::PoliceCar(const std::string &street, double position) : Vehicle(street, position) {
    PoliceCar::_initCheck = this;
    PoliceCar::fMaxSpeed = policeCarMaxSpeed;

    ENSURE(properlyInitialized(), "PoliceCar constructor did not end in an initialized state");
}

PoliceCar::~PoliceCar() {}

bool PoliceCar::properlyInitialized() const {
    return PoliceCar::_initCheck == this;
}

double PoliceCar::getLength() const {
    REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling getLength()");

    return policeCarLength;
}

std::string PoliceCar::getType() const {
    REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling getType()");

    return "PoliceCar";
}

char PoliceCar::getAcronym() const {
    REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling getAcronym()");

    return 'P';
}

void PoliceCar::drive(Vehicle *vehicleInFront) {
    REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling drive()");

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
        delta = (policeCarMinFollowDistance + std::max(0.0, (fSpeed + ((fSpeed * deltaV) / (2 * sqrt(policeCarMaxAcceleration * policeCarMaxBrakeFactor)))))) / deltaX;
    }
    fAcceleration = policeCarMaxAcceleration * (1 - pow(fSpeed / fMaxSpeed, 4) - pow(delta, 2));

    ENSURE(fPosition >= startPosition || std::abs(fPosition-startPosition) < 0.001, "drive() postcondition");
}

void PoliceCar::brake() {
    REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling brake()");

    double startMaxSpeed = fMaxSpeed;
    fMaxSpeed = gSlowFactor * policeCarMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }

    ENSURE(fMaxSpeed <= policeCarMaxSpeed, "brake() postcondition");
    ENSURE(fMaxSpeed <= startMaxSpeed, "brake() postcondition");
}

void PoliceCar::stop() {
    REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling stop()");

    double startAcceleration = fAcceleration;
    fAcceleration = -((policeCarMaxBrakeFactor * fSpeed) / fMaxSpeed);

    ENSURE(fAcceleration <= startAcceleration, "stop() postcondition");
}

void PoliceCar::setMaxSpeed() {
    REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling setMaxSpeed()");

    fMaxSpeed = policeCarMaxSpeed;
}

bool PoliceCar::hasPriority() const {
    REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling hasPriority()");

    return true;
}
