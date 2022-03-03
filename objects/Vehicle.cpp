#include "Vehicle.h"

Vehicle::Vehicle() {}

Vehicle::~Vehicle() {}

void Vehicle::setStreet(const std::string &s) {
    Vehicle::street = s;
}

void Vehicle::setPosition(int p) {
    Vehicle::position = p;
}

const std::string &Vehicle::getStreet() const {
    return street;
}

int Vehicle::getPosition() const {
    return position;
}
