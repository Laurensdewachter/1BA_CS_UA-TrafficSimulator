// ===========================================================
// Name         : Car.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Car` subclass
// ===========================================================

#ifndef TRAFFICSIMULATION_CAR_H
#define TRAFFICSIMULATION_CAR_H

#include "../Vehicle.h"

const double carLength = 4.0;
const double carMaxSpeed = 16.6;
const double carMaxAcceleration = 1.44;
const double carMaxBrakeFactor = 4.61;
const double carMinFollowDistance = 4.0;

class Car : public Vehicle {
    Car* _initCheck;

public:
    /*
     * ENSURE(properlyInitialized(), "Car constructor did not end in an initialized state")
     */
    Car(const std::string &street, double position);

    ~Car();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "Car wasn't initialized when calling getLength()")
     */
    double getLength() const;

    /*
     * REQUIRE(properlyInitialized(), "Car wasn't initialized when calling getType()")
     */
    std::string getType() const;

    /*
     * REQUIRE(properlyInitialized(), "Car wasn't initialized when calling getAcronym()")
     */
    char getAcronym() const;

    /*
     * REQUIRE(properlyInitialized(), "Car wasn't initialized when calling drive()")
     *
     * ENSURE(fPosition >= startPosition || std::abs(fPosition-startPosition) < 0.001, "drive() postcondition")
     */
    void drive(Vehicle* vehicleInFront);

    /*
     * REQUIRE(properlyInitialized(), "Car wasn't initialized when calling brake()")
     *
     * ENSURE(fMaxSpeed <= carMaxSpeed, "brake() postcondition")
     * ENSURE(fMaxSpeed <= startMaxSpeed, "brake() postcondition")
     */
    void brake();

    /*
     * REQUIRE(properlyInitialized(), "Car wasn't initialized when calling stop()")
     *
     * ENSURE(fAcceleration <= startAcceleration, "stop() postcondition")
     */
    void stop();

    /*
     * REQUIRE(properlyInitialized(), "Car wasn't initialized when calling setMaxSpeed()")
     */
    void setMaxSpeed();

    /*
     * REQUIRE(properlyInitialized(), "Car wasn't initialized when calling hasPriority()")
     */
    bool hasPriority() const;
};


#endif