// ===========================================================
// Name         : TrafficSimulation.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `TrafficSimulation` class
// ===========================================================

#ifndef PSE_TRAFFICSIMULATION_H
#define PSE_TRAFFICSIMULATION_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "DesignByContract.h"
#include "parsers/ElementParser.h"

class Street;

class TrafficSimulation {
    std::vector<Street*> fStreets;
    TrafficSimulation* _initCheck;

public:
    /*
     * ENSURE(properlyInitialized(), "TrafficSimulation constructor did not end in an initialized state")
     */
    TrafficSimulation();

    virtual ~TrafficSimulation();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling parseInputFile()")
     */
    EParserSucces parseInputFile(const std::string &filename, std::ostream &errStream);

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling drive()")
     * REQUIRE(!fVehicles.empty(), "There were no vehicles in TrafficSimulation when calling drive()")
     */
    void drive();

private:
    Street* getStreet(const std::string &name) const;
};


#endif