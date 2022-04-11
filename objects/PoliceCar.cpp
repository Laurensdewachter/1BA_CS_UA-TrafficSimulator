#include "PoliceCar.h"
#include "../DesignByContract.h"
#include "../Variables.h"

#include <cmath>

PoliceCar::PoliceCar(const std::string &street, double position) : Vehicle(street, position, policeCarLength, policeCarMaxSpeed, true) {
    // TODO: ask if initcheck should be of super- or subclass

    ENSURE(properlyInitialized(), "PoliceCar constructor did not end in an initialized state");
}

void PoliceCar::drive(Vehicle* vehicleInFront) {
    REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling drive()");

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

    // TODO: ask about ENSURE here
}

void PoliceCar::brake() {
    REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling brake()");

    fMaxSpeed = gSlowFactor * policeCarMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }
}

void PoliceCar::stop() {
    REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling stop()");

    fAcceleration = -((policeCarMaxBrakeFactor * fSpeed) / fMaxSpeed);
}

void PoliceCar::setMaxSpeed() {
    REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling setMaxSpeed()");

    fMaxSpeed = policeCarMaxSpeed;

    ENSURE(fMaxSpeed == policeCarMaxSpeed, "setMaxSpeed() postcondition");
}