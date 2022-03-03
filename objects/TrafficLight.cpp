#include "TrafficLight.h"

TrafficLight::TrafficLight() {}

TrafficLight::~TrafficLight() {}

void TrafficLight::setStreet(const std::string &s) {
    TrafficLight::street = s;
}

void TrafficLight::setPosition(int p) {
    TrafficLight::position = p;
}

void TrafficLight::setCycle(int c) {
    TrafficLight::cycle = c;
}

const std::string &TrafficLight::getStreet() const {
    return street;
}

int TrafficLight::getPosition() const {
    return position;
}

int TrafficLight::getCycle() const {
    return cycle;
}
