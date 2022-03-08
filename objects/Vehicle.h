// ===========================================================
// Name         : Vehicle.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Vehicle` class
// ===========================================================

#ifndef PSE_VEHICLE_H
#define PSE_VEHICLE_H

#include <iostream>
#include "../DesignByContract.h"

class Vehicle {
    Vehicle* _initCheck;
    std::string street;
    int position;

public:
    /*
     * ENSURE(properlyInitialized(), "Vehicle constructor did not end in an initialized state")
     */
    Vehicle();

    virtual ~Vehicle();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setStreet()")
     * ENSURE(Vehicle::street == s, "setStreet() postcondition")
     */
    void setStreet(const std::string &s);

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setPosition()")
     * ENSURE(Vehicle::position == p, "setPosition() postcondition")
     */
    void setPosition(int p);

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getStreet()")
     */
    const std::string &getStreet() const;

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getPosition()")
     */
    int getPosition() const;
};


#endif
