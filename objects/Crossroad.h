// ===========================================================
// Name         : Crossroad.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Crossroad` class
// ===========================================================

#ifndef TRAFFICSIMULATION_CROSSROAD_H
#define TRAFFICSIMULATION_CROSSROAD_H

#include <map>

class Street;

class Crossroad {
    Crossroad* _initCheck;

    std::pair<Street*, unsigned int> fStreet1;
    std::pair<Street*, unsigned int> fStreet2;

public:
    Crossroad();

    virtual ~Crossroad();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "Crossroad wasn't initialized when calling getStreet1()")
     */
    const std::pair<Street *, unsigned int> &getStreet1() const;

    /*
     * REQUIRE(properlyInitialized(), "Crossroad wasn't initialized when calling getStreet2()")
     */
    const std::pair<Street *, unsigned int> &getStreet2() const;
};


#endif