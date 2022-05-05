// ===========================================================
// Name         : BusStop.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `BusStop` class
// ===========================================================

#ifndef TRAFFICSIMULATION_BUSSTOP_H
#define TRAFFICSIMULATION_BUSSTOP_H

#include <iostream>
#include "../DesignByContract.h"

class BusStop {
    BusStop* _initCheck;

    std::string fStreet;
    int fPosition;
    int fWaitTime;

public:
    /*
     * ENSURE(properlyInitialized(), "BusStop constructor did not end in an initialized state")
     */
    BusStop(const std::string &street, int position, int waitTime);

    virtual ~BusStop();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "BusStop wasn't initialized when calling getStreet()")
     */
    const std::string &getStreet() const;

    /*
     * REQUIRE(this->properlyInitialized(), "BusStop wasn't initialized when calling getPosition")
     */
    int getPosition() const;

    /*
     * REQUIRE(properlyInitialized(), "BusStop wasn't initialized when calling getWaitTime()")
     */
    int getWaitTime() const;
};


#endif