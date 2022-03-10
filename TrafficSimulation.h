#ifndef PSE_TRAFFICSIMULATION_H
#define PSE_TRAFFICSIMULATION_H

#include <iostream>
#include <vector>
#include "DesignByContract.h"

class Street;
class TrafficLight;
class Vehicle;
class VehicleGenerator;

class TrafficSimulation {
    std::vector<Street*> fStreets;
    std::vector<TrafficLight*> fTrafficLights;
    std::vector<Vehicle*> fVehicles;
    std::vector<VehicleGenerator*> fVehicleGenerators;
    TrafficSimulation* _initCheck;

public:
    /*
     * ENSURE(properlyInitialized(), "TrafficSimulation constructor did not end in an initialized state")
     */
    TrafficSimulation();

    virtual ~TrafficSimulation();

    bool properlyInitialized() const;

    /*
     * ENSURE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling parseInputFile()")
     */
    void parseInputFile(const std::string &filename);
};


#endif
