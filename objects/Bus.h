#ifndef TRAFFICSIMULATION_BUS_H
#define TRAFFICSIMULATION_BUS_H

#include "Vehicle.h"

const double busLength = 12;
const double busMaxSpeed = 11.4;
const double busMaxAcceleration = 1.22;
const double busMaxBrakeFactor = 4.29;
const double busMinFollowDistance = 12;

class Bus : public Vehicle{
public:
    /*
     * ENSURE(properlyInitialized(), "Bus constructor did not end in an initialized state")
     */
    Bus(const std::string &street, double position);

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling drive()")
     */
    void drive(Vehicle* vehicleInFront);

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling brake()")
     */
    void brake();

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling stop()")
     */
    void stop();

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling setMaxSpeed()")
     */
    void setMaxSpeed();
};


#endif