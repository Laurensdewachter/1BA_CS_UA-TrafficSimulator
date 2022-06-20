// ===========================================================
// Name         : TrafficSimulation.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `TrafficSimulation` class
// ===========================================================

#ifndef PSE_TRAFFICSIMULATION_H
#define PSE_TRAFFICSIMULATION_H

#include <vector>
#include <fstream>
#include <map>
#include "parsers/ElementParser.h"

class Street;

class TrafficSimulation {
    TrafficSimulation* _initCheck;

    std::vector<Street*> fStreets;
    double fTime;

public:
    /*
     * ENSURE(properlyInitialized(), "TrafficSimulation constructor did not end in an initialized state")
     */
    TrafficSimulation();

    /*
     * ENSURE(fStreets.empty(), "TrafficSimulation destructor did not end in an empty state")
     */
    virtual ~TrafficSimulation();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling parseInputFile()")
     * REQUIRE(errStream.good(), "The errorStream wasn't good when calling parseInputFile()")
     *
     * ENSURE(errStream.good(), "The errorStream wasn't good at the end of parseInputFile()")
     * ENSURE(parseSucces == Success || parseSucces == ImportAborted, "The parser did not return a proper success or aborted value")
     */
    EParserSuccess parseInputFile(const std::string &filename, std::ostream &errStream = std::cerr);

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling writeOn()")
     * REQUIRE(onstream.good(), "The outputStream wasn't good when calling writeOn()")
     *
     * ENSURE(onstream.good(), "The outputStream wasn't good at the end of writeOn()")
     */
    void writeOn(std::ostream &onstream = std::cout) const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling visualize()")
     * REQUIRE(onstream.good(), "The outputStream wasn't good when calling visualize()")
     *
     * ENSURE(onstream.good(), "The outputStream wasn't good at the end of visualize()")
     */
    void visualize(std::ostream &onstream = std::cout) const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling graph()")
     * REQUIRE(onstream.good(), "The outputStream wasn't good when calling graph()")
     *
     * ENSURE(onstream.good(), "The outputStream wasn't good at the end of graph()")
     */
    void graph(std::ostream &onstream = std::cout) const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling simulate()")
     *
     * ENSURE(fStreets.size() == beginSize, "The number of streets changed when calling simulate()")
     */
    void simulate();

    /*
    * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling simCrossroads()")
    */
    void simCrossroads();

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling clearSimulation()")
     *
     * ENSURE(fStreets.empty(), "The streets vector wasn't empty at the end of clearSimulation()")
     */
    void clearSimulation();

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling getStreets()")
     */
    const std::vector<Street *> &getStreets() const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficSimulation wasn't initialized when calling getTime()")
     */
    double getTime() const;

    bool contains(int pos_veh,std::map<Street*,int> kruispunten);

    int findPosition(Street * street, std::map<Street*,int> kruispunten);

    void createImage(unsigned int i);

private:
    Street* getStreetFromString(const std::string &name) const;
};


#endif