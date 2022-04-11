#include "Ambulance.h"
#include "../DesignByContract.h"
#include "../Variables.h"

#include <cmath>

Ambulance::Ambulance(const std::string &street, double position) : Vehicle(street, position, ambulanceLength, ambulanceMaxSpeed) {
    // TODO: ask if initcheck should be of super- or subclass

    ENSURE(properlyInitialized(), "Ambulance constructor did not end in an initialized state");
}

void Ambulance::drive(Vehicle* vehicleInFront) {
    REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling drive()");

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

    // TODO: ask about ENSURE here
}

void Ambulance::brake() {
    REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling brake()");

    fMaxSpeed = gSlowFactor * ambulanceMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }
}

void Ambulance::stop() {
    REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling stop()");

    fAcceleration = -((ambulanceMaxBrakeFactor * fSpeed) / fMaxSpeed);
}

void Ambulance::setMaxSpeed() {
    REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling setMaxSpeed()");

    fMaxSpeed = ambulanceMaxSpeed;

    ENSURE(fMaxSpeed == ambulanceMaxSpeed, "setMaxSpeed() postcondition");
}