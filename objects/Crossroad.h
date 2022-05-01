//
// Created by sunaj on 28/04/22.
//

#ifndef TRAFFICSIMULATION_CROSSROAD_H
#define TRAFFICSIMULATION_CROSSROAD_H

#include <iostream>
#include <vector>

class Street;

class Crossroad {
    Crossroad* _initCheck;

    std::string fStreet;
    double fPosition;

public:

    /*
    * ENSURE(properlyInitialized(), "Crossroad constructor did not end in an initialized state")
    */
    Crossroad(const std::string &street, double position);

    virtual ~Crossroad();

    bool properlyInitialized() const;

/*
     * REQUIRE(properlyInitialized(), "Crossroad wasn't initialized when calling getStreet()")
     */
    const std::string &getStreet() const;

    /*
     * REQUIRE(properlyInitialized(), "Crossroad wasn't initialized when calling getPosition()")
     */
    double getPosition() const;

};


#endif //TRAFFICSIMULATION_CROSSROAD_H
