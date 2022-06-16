// ===========================================================
// Name         : Bus.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Bus` subclass
// ===========================================================

#include "Bus.h"
#include "../../Variables.h"
#include <cmath>

Bus::Bus(const std::string &street, double position) : Vehicle(street, position) {
    fMaxSpeed = busMaxSpeed;
}

Bus::~Bus() {}

double Bus::getLength() const {
    return busLength;
}

double Bus::getWaitTime() const {
    return fWaitTime;
}

void Bus::addWaitTime(double time) {
    fWaitTime += time;
}

void Bus::clearWaitTime() {
    fWaitTime = 0;
}

std::string Bus::getType() const {
    return "Bus";
}

char Bus::getAcronym() const {
    return 'B';
}

void Bus::drive(Vehicle *vehicleInFront) {
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
        delta = (busMinFollowDistance + std::max(0.0, (fSpeed + ((fSpeed * deltaV) / (2 * sqrt(busMaxAcceleration * busMaxBrakeFactor)))))) / deltaX;
    }
    fAcceleration = busMaxAcceleration * (1 - pow(fSpeed / fMaxSpeed, 4) - pow(delta, 2));
}

void Bus::brake() {
    fMaxSpeed = gSlowFactor * busMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }
}

void Bus::stop() {
    fAcceleration = -((busMaxBrakeFactor * fSpeed) / fMaxSpeed);
}

void Bus::setMaxSpeed() {
    fMaxSpeed = busMaxSpeed;
}

bool Bus::hasPriority() const {
    return false;
}
