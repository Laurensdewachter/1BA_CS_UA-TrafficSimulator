#ifndef TRAFFICSIMULATION_AMBULANCE_H
#define TRAFFICSIMULATION_AMBULANCE_H

#include "Vehicle.h"

const double ambulanceLength = 10;
const double ambulanceMaxSpeed = 14.6;
const double ambulanceMaxAcceleration = 1.33;
const double ambulanceMaxBrakeFactor = 4.56;
const double ambulanceMinFollowDistance = 10;

class Ambulance : public Vehicle {
public:
    /*
     * ENSURE(properlyInitialized(), "Ambulance constructor did not end in an initialized state")
     */
    Ambulance(const std::string &street, double position);

    /*
     * REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling drive()")
     */
    void drive(Vehicle* vehicleInFront = NULL);

    /*
     * REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling brake()")
     */
    void brake();

    /*
     * REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling stop()")
     */
    void stop();

    /*
     * REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling setMaxSpeed()")
     */
    void setMaxSpeed();
};


#endif