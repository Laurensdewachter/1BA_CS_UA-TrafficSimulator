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

void TrafficSimulation::parseInputFile(const std::string &filename) {
    REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling parseInputFile()");

    ElementParser parser;
    try {
        parser.parseFile(filename);
    }
    catch (std::exception *e) {
        std::cerr << e->what() << std::endl;
    }

    std::vector<Street*> tempStreets = parser.getStreets();
    for (long unsigned int i = 0; i < tempStreets.size(); i++) {
        fStreets[tempStreets[i]->getName()] = tempStreets[i];
    }
    TrafficSimulation::fTrafficLights = parser.getTrafficLights();

    TrafficSimulation::fVehicles = parser.getVehicles();
    for (long unsigned int i = 0; i < fVehicles.size(); i++) {
        TrafficSimulation::fVehiclesByStreet[fVehicles[i]->getStreet()] = fVehicles[i];
    }

    TrafficSimulation::fVehicleGenerators = parser.getVehicleGenerators();
}

void TrafficSimulation::drive() {
    REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling drive()");

    if (fVehicles.empty()) {
        throw SimulationException("There are no vehicles in the simulation");
    }

    fVehicles[0]->drive();
    if (fVehicles[0]->getPosition() > fStreets[fVehicles[0]->getStreet()]->getLength()) {
        Vehicle* toBeDeleted = fVehicles[0];
        fVehicles.erase(fVehicles.begin());
        delete toBeDeleted;
    }
    if (fVehicles.size() > 1) {
        for (long unsigned int i = 1; i < fVehicles.size(); i++) {
            fVehicles[i]->drive(fVehicles[i - 1]);
        }
    }
}

void TrafficSimulation::sortVehicles() {
    std::vector<Vehicle*> newList;
    
}