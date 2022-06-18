// ===========================================================
// Name         : PoliceCar.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `PoliceCar` subclass
// ===========================================================

#ifndef TRAFFICSIMULATION_POLICECAR_H
#define TRAFFICSIMULATION_POLICECAR_H

#include "../Vehicle.h"

const double policeCarLength = 6.0;
const double policeCarMaxSpeed = 17.2;
const double policeCarMaxAcceleration = 1.55;
const double policeCarMaxBrakeFactor = 4.92;
const double policeCarMinFollowDistance = 6.0;

class PoliceCar : public Vehicle {
    PoliceCar* _initCheck;

public:
    /*
     * ENSURE(properlyInitialized(), "PoliceCar constructor did not end in an initialized state")
     */
    PoliceCar(const std::string &street, double position);

    ~PoliceCar();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling getLength()")
     */
    double getLength() const;

    /*
     * REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling getType()")
     */
    std::string getType() const;

    /*
     * REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling getAcronym()")
     */
    char getAcronym() const;

    /*
     * REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling drive()")
     *
     * ENSURE(fPosition >= startPosition || std::abs(fPosition-startPosition) < 0.001, "drive() postcondition")
     */
    void drive(Vehicle* vehicleInFront);

    /*
     * REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling brake()")
     *
     * ENSURE(fMaxSpeed <= policeCarMaxSpeed, "brake() postcondition")
     * ENSURE(fMaxSpeed <= startMaxSpeed, "brake() postcondition")
     */
    void brake();

    /*
     * REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling stop()")
     *
     * ENSURE(fAcceleration <= startAcceleration, "stop() postcondition")
     */
    void stop();

    /*
     * REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling setMaxSpeed()")
     */
    void setMaxSpeed();

    /*
     * REQUIRE(properlyInitialized(), "PoliceCar wasn't initialized when calling hasPriority()")
     */
    bool hasPriority() const;
};


#endif