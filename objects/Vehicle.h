// ===========================================================
// Name         : Vehicle.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is contains the `Vehicle` class
// ===========================================================

#ifndef PSE_VEHICLE_H
#define PSE_VEHICLE_H

#include <iostream>
#include <map>

enum EVehicleType {
    car,
    bus,
    fireEngine,
    ambulance,
    policeCar
};

const double carLength = 4.0;
const double carMaxSpeed = 16.6;
const double carMaxAcceleration = 1.44;
const double carMaxBrakeFactor = 4.61;
const double carMinFollowDistance = 4.0;

const double busLength = 12.0;
const double busMaxSpeed = 11.4;
const double busMaxAcceleration = 1.22;
const double busMaxBrakeFactor = 4.29;
const double busMinFollowDistance = 12.0;

const double fireEngineLength = 10.0;
const double fireEngineMaxSpeed = 14.6;
const double fireEngineMaxAcceleration = 1.33;
const double fireEngineMaxBrakeFactor = 4.56;
const double fireEngineMinFollowDistance = 10.0;

const double ambulanceLength = 8.0;
const double ambulanceMaxSpeed = 15.5;
const double ambulanceMaxAcceleration = 1.44;
const double ambulanceMaxBrakeFactor = 4.47;
const double ambulanceMinFollowDistance = 8.0;

const double policeCarLength = 6.0;
const double policeCarMaxSpeed = 17.2;
const double policeCarMaxAcceleration = 1.55;
const double policeCarMaxBrakeFactor = 4.92;
const double policeCarMinFollowDistance = 6.0;

class Vehicle {
protected:
    Vehicle* _initCheck;

    std::string fStreet;
    double fPosition;
    EVehicleType fType;

    double fSpeed;
    double fAcceleration;
    double fMaxSpeed;

public:

    /*
     * ENSURE(properlyInitialized(), "Vehicle constructor did not end in an initialized state")
     */
    Vehicle(const std::string &street, double position, EVehicleType type);

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
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling getType()")
     */
    EVehicleType getType() const;

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling drive()")
     * ENSURE(fPosition >= startPosition, "drive() postcondition")
     */
    void drive(Vehicle* vehicleInFront);

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling brake()")
     * ENSURE(fMaxSpeed <= maxSpeed, "brake() postcondition")
     * ENSURE(fMaxSpeed <= startMaxSpeed, "brake() postcondition")
     */
    void brake();

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling stop()")
     */
    void stop();

    /*
     * REQUIRE(properlyInitialized(), "Vehicle wasn't initialized when calling setMaxSpeed()")
     */
    void setMaxSpeed();
};


#endif