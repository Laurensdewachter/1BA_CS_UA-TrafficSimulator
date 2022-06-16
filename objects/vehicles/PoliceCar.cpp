// ===========================================================
// Name         : PoliceCar.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `PoliceCar` subclass
// ===========================================================

#include "PoliceCar.h"
#include "../../Variables.h"
#include <cmath>

PoliceCar::PoliceCar(const std::string &street, double position) : Vehicle(street, position) {
    fMaxSpeed = policeCarMaxSpeed;
}

PoliceCar::~PoliceCar() {}

double PoliceCar::getLength() const {
    return policeCarLength;
}

std::string PoliceCar::getType() const {
    return "PoliceCar";
}

char PoliceCar::getAcronym() const {
    return 'P';
}

void PoliceCar::drive(Vehicle *vehicleInFront) {
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
}

void PoliceCar::brake() {
    fMaxSpeed = gSlowFactor * policeCarMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }
}

void PoliceCar::stop() {
    fAcceleration = -((policeCarMaxBrakeFactor * fSpeed) / fMaxSpeed);
}

void PoliceCar::setMaxSpeed() {
    fMaxSpeed = policeCarMaxSpeed;
}

bool PoliceCar::hasPriority() const {
    return true;
}
