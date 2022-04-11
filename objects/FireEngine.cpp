#include "FireEngine.h"
#include "../DesignByContract.h"
#include "../Variables.h"

#include <cmath>

FireEngine::FireEngine(const std::string &street, double position) : Vehicle(street, position, fireEngineLength, fireEngineMaxSpeed) {
    // TODO: ask if initcheck should be of super- or subclass

    ENSURE(properlyInitialized(), "FireEngine constructor did not end in an initialized state");
}

void FireEngine::drive(Vehicle* vehicleInFront) {
    REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling drive()");

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

    // TODO: ask about ENSURE here
}

void FireEngine::brake() {
    REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling brake()");

    fMaxSpeed = gSlowFactor * fireEngineMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }
}

void FireEngine::stop() {
    REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling stop()");

    fAcceleration = -((fireEngineMaxBrakeFactor * fSpeed) / fMaxSpeed);
}

void FireEngine::setMaxSpeed() {
    REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling setMaxSpeed()");

    fMaxSpeed = fireEngineMaxSpeed;

    ENSURE(fMaxSpeed == fireEngineMaxSpeed, "setMaxSpeed() postcondition");
}