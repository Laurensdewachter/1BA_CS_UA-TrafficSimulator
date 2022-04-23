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
        case Car: {
            fMaxSpeed = carMaxSpeed;
        }
        case Bus: {
            fMaxSpeed = busMaxSpeed;
            break;
        }
        case FireEngine: {
            fMaxSpeed = fireEngineMaxSpeed;
            break;
        }
        case Ambulance: {
            fMaxSpeed = ambulanceMaxSpeed;
            break;
        }
        case PoliceCar: {
            fMaxSpeed = policeCarMaxSpeed;
            break;
        }
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
        case Car: return carLength;
        case Bus: return busLength;
        case FireEngine: return fireEngineLength;
        case Ambulance: return ambulanceLength;
        case PoliceCar: return policeCarLength;
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
        case Car: {
            minFollowDistance = carMinFollowDistance;
            maxAcceleration = carMaxAcceleration;
            maxBrakeFactor = carMaxBrakeFactor;
            break;
        }
        case Bus: {
            minFollowDistance = busMinFollowDistance;
            maxAcceleration = busMaxAcceleration;
            maxBrakeFactor = busMaxBrakeFactor;
            break;
        }
        case FireEngine: {
            minFollowDistance = fireEngineMinFollowDistance;
            maxAcceleration = fireEngineMaxAcceleration;
            maxBrakeFactor = fireEngineMaxBrakeFactor;
            break;
        }
        case Ambulance: {
            minFollowDistance = ambulanceMinFollowDistance;
            maxAcceleration = ambulanceMaxAcceleration;
            maxBrakeFactor = ambulanceMaxBrakeFactor;
            break;
        }
        case PoliceCar: {
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
        case Car: {
            maxSpeed = carMaxSpeed;
            break;
        }
        case Bus: {
            maxSpeed = busMaxSpeed;
            break;
        }
        case FireEngine: {
            maxSpeed = fireEngineMaxSpeed;
            break;
        }
        case Ambulance: {
            maxSpeed = ambulanceMaxSpeed;
            break;
        }
        case PoliceCar: {
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

    double maxBrakeFactor;

    switch (fType) {
        case Car: {
            maxBrakeFactor = carMaxBrakeFactor;
            break;
        }
        case Bus: {
            maxBrakeFactor = busMaxBrakeFactor;
            break;
        }
        case FireEngine: {
            maxBrakeFactor = fireEngineMaxBrakeFactor;
            break;
        }
        case Ambulance: {
            maxBrakeFactor = ambulanceMaxBrakeFactor;
            break;
        }
        case PoliceCar: {
            maxBrakeFactor = policeCarMaxBrakeFactor;
            break;
        }
    }

    fAcceleration = -((maxBrakeFactor * fSpeed) / fMaxSpeed);
}

void Vehicle::setMaxSpeed() {
    REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setMaxSpeed()");

    switch (fType) {
        case Car: {
            fMaxSpeed = carMaxSpeed;
            break;
        }
        case Bus: {
            fMaxSpeed = busMaxSpeed;
            break;
        }
        case FireEngine: {
            fMaxSpeed = fireEngineMaxSpeed;
            break;
        }
        case Ambulance: {
            fMaxSpeed = ambulanceMaxSpeed;
            break;
        }
        case PoliceCar: {
            fMaxSpeed = policeCarMaxSpeed;
            break;
        }
    }
}
