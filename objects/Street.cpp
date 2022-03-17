// ===========================================================
// Name         : Street.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Street` class
// ===========================================================

#include "Street.h"
#include "Vehicle.h"

Street::Street() {
    fVehicleGenerator = NULL;
    Street::_initCheck = this;
    ENSURE(properlyInitialized(), "Street constructor did not end in an initialized state");
}

Street::~Street() {}

bool Street::properlyInitialized() const {
    return Street::_initCheck == this;
}

void Street::setName(const std::string &n) {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling setName()");
    Street::fName = n;
    ENSURE(this->getName() == n, "setName() postcondition");
}

void Street::setLength(int l) {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling setLength()");
    Street::fLength = l;
    ENSURE(this->getLength() == l, "setLength() postcondition");
}

void Street::addTrafficLight(TrafficLight *t) {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling addTrafficLight()");
    fTrafficLights.push_back(t);
    ENSURE(!fTrafficLights.empty(), "addTrafficLight() postcondition");
}

void Street::addVehicle(Vehicle *v) {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling addVehicle()");
    fVehicles.push_back(v);
    ENSURE(!fVehicles.empty(), "addVehicle() postcondition");
}

void Street::setVehicleGenerator(VehicleGenerator *vg) {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling addVehicleGenerator()");
    fVehicleGenerator = vg;
    ENSURE(fVehicleGenerator == vg, "addVehicleGenerator() postcondition");
}

void Street::removeVehicle() {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling removeVehicle()");
    delete fVehicles[0];
    fVehicles.erase(fVehicles.begin());
}

const std::string &Street::getName() const {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling getName()");
    return Street::fName;
}

int Street::getLength() const {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling getLength()");
    return Street::fLength;
}

std::vector<TrafficLight *> Street::getTrafficLights() const {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling getTrafficLights()");
    return fTrafficLights;
}

std::vector<Vehicle*> Street::getVehicles() const {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling getVehicles()");
    return fVehicles;
}

bool Street::hasVehicleGenerator() const {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling hasVehicleGenerator()");
    return fVehicleGenerator != NULL;
}