// ===========================================================
// Name         : Vehicle.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is contains the `Vehicle` class
// ===========================================================

#ifndef PSE_VEHICLE_H
#define PSE_VEHICLE_H

#include <iostream>

enum EVehicleType {
    car,
    bus,
    fireEngine,
    ambulance,
    policeCar
};

class Vehicle {
protected:
    Vehicle* _initCheck;

    std::string fStreet;
    double fPosition;

    double fLength;
    double fSpeed;
    double fAcceleration;
    double fMaxSpeed;

public:
    /*
     * ENSURE(properlyInitialized(), "Vehicle constructor did not end in an initialized state")
     */
    Vehicle();

    Vehicle(const std::string &street, double position, double length, double maxSpeed);

    virtual ~Vehicle();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setStreet()")
     * ENSURE(Vehicle::fStreet == s, "setStreet() postcondition")
     */
    void setStreet(const std::string &s);

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setPosition()")
     * ENSURE(Vehicle::fPosition == p, "setPosition() postcondition")
     */
    void setPosition(int p);

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

    virtual void drive(Vehicle* vehicleInFront = NULL) = 0;

    virtual void brake() = 0;

    virtual void stop() = 0;

    virtual void setMaxSpeed() = 0;
};


#endif