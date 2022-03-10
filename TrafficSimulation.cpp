#include "TrafficSimulation.h"
#include "parsers/ElementParser.h"

TrafficSimulation::TrafficSimulation() {
    TrafficSimulation::_initCheck = this;
    ENSURE(properlyInitialized(), "TrafficSimulation constructor did not end in an initialized state");
}

TrafficSimulation::~TrafficSimulation() {}

bool TrafficSimulation::properlyInitialized() const {
    return TrafficSimulation::_initCheck == this;
}

void TrafficSimulation::parseInputFile(const std::string &filename) {
    ENSURE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling parseInputFile()");
    ElementParser parser;
    try {
        parser.parseFile(filename);
    }
    catch (std::exception *e) {
        std::cerr << e->what() << std::endl;
    }

    TrafficSimulation::fStreets = parser.getStreets();
    TrafficSimulation::fTrafficLights = parser.getTrafficLights();
    TrafficSimulation::fVehicles = parser.getVehicles();
    TrafficSimulation::fVehicleGenerators = parser.getVehicleGenerators();
}