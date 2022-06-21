// ===========================================================
// Name         : TrafficLight.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `TrafficLight` class
// ===========================================================

#include "TrafficLight.h"
#include "../DesignByContract.h"
#include "../Variables.h"

TrafficLight::TrafficLight(const std::string &street, int position, int cycle) : fStreet(street), fPosition(position), fCycle(cycle) {
    TrafficLight::fIsgreen = true;
    TrafficLight::fLastUpdateTime = 0;
    TrafficLight::_initCheck = this;

    ENSURE(properlyInitialized(), "TrafficLight constructor did not end in an initialized state");
}

TrafficLight::~TrafficLight() {}

bool TrafficLight::properlyInitialized() const {
    return TrafficLight::_initCheck == this;
}

void TrafficLight::setLastUpdateTime(double u) {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setLastUpdateTime()");
    REQUIRE(u >= 0, "LastUpdateTime must be greater than 0");

    TrafficLight::fLastUpdateTime = u;

    ENSURE(this->getLastUpdateTime() == u, "setLastUpdateTime() postcondition");
}

const std::string &TrafficLight::getStreet() const {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling getStreet()");

    return TrafficLight::fStreet;
}

int TrafficLight::getPosition() const {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling getPosition()");

    return TrafficLight::fPosition;
}

int TrafficLight::getCycle() const {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling getCycle()");

    return TrafficLight::fCycle;
}

bool TrafficLight::isGreen() const {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling isGreen()");

    return TrafficLight::fIsgreen;
}

double TrafficLight::getLastUpdateTime() const {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling getLastUpdateTime()");

    return TrafficLight::fLastUpdateTime;
}

void TrafficLight::changeLight() {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling changeLight()");

    fIsgreen = !fIsgreen;
}
