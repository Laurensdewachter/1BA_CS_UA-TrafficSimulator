// ===========================================================
// Name         : Street.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Street` class
// ===========================================================

#include "Street.h"
#include "TrafficLight.h"
#include "Vehicle.h"
#include "VehicleGenerator.h"

Street::Street() {
    fVehicleGenerator = NULL;
    Street::_initCheck = this;
    ENSURE(properlyInitialized(), "Street constructor did not end in an initialized state");
}

Street::~Street() {
    for (unsigned int i = 0; i < fTrafficLights.size(); i++) {
        delete fTrafficLights[i];
    }
    for (unsigned int i = 0; i < fVehicles.size(); i++) {
        delete fVehicles[i];
    }
    delete fVehicleGenerator;
}

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

void Street::driveVehicles() {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling driveVehicles()");

    if (fVehicles.empty()) {
        return;
    }
    for (unsigned int i = 0; i < fVehicles.size(); i++) {
        if (i == 0) {
            fVehicles[i]->drive();
            if (fVehicles[i]->getPosition() > fLength) {
                this->removeVehicle();
            }
            continue;
        }
        fVehicles[i]->drive(fVehicles[i-1]);
    }
}

void Street::simTrafficLights(double &fTime) {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling simTrafficLights()");

    if(fTrafficLights.empty()){
        return;
    }

    // change light when MOD is 0
    std::cout << "Simulation: " << fTime << std::endl;
    for(unsigned int i = 0; i < fTrafficLights.size(); i++){
        std::cout << "Trafficlight pos: " << fTrafficLights[i]->getPosition() << " and has cycle: " << fTrafficLights[i]->getCycle();
        if(fTime >= fTrafficLights[i]->getUpdatedlight()){
            std::cout << " | From " << fTrafficLights[i]->getIsgreen() << " to ";
            if(fTrafficLights[i]->getIsgreen()){
                fTrafficLights[i]->setLight(false);
            }else{
                fTrafficLights[i]->setLight(true);
            }
            fTrafficLights[i]->setUpdatedlight(fTrafficLights[i]->getUpdatedlight() + fTrafficLights[i]->getCycle());                  // set next light at getCycle() + fTime
            std::cout << fTrafficLights[i]->getIsgreen() << std::endl;
        }

        if(fTrafficLights[i]->getIsgreen()) {
            fVehicles[0]->setMaxSpeed(gMaxSpeed);
        }else{
            double distance =  fTrafficLights[i]->getPosition() - fVehicles[0]->getPosition();
            if(distance <= gBrakeDistance && distance >= 0){                    // pas vertraagfactor toe op deze auto
                fVehicles[0]->setMaxSpeed(gSlowDownFactor*gMaxSpeed);
            }else if(distance <= gStopDistance && distance >= gStopDistance/2){ // vehicle is in the first half (15-7.5) of the stopdistance => then stop
                fVehicles[0]->setMaxSpeed(0);
            }
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Street::sortVehicles() {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling sortVehicles()");

    if (fVehicles.empty()) {
        return;
    }

    std::vector<Vehicle*> newVehicles;
    newVehicles.push_back(fVehicles[0]);

    for (unsigned int i = 1; i < fVehicles.size(); i++) {
        for (unsigned int j = 0; j < newVehicles.size(); j++) {
            if (fVehicles[i]->getPosition() > newVehicles[j]->getPosition()) {
                newVehicles.insert(newVehicles.begin() + j, fVehicles[i]);
                break;
            }
        }
    }

    fVehicles = newVehicles;
}