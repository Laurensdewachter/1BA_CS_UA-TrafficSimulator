// ===========================================================
// Name         : TrafficLight.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `TrafficLight` class
// ===========================================================

#include "TrafficLight.h"

TrafficLight::TrafficLight() {
    TrafficLight::_initCheck = this;
    ENSURE(properlyInitialized(), "TrafficLight constructor dit not end in an initialized state");
}

TrafficLight::~TrafficLight() {}

bool TrafficLight::properlyInitialized() const {
    return TrafficLight::_initCheck == this;
}

void TrafficLight::setStreet(const std::string &s) {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setStreet()");
    TrafficLight::street = s;
    ENSURE(this->getStreet() == s, "setStreet() postcondition");
}

void TrafficLight::setPosition(int p) {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setPosition()");
    TrafficLight::position = p;
    ENSURE(this->getPosition() == p, "setPosition() postcondition");
}

void TrafficLight::setCycle(int c) {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setCycle()");
    TrafficLight::cycle = c;
    ENSURE(this->getCycle() == c, "setCycle() postcondition");
}

const std::string &TrafficLight::getStreet() const {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling getStreet()");
    return TrafficLight::street;
}

int TrafficLight::getPosition() const {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling getPosition()");
    return TrafficLight::position;
}

int TrafficLight::getCycle() const {
    REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling getCycle()");
    return TrafficLight::cycle;
}
