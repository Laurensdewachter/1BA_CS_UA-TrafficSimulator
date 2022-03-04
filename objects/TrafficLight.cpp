// ===========================================================
// Name         : TrafficLight.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `TrafficLight` class
// ===========================================================

#include "TrafficLight.h"

TrafficLight::TrafficLight() {
    TrafficLight::_initCheck = this;
    ENSURE(properlyInitialized(), "TrafficLight constructor dit not end in a initialized state.");
}

TrafficLight::~TrafficLight() {}

bool TrafficLight::properlyInitialized() const {
    return TrafficLight::_initCheck == this;
}

void TrafficLight::setStreet(const std::string &s) {
    REQUIRE(TrafficLight::properlyInitialized(), "TrafficLight wasn't initialized when calling `setStreet()`.");
    TrafficLight::street = s;
    ENSURE(TrafficLight::street == s, "`setStreet()` postcondition failed.");
}

void TrafficLight::setPosition(int p) {
    REQUIRE(TrafficLight::properlyInitialized(), "TrafficLight wasn't initialized when calling `setPosition()`.");
    TrafficLight::position = p;
    ENSURE(TrafficLight::position == p, "`setPosition()` postcondition failed.");
}

void TrafficLight::setCycle(int c) {
    REQUIRE(TrafficLight::properlyInitialized(), "TrafficLight wasn't initialized when calling `setCycle()`.");
    TrafficLight::cycle = c;
    ENSURE(TrafficLight::position == c, "`setCycle()` postcondition failed.");
}

const std::string &TrafficLight::getStreet() const {
    REQUIRE(TrafficLight::properlyInitialized(), "TrafficLight wasn't initialized when calling `getStreet()`.");
    return street;
}

int TrafficLight::getPosition() const {
    REQUIRE(TrafficLight::properlyInitialized(), "TrafficLight wasn't initialized when calling `getPosition()`.");
    return position;
}

int TrafficLight::getCycle() const {
    REQUIRE(TrafficLight::properlyInitialized(), "TrafficLight wasn't initialized when calling `getCycle()`.");
    return cycle;
}
