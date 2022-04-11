// ===========================================================
// Name         : Vehicle.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is contains the `Vehicle` class
// ===========================================================

#ifndef PSE_VEHICLE_H
#define PSE_VEHICLE_H

#include <iostream>

class Vehicle {
protected:
    Vehicle* _initCheck;

    std::string fStreet;
    double fPosition;

    bool fHasPriority;

    double fLength;
    double fSpeed;
    double fAcceleration;
    double fMaxSpeed;

public:
    /*
     * ENSURE(properlyInitialized(), "Vehicle constructor did not end in an initialized state")
     */
    Vehicle();

    Vehicle(const std::string &street, double position, double length, double maxSpeed, bool hasPriority);

    virtual ~Vehicle();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getStreet()")
     */
    const std::string &getStreet() const;

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getPosition()")
     */
    double getPosition() const;

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getPosition()")
     */
    double getSpeed() const;

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getLength()")
     */
    double getLength() const;

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling hasPriority()")
     */
    bool hasPriority() const;

    virtual void drive(Vehicle* vehicleInFront) = 0;

    virtual void brake() = 0;

    virtual void stop() = 0;

    virtual void setMaxSpeed() = 0;
};


#endif