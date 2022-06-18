// ===========================================================
// Name         : FireEngine.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `FireEngine` subclass
// ===========================================================

#include <cmath>
#include "FireEngine.h"
#include "../../DesignByContract.h"
#include "../../Variables.h"

FireEngine::FireEngine(const std::string &street, double position) : Vehicle(street, position) {
    FireEngine::_initCheck = this;
    FireEngine::fMaxSpeed = fireEngineMaxSpeed;

    ENSURE(properlyInitialized(), "FireEngine constructor did not end in an initialized state");
}

FireEngine::~FireEngine() {}

bool FireEngine::properlyInitialized() const {
    return FireEngine::_initCheck == this;
}

double FireEngine::getLength() const {
    REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling getLength()");

    return fireEngineLength;
}

std::string FireEngine::getType() const {
    REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling getType()");

    return "FireEngine";
}

char FireEngine::getAcronym() const {
    REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling getAcronym()");

    return 'F';
}

void FireEngine::drive(Vehicle *vehicleInFront) {
    REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling drive()");

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
        delta = (fireEngineMinFollowDistance + std::max(0.0, (fSpeed + ((fSpeed * deltaV) / (2 * sqrt(fireEngineMaxAcceleration * fireEngineMaxBrakeFactor)))))) / deltaX;
    }
    fAcceleration = fireEngineMaxAcceleration * (1 - pow(fSpeed / fMaxSpeed, 4) - pow(delta, 2));

    ENSURE(fPosition >= startPosition || std::abs(fPosition-startPosition) < 0.001, "drive() postcondition");
}

void FireEngine::brake() {
    REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling brake()");

    double startMaxSpeed = fMaxSpeed;
    fMaxSpeed = gSlowFactor * fireEngineMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }

    ENSURE(fMaxSpeed <= fireEngineMaxSpeed, "brake() postcondition");
    ENSURE(fMaxSpeed <= startMaxSpeed, "brake() postcondition");
}

void FireEngine::stop() {
    REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling stop()");

    double startAcceleration = fAcceleration;
    fAcceleration = -((fireEngineMaxBrakeFactor * fSpeed) / fMaxSpeed);

    ENSURE(fAcceleration <= startAcceleration, "stop() postcondition");
}

void FireEngine::setMaxSpeed() {
    REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling setMaxSpeed()");

    fMaxSpeed = fireEngineMaxSpeed;
}

bool FireEngine::hasPriority() const {
    REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling hasPriority()");

    return true;
}
