#include "Ambulance.h"
#include "../../Variables.h"
#include <cmath>

Ambulance::Ambulance(const std::string &street, double position) : Vehicle(street, position) {
    fMaxSpeed = ambulanceMaxSpeed;
}

Ambulance::~Ambulance() {}

double Ambulance::getLength() const {
    return ambulanceLength;
}

std::string Ambulance::getType() const {
    return "Ambulance";
}

char Ambulance::getAcronym() const {
    return 'Z';
}

void Ambulance::drive(Vehicle *vehicleInFront) {
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
}

void Ambulance::brake() {
    fMaxSpeed = gSlowFactor * ambulanceMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }
}

void Ambulance::stop() {
    fAcceleration = -((ambulanceMaxBrakeFactor * fSpeed) / fMaxSpeed);
}

void Ambulance::setMaxSpeed() {
    fMaxSpeed = ambulanceMaxSpeed;
}

bool Ambulance::hasPriority() const {
    return true;
}
