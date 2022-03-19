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
    double fTime;
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
    EParserSucces parseInputFile(const std::string &filename, std::ostream &errStream = std::cerr);

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling writeOn()")
     */
    void writeOn(std::ostream &onstream = std::cout) const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling simulate()")
     */
    void simulate();

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling clearSimulation()")
     */
    void clearSimulation();

private:
    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling getStreet()")
     */
    Street* getStreet(const std::string &name) const;
};


#endif