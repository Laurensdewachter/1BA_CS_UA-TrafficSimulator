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

    TrafficSimulation::fStreets = parser.getStreets();

    TrafficSimulation::fTrafficLights = parser.getTrafficLights();

    std::vector<Vehicle*> vehicles = parser.getVehicles();

    TrafficSimulation::fVehicleGenerators = parser.getVehicleGenerators();

    for (long unsigned int i = 0; i < vehicles.size(); i++) {
        try {
            Street *s = getStreet(vehicles[i]->getStreet());
            s->addVehicle(vehicles[i]);
        }
        catch (std::exception &e) {
            throw SimulationException("There is a vehicle that was initialized on a non-existent street");
        }
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
    throw SimulationException("Street not found");
}