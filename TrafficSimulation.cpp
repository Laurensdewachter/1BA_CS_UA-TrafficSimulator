// ===========================================================
// Name         : TrafficSimulation.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `TrafficSimulation` class
// ===========================================================

#include "TrafficSimulation.h"
#include "Variables.h"
#include "objects/Street.h"
#include "objects/TrafficLight.h"
#include "objects/Vehicle.h"
#include "objects/VehicleGenerator.h"

TrafficSimulation::TrafficSimulation() {
    TrafficSimulation::fTime = 0;
    TrafficSimulation::_initCheck = this;
    ENSURE(properlyInitialized(), "TrafficSimulation constructor did not end in an initialized state");
}

TrafficSimulation::~TrafficSimulation() {}

bool TrafficSimulation::properlyInitialized() const {
    return TrafficSimulation::_initCheck == this;
}

EParserSucces TrafficSimulation::parseInputFile(const std::string &filename, std::ostream &errStream) {
    REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling parseInputFile()");
    REQUIRE(errStream.good(), "The errorStream wasn't good");

    EParserSucces parseSucces = Success;

    ElementParser parser;
    parseSucces = parser.parseFile(filename, errStream);

    TrafficSimulation::fStreets = parser.getStreets();
    std::vector<TrafficLight*> trafficLights = parser.getTrafficLights();
    std::vector<Vehicle*> vehicles = parser.getVehicles();
    std::vector<VehicleGenerator*> vehicleGenerators = parser.getVehicleGenerators();

    for (long unsigned int i = 0; i < trafficLights.size(); i++) {
        TrafficLight* curTrafficLight = trafficLights[i];
        Street* curStreet = getStreet(curTrafficLight->getStreet());
        if (curStreet != NULL && curTrafficLight->getPosition() < curStreet->getLength()) {
            std::vector<TrafficLight*> trafficLightsOnStreet = curStreet->getTrafficLights();
            bool validTrafficLight = true;
            for (long unsigned int j = 0; j < trafficLightsOnStreet.size(); j++) {
                int position = trafficLightsOnStreet[j]->getPosition();
                if (abs(position - curTrafficLight->getPosition()) < gBrakeDistance) {
                    validTrafficLight = false;
                }
            }
            if (validTrafficLight) {
                curStreet->addTrafficLight(curTrafficLight);
            } else {
                errStream << "XML IMPORT ABORT: The simulation is not consistent." << std::endl;
                return ImportAborted;
            }
        } else {
            errStream << "XML IMPORT ABORT: The simulation is not consistent." << std::endl;
            return ImportAborted;
        }
    }

    for (long unsigned int i = 0; i < vehicles.size(); i++) {
        Vehicle* curVehicle = vehicles[i];
        Street* curStreet = getStreet(curVehicle->getStreet());
        if (curStreet != NULL && curVehicle->getPosition() < curStreet->getLength()) {
            curStreet->addVehicle(curVehicle);
        } else {
            errStream << "XML IMPORT ABORT: The simulation is not consistent" << std::endl;
            return ImportAborted;
        }
    }

    for (long unsigned int i = 0; i < vehicleGenerators.size(); i++) {
        VehicleGenerator* curVehicleGenerator = vehicleGenerators[i];
        Street* curStreet = getStreet(curVehicleGenerator->getStreet());
        if (curStreet != NULL && !curStreet->hasVehicleGenerator()) {
            curStreet->setVehicleGenerator(curVehicleGenerator);
        } else {
            errStream << "XML IMPORT ABORT: The simulation is not consistent" << std::endl;
            return ImportAborted;
        }
    }

    for (unsigned int i = 0; i < fStreets.size(); i++) {
        fStreets[i]->sortVehicles();
    }

    return parseSucces;
}

void TrafficSimulation::writeOn(std::ostream &onstream) const {
    REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling writeOn()");

    onstream << "Tijd: " << fTime << std::endl;

    int voertuigCounter = 1;
    for (unsigned int i = 0; i < fStreets.size(); i++) {
        std::vector<Vehicle*> vehicles = fStreets[i]->getVehicles();
        for (unsigned int j = 0; j < vehicles.size(); j++) {
            Vehicle* curVehicle = vehicles[j];
            onstream << "Voertuig " << voertuigCounter << std::endl;
            onstream << "-> baan: " << curVehicle->getStreet() << std::endl;
            onstream << "-> positie: " << curVehicle->getPosition() << std::endl;
            onstream << "-> snelheid: " << curVehicle->getSpeed() << std::endl << std::endl;
            voertuigCounter++;
        }
    }
}

void TrafficSimulation::visualize(std::ostream &onstream) const {
    REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling visualize()");

    for (unsigned int i = 0; i < fStreets.size(); i++) {
        std::vector<Vehicle*> vehicles = fStreets[i]->getVehicles();
        for (unsigned int j = 0; j < vehicles.size(); j++) {
            onstream << "{";
            onstream << "\"time\":" << fTime << ",";
            onstream << "\"roads\":[";
            onstream << "{";
            Vehicle* curVehicle = vehicles[j];
            onstream << "\"name\":\"" << curVehicle->getStreet()<< "\",";
            onstream << "\"length\":" << fStreets[i]->getLength() << ",";
            onstream << "\"cars\":";
            onstream << "[";
            if(!fStreets[i]->getVehicles().empty()){
                for(unsigned int l = 0; l <vehicles.size();l++){
                    Vehicle* curVehicle2 = vehicles[l];
                    onstream << "{";
                    onstream << "\"x\":" << curVehicle2->getPosition();
                    onstream << "}";
                    if(l<vehicles.size()-1){
                        onstream << ",";
                    }
                }
            }
            onstream << "],";
            if(!fStreets[i]->getTrafficLights().empty()){
                onstream << "\"lights\":";
                onstream << "[";
                for(unsigned int t = 0;t<fStreets[i]->getTrafficLights().size();t++){
                    TrafficLight * T = fStreets[i]->getTrafficLights()[t];
                    onstream << "{";
                    onstream << "\"x\":" << T->getPosition() << ",";
                    onstream << "\"green\":" << int(T->getIsgreen())<< ",";
                    onstream << "\"xs\":" << gBrakeDistance << ",";
                    onstream << "\"xs0\":" << gStopDistance;
                    onstream << "}";
                    if(t<fStreets[i]->getTrafficLights().size()-1){
                        onstream << ",";
                    }
                }
            }
            onstream << "]" <<"}" << "]" << "}" << std::endl;
        }
    }
}

void TrafficSimulation::simulate() {
    REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling simulate()");
    for (long unsigned int i = 0; i < fStreets.size(); i++) {
        fStreets[i]->driveVehicles();
        fStreets[i]->simTrafficLights(fTime);
    }
    fTime += gSimulationTime;
}

void TrafficSimulation::clearSimulation() {
    REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling clearSimulation()");

    fTime = 0;
    for (unsigned int i = 0; i < fStreets.size(); i++) {
        delete fStreets[i];
    }
}

Street *TrafficSimulation::getStreet(const std::string &name) const {
    REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling getStreet()");
    for (long unsigned int i = 0; i < fStreets.size(); i++) {
        if (fStreets[i]->getName() == name) {
            return fStreets[i];
        }
    }
    return NULL;
}

double TrafficSimulation::getFTime() const {
    REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling getFtime()");
    return TrafficSimulation::fTime;
}
