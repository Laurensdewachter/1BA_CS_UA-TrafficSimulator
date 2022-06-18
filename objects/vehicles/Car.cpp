// ===========================================================
// Name         : Car.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Car` subclass
// ===========================================================

#include <cmath>
#include "Car.h"
#include "../../DesignByContract.h"
#include "../../Variables.h"

Car::Car(const std::string &street, double position) : Vehicle(street, position) {
    Car::_initCheck = this;
    Car::fMaxSpeed = carMaxSpeed;

    ENSURE(properlyInitialized(), "Car constructor did not end in an initialized state");
}

Car::~Car() {}

bool Car::properlyInitialized() const {
    return Car::_initCheck == this;
}

double Car::getLength() const {
    REQUIRE(properlyInitialized(), "Car wasn't initialized when calling getLength()");

    return carLength;
}

std::string Car::getType() const {
    REQUIRE(properlyInitialized(), "Car wasn't initialized when calling getType()");

    return  "Car";
}

char Car::getAcronym() const {
    REQUIRE(properlyInitialized(), "Car wasn't initialized when calling getAcronym()");

    return 'A';
}

void Car::drive(Vehicle *vehicleInFront) {
    REQUIRE(properlyInitialized(), "Car wasn't initialized when calling drive()");

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
        delta = (carMinFollowDistance + std::max(0.0, (fSpeed + ((fSpeed * deltaV) / (2 * sqrt(carMaxAcceleration * carMaxBrakeFactor)))))) / deltaX;
    }
    fAcceleration = carMaxAcceleration * (1 - pow(fSpeed / fMaxSpeed, 4) - pow(delta, 2));

    ENSURE(fPosition >= startPosition || std::abs(fPosition-startPosition) < 0.001, "drive() postcondition");
}

void Car::brake() {
    REQUIRE(properlyInitialized(), "Car wasn't initialized when calling brake()");

    double startMaxSpeed = fMaxSpeed;
    fMaxSpeed = gSlowFactor * carMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }

    ENSURE(fMaxSpeed <= carMaxSpeed, "brake() postcondition");
    ENSURE(fMaxSpeed <= startMaxSpeed, "brake() postcondition");
}

void Car::stop() {
    REQUIRE(properlyInitialized(), "Car wasn't initialized when calling stop()");

    double startAcceleration = fAcceleration;
    fAcceleration = -((carMaxBrakeFactor * fSpeed) / fMaxSpeed);

    ENSURE(fAcceleration <= startAcceleration, "stop() postcondition");
}

void Car::setMaxSpeed() {
    REQUIRE(properlyInitialized(), "Car wasn't initialized when calling setMaxSpeed()");

    fMaxSpeed = carMaxSpeed;
}

bool Car::hasPriority() const {
    REQUIRE(properlyInitialized(), "Car wasn't initialized when calling hasPriority()");

    return false;
}
