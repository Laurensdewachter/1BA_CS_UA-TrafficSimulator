#ifndef TRAFFICSIMULATION_CAR_H
#define TRAFFICSIMULATION_CAR_H

#include "Vehicle.h"

const double carLength = 4;
const double carMaxSpeed = 16.6;
const double carMaxAcceleration = 1.44;
const double carMaxBrakeFactor = 4.61;
const double carMinFollowDistance = 4;

class Car : public Vehicle {
public:
    /*
     * ENSURE(properlyInitialized(), "Car constructor did not end in an initialized state")
     */
    Car(const std::string &street, double position);

    /*
     * REQUIRE(properlyInitialized(), "Car wasn't initialized when calling drive()")
     */
    void drive(Vehicle* vehicleInFront);

    /*
     * REQUIRE(properlyInitialized(), "Car wasn't initialized when calling brake()")
     */
    void brake();

    /*
     * REQUIRE(properlyInitialized(), "Car wasn't initialized when calling stop()")
     */
    void stop();

    /*
     * REQUIRE(properlyInitialized(), "Car wasn't initialized when calling setMaxSpeed()")
     */
    void setMaxSpeed();
};


#endif