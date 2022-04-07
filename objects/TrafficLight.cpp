// ===========================================================
// Name         : TrafficLight.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `TrafficLight` class
// ===========================================================

#include "TrafficLight.h"
#include "../Variables.h"

TrafficLight::TrafficLight() {
    fIsgreen = true;
    fLastUpdateTime = 0;
    TrafficLight::_initCheck = this;
    ENSURE(properlyInitialized(), "TrafficLight constructor did not end in an initialized state");
}

TrafficLight::~TrafficLight() {}

bool TrafficLight::properlyInitialized() const {
    return TrafficLight::_initCheck == this;
}

void TrafficLight::setStreet(const std::string &s) {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setStreet()");
    TrafficLight::fStreet = s;
    ENSURE(this->getStreet() == s, "setStreet() postcondition");
}

void TrafficLight::setPosition(int p) {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setPosition()");
    TrafficLight::fPosition = p;
    ENSURE(this->getPosition() == p, "setPosition() postcondition");
}

void TrafficLight::setCycle(int c) {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setCycle()");
    TrafficLight::fCycle = c;
    ENSURE(this->getCycle() == c, "setCycle() postcondition");
}

void TrafficLight::setLight(bool s) {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setLight()");
    TrafficLight::fIsgreen = s;
    ENSURE(this->isGreen() == s, "setLight() postcondition");
}

void TrafficLight::setLastUpdateTime(double u) {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setLastUpdateTime()");
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
    if (fIsgreen) {
        fIsgreen = false;
    } else {
        fIsgreen = true;
    }
}