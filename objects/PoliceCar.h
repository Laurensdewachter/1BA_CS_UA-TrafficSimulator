#ifndef TRAFFICSIMULATION_POLICECAR_H
#define TRAFFICSIMULATION_POLICECAR_H

#include "Vehicle.h"

const double policeCarLength = 6;
const double policeCarMaxSpeed = 17.2;
const double policeCarMaxAcceleration = 1.55;
const double policeCarMaxBrakeFactor = 4.92;
const double policeCarMinFollowDistance = 6;

class PoliceCar : public Vehicle {
public:
    /*
     * ENSURE(properlyInitialized(), "PoliceCar constructor did not end in an initialized state")
     */
    PoliceCar(const std::string &street, double position);

    /*
     * REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling drive()")
     */
    void drive(Vehicle* vehicleInFront = NULL);

    /*
     * REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling brake()")
     */
    void brake();

    /*
     * REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling stop()")
     */
    void stop();

    /*
     * REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling setMaxSpeed()")
     */
    void setMaxSpeed();
};


#endif