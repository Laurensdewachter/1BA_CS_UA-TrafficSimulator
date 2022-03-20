// ===========================================================
// Name         : TrafficLight.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `TrafficLight` class
// ===========================================================

#include "TrafficLight.h"

TrafficLight::TrafficLight() {
    TrafficLight::_initCheck = this;
    ENSURE(properlyInitialized(), "TrafficLight constructor did not end in an initialized state");
    fIsgreen = true;
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
    ENSURE(this->getIsgreen() == s, "setLight() postcondition");
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

bool TrafficLight::getIsgreen() const {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling getIsgreen()");
    return TrafficLight::fIsgreen;
}