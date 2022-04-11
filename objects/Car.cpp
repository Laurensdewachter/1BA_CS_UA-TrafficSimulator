#include "Car.h"
#include "../DesignByContract.h"
#include "../Variables.h"

#include <cmath>

Car::Car(const std::string &street, double position) : Vehicle(street, position, carLength, carMaxSpeed, false) {
    // TODO: ask if initcheck should be of super- or subclass

    ENSURE(properlyInitialized(), "Car constructor did not end in an initialized state");
}

void Car::drive(Vehicle* vehicleInFront) {
    REQUIRE(properlyInitialized(), "Car wasn't initialized when calling drive()");

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
        delta = (carMinFollowDistance + std::max(0.0, (fSpeed + ((fSpeed * deltaV) / (2 * sqrt(carMaxAcceleration * carMaxBrakeFactor)))))) / deltaX;
    }
    fAcceleration = carMaxAcceleration * (1 - pow(fSpeed / fMaxSpeed, 4) - pow(delta, 2));

    // TODO: ask about ENSURE here
}

void Car::brake() {
    REQUIRE(properlyInitialized(), "Car wasn't initialized when calling brake()");

    fMaxSpeed = gSlowFactor * carMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }
}

void Car::stop() {
    REQUIRE(properlyInitialized(), "Car wasn't initialized when calling stop()");

    fAcceleration = -((carMaxBrakeFactor * fSpeed) / fMaxSpeed);
}

void Car::setMaxSpeed() {
    REQUIRE(properlyInitialized(), "Car wasn't initialized when calling setMaxSpeed()");

    fMaxSpeed = carMaxSpeed;

    ENSURE(fMaxSpeed == carMaxSpeed, "setMaxSpeed() postcondition");
}