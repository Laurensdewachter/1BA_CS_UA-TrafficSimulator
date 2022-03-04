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
     * ENSURE(properlyInitialized(), "Vehicle constructor dit not end in a initialized state.")
     */
    Vehicle();

    virtual ~Vehicle();

    bool properlyInitialized() const;

    /*
     * REQUIRE(Vehicle::properlyInitialized(), "Vehicle wasn't initialized when calling `setStreet()`.")
     * ENSURE(Vehicle::street == s, "`setStreet()` postcondition failed.")
     */
    void setStreet(const std::string &street);

    /*
     * REQUIRE(Vehicle::properlyInitialized(), "Vehicle wasn't initialized when calling `setPosition()`.")
     * ENSURE(Vehicle::position == p, "`setPosition()` postcondition failed.")
     */
    void setPosition(int position);

    /*
     * REQUIRE(Vehicle::properlyInitialized(), "Vehicle wasn't initialized when calling `getStreet()`.")
     */
    const std::string &getStreet() const;

    /*
     * REQUIRE(Vehicle::properlyInitialized(), "Vehicle wasn't initialized when calling `getPosition()`.")
     */
    int getPosition() const;
};


#endif
