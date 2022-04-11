#ifndef TRAFFICSIMULATION_FIREENGINE_H
#define TRAFFICSIMULATION_FIREENGINE_H

#include "Vehicle.h"

const double fireEngineLength = 10;
const double fireEngineMaxSpeed = 14.6;
const double fireEngineMaxAcceleration = 1.33;
const double fireEngineMaxBrakeFactor = 4.56;
const double fireEngineMinFollowDistance = 10;

class FireEngine : public Vehicle {
public:
    /*
     * ENSURE(properlyInitialized(), "FireEngine constructor did not end in an initialized state")
     */
    FireEngine(const std::string &street, double position);

    /*
     * REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling drive()")
     */
    void drive(Vehicle* vehicleInFront = NULL);

    /*
     * REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling brake()")
     */
    void brake();

    /*
     * REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling stop()")
     */
    void stop();

    /*
     * REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling setMaxSpeed()")
     */
    void setMaxSpeed();
};


#endif