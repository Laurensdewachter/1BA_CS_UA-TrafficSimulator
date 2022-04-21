// ===========================================================
// Name         : Vehicle.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is contains the `Vehicle` class
// ===========================================================

#include "Vehicle.h"
#include "../DesignByContract.h"
#include "../Variables.h"

#include <cmath>

Vehicle::Vehicle(const std::string &street, double position, EVehicleType type) :
            fStreet(street), fPosition(position), fType(type), fSpeed(0), fAcceleration(0) {

    switch (fType) {
        case car: fMaxSpeed = carMaxSpeed;
        case bus: fMaxSpeed = busMaxSpeed;
        case fireEngine: fMaxSpeed = fireEngineMaxSpeed;
        case ambulance: fMaxSpeed = ambulanceMaxSpeed;
        case policeCar: fMaxSpeed = policeCarMaxSpeed;
    }

    _initCheck = this;

    ENSURE(properlyInitialized(), "Vehicle constructor did not end in an initialized state");
}

Vehicle::~Vehicle() {}

bool Vehicle::properlyInitialized() const {
    return _initCheck == this;
}

const std::string &Vehicle::getStreet() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getStreet()");

    return fStreet;
}

double Vehicle::getPosition() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getPosition()");

    return fPosition;
}

double Vehicle::getSpeed() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getSpeed()");

    return fSpeed;
}

double Vehicle::getLength() const {
    switch (fType) {
        case car: return carLength;
        case bus: return busLength;
        case fireEngine: return fireEngineLength;
        case ambulance: return ambulanceLength;
        case policeCar: return policeCarLength;
    }
    return -1;
}

EVehicleType Vehicle::getType() const {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getType()");

    return fType;
}

void Vehicle::drive(Vehicle* vehicleInFront) {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling drive()");

    double startPosition = fPosition;

    double minFollowDistance;
    double maxAcceleration;
    double maxBrakeFactor;

    switch (fType) {
        case car: {
            minFollowDistance = carMinFollowDistance;
            maxAcceleration = carMaxAcceleration;
            maxBrakeFactor = carMaxBrakeFactor;
            break;
        }
        case bus: {
            minFollowDistance = busMinFollowDistance;
            maxAcceleration = busMaxAcceleration;
            maxBrakeFactor = busMaxBrakeFactor;
            break;
        }
        case fireEngine: {
            minFollowDistance = fireEngineMinFollowDistance;
            maxAcceleration = fireEngineMaxAcceleration;
            maxBrakeFactor = fireEngineMaxBrakeFactor;
            break;
        }
        case ambulance: {
            minFollowDistance = ambulanceMinFollowDistance;
            maxAcceleration = ambulanceMaxAcceleration;
            maxBrakeFactor = ambulanceMaxBrakeFactor;
            break;
        }
        case policeCar: {
            minFollowDistance = policeCarMinFollowDistance;
            maxAcceleration = policeCarMaxAcceleration;
            maxBrakeFactor = policeCarMaxBrakeFactor;
            break;
        }
    }

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
        delta = (minFollowDistance + std::max(0.0, (fSpeed + ((fSpeed * deltaV) / (2 * sqrt(maxAcceleration * maxBrakeFactor)))))) / deltaX;
    }
    fAcceleration = carMaxAcceleration * (1 - pow(fSpeed / fMaxSpeed, 4) - pow(delta, 2));

    if (fSpeed + (fAcceleration*gSimulationTime) > 0) {
        ENSURE(fPosition >= startPosition, "drive() postcondition");
    }
}

void Vehicle::brake() {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling brake()");

    double startMaxSpeed = fMaxSpeed;

    double maxSpeed;

    switch (fType) {
        case car: {
            maxSpeed = carMaxSpeed;
            break;
        }
        case bus: {
            maxSpeed = busMaxSpeed;
            break;
        }
        case fireEngine: {
            maxSpeed = fireEngineMaxSpeed;
            break;
        }
        case ambulance: {
            maxSpeed = ambulanceMaxSpeed;
            break;
        }
        case policeCar: {
            maxSpeed = policeCarMaxSpeed;
            break;
        }
    }

    fMaxSpeed = gSlowFactor * maxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }

    ENSURE(fMaxSpeed <= maxSpeed, "brake() postcondition");
    ENSURE(fMaxSpeed <= startMaxSpeed, "brake() postcondition");
}

void Vehicle::stop() {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling stop()");

    double startAcceleration = fAcceleration;

    double maxBrakeFactor;

    switch (fType) {
        case car: {
            maxBrakeFactor = carMaxBrakeFactor;
            break;
        }
        case bus: {
            maxBrakeFactor = busMaxBrakeFactor;
            break;
        }
        case fireEngine: {
            maxBrakeFactor = fireEngineMaxBrakeFactor;
            break;
        }
        case ambulance: {
            maxBrakeFactor = ambulanceMaxBrakeFactor;
            break;
        }
        case policeCar: {
            maxBrakeFactor = policeCarMaxBrakeFactor;
            break;
        }
    }

    fAcceleration = -((maxBrakeFactor * fSpeed) / fMaxSpeed);
}

void Vehicle::setMaxSpeed() {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setMaxSpeed()");

    switch (fType) {
        case car: {
            fMaxSpeed = carMaxSpeed;
            break;
        }
        case bus: {
            fMaxSpeed = busMaxSpeed;
            break;
        }
        case fireEngine: {
            fMaxSpeed = fireEngineMaxSpeed;
            break;
        }
        case ambulance: {
            fMaxSpeed = ambulanceMaxSpeed;
            break;
        }
        case policeCar: {
            fMaxSpeed = policeCarMaxSpeed;
            break;
        }
    }
}
