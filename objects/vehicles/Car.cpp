#include "Car.h"
#include "../../Variables.h"
#include <cmath>

Car::Car(const std::string &street, double position) : Vehicle(street, position) {
    fMaxSpeed = carMaxSpeed;
}

Car::~Car() {}

double Car::getLength() const {
    return carLength;
}

std::string Car::getType() const {
    return  "Car";
}

char Car::getAcronym() const {
    return 'A';
}

void Car::drive(Vehicle *vehicleInFront) {
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
}

void Car::brake() {
    fMaxSpeed = gSlowFactor * carMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }
}

void Car::stop() {
    fAcceleration = -((carMaxBrakeFactor * fSpeed) / fMaxSpeed);
}

void Car::setMaxSpeed() {
    fMaxSpeed = carMaxSpeed;
}

bool Car::hasPriority() const {
    return false;
}
