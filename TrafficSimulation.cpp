// ===========================================================
// Name         : TrafficSimulation.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `TrafficSimulation` class
// ===========================================================

#include "TrafficSimulation.h"
#include "SimulationException.h"
#include "parsers/ElementParser.h"
#include "objects/Vehicle.h"
#include "objects/Street.h"

TrafficSimulation::TrafficSimulation() {
    TrafficSimulation::_initCheck = this;
    ENSURE(properlyInitialized(), "TrafficSimulation constructor did not end in an initialized state");
}

TrafficSimulation::~TrafficSimulation() {}

bool TrafficSimulation::properlyInitialized() const {
    return TrafficSimulation::_initCheck == this;
}

void TrafficSimulation::parseInputFile(const std::string &filename, std::ostream &errStream) {
    REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling parseInputFile()");
    REQUIRE(errStream.good(), "The errorStream wasn't good");

    ElementParser parser;
    parser.parseFile(filename, errStream);

    TrafficSimulation::fStreets = parser.getStreets();
    TrafficSimulation::fTrafficLights = parser.getTrafficLights();
    std::vector<Vehicle*> vehicles = parser.getVehicles();
    TrafficSimulation::fVehicleGenerators = parser.getVehicleGenerators();
    for (long unsigned int i = 0; i < vehicles.size(); i++) {
        Street *s = getStreet(vehicles[i]->getStreet());
        if (s == NULL) {
            errStream << "There was a vehicle that was generated on a non-existing street" << std::endl;
            continue;
        }
        s->addVehicle(vehicles[i]);
    }
}

void TrafficSimulation::drive() {
    REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling drive()");

    for (long unsigned int i = 0; i < fStreets.size(); i++) {
        Street* curStreet = fStreets[i];
        std::vector<Vehicle*> curVehicles = curStreet->getVehicles();

        if (curVehicles.empty()) {
            continue;
        }

        curVehicles[0]->drive();
        if (curVehicles[0]->getPosition() > curStreet->getLength()) {
            curStreet->removeVehicle();
        }
        if (curVehicles.size() > 1) {
            for (long unsigned int j = 1; j < curVehicles.size(); j++) {
                curVehicles[j]->drive(curVehicles[j-1]);
            }
        }
    }
}

Street *TrafficSimulation::getStreet(const std::string &name) const {
    for (long unsigned int i = 0; i < fStreets.size(); i++) {
        if (fStreets[i]->getName() == name) {
            return fStreets[i];
        }
    }
    return NULL;
}