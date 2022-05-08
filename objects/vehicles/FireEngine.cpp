#include "FireEngine.h"
#include "../../Variables.h"
#include <cmath>

FireEngine::FireEngine(const std::string &street, double position) : Vehicle(street, position) {
    fMaxSpeed = fireEngineMaxSpeed;
}

FireEngine::~FireEngine() {}

double FireEngine::getLength() const {
    return fireEngineLength;
}

std::string FireEngine::getType() const {
    return "FireEngine";
}

char FireEngine::getAcronym() const {
    return 'F';
}

void FireEngine::drive(Vehicle *vehicleInFront) {
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
        delta = (fireEngineMinFollowDistance + std::max(0.0, (fSpeed + ((fSpeed * deltaV) / (2 * sqrt(fireEngineMaxAcceleration * fireEngineMaxBrakeFactor)))))) / deltaX;
    }
    fAcceleration = fireEngineMaxAcceleration * (1 - pow(fSpeed / fMaxSpeed, 4) - pow(delta, 2));
}

void FireEngine::brake() {
    fMaxSpeed = gSlowFactor * fireEngineMaxSpeed;
    if (fMaxSpeed == 0) {
        fMaxSpeed = 0.0000000000000000000001;
    }
}

void FireEngine::stop() {
    fAcceleration = -((fireEngineMaxBrakeFactor * fSpeed) / fMaxSpeed);
}

void FireEngine::setMaxSpeed() {
    fMaxSpeed = fireEngineMaxSpeed;
}

bool FireEngine::hasPriority() const {
    return true;
}
