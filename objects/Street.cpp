// ===========================================================
// Name         : Street.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
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

    unsigned int vehiclesSize = fVehicles.size();
    fVehicles.push_back(v);

    ENSURE(fVehicles.size() == vehiclesSize+1, "addVehicle() postcondition");
}

void Street::setVehicleGenerator(VehicleGenerator *vg) {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling addVehicleGenerator()");

    fVehicleGenerator = vg;

    ENSURE(fVehicleGenerator == vg, "addVehicleGenerator() postcondition");
}

void Street::removeVehicle() {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling removeVehicle()");

    unsigned int vehiclesSize = fVehicles.size();
    delete fVehicles[0];
    fVehicles.erase(fVehicles.begin());

    ENSURE(fVehicles.size() == vehiclesSize-1, "removeVehicle() postcondition");
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

    // TODO: ask about ENSURE here
}

void Street::simTrafficLights(double &time) {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling simTrafficLights()");

    if (fTrafficLights.empty()) {
        return;
    }

    for (unsigned int i = 0; i < fTrafficLights.size(); i++) {
        // Change traffic light if necessary
        TrafficLight *curTrafficLight = fTrafficLights[i];

        if (time >= curTrafficLight->getLastUpdateTime()) {
            curTrafficLight->changeLight();
            curTrafficLight->setLastUpdateTime(curTrafficLight->getLastUpdateTime() + curTrafficLight->getCycle());
        }

        // Get vehicle closest to the traffic light
        if (fVehicles.empty()) {
            return;
        }
        Vehicle *closestVehicle = NULL;
        for (unsigned int v = 0; v < fVehicles.size(); v++) {
            if (fVehicles[v]->getPosition() < curTrafficLight->getPosition()) {
                closestVehicle = fVehicles[v];
            }

            // Go to next traffic light if there is no vehicle before the traffic light
            if (closestVehicle == NULL) {
                continue;
            }

            // Traffic light is green
            if (curTrafficLight->isGreen()) {
                closestVehicle->setMaxSpeed(gMaxSpeed);
            }

            // Traffic light is red
            else {
                double distance = curTrafficLight->getPosition() - closestVehicle->getPosition();
                if (distance > 0 && distance < gStopDistance) {
                    closestVehicle->stop();
                }
                else if (distance > 0 && distance < gBrakeDistance) {
                    closestVehicle->brake();
                }
            }
        }
    }

    // TODO: ask about ENSURE here
}

void Street::simGenerator(double &time) {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling simGenerator()");

    if (fVehicleGenerator == NULL) {
        return;
    }
    if (fVehicleGenerator->getTimeSinceLastSpawn() < time && (fVehicles.empty() || fVehicles.back()->getPosition() > 2*gLength)) {
        Vehicle* newVehicle = new Vehicle();
        newVehicle->setStreet(fName);
        newVehicle->setPosition(0);
        fVehicles.push_back(newVehicle);

        fVehicleGenerator->setTimeSinceLastSpawn(fVehicleGenerator->getTimeSinceLastSpawn() + fVehicleGenerator->getFrequency());
    }
}

void Street::sortVehicles() {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling sortVehicles()");

    if (fVehicles.empty()) {
        return;
    }

    std::vector<Vehicle *> newVehicles;
    newVehicles.push_back(fVehicles[0]);

    for (unsigned int i = 1; i < fVehicles.size(); i++) {
        for (unsigned int j = 0; j < newVehicles.size(); j++) {
            if (fVehicles[i]->getPosition() > newVehicles[j]->getPosition()) {
                newVehicles.insert(newVehicles.begin() + j, fVehicles[i]);
                break;
            } else if (j == newVehicles.size() - 1) {
                newVehicles.push_back(fVehicles[i]);
                break;
            }
        }
    }
    fVehicles = newVehicles;

    ENSURE(!fVehicles.empty(), "sortVehicles() postcondition");
}