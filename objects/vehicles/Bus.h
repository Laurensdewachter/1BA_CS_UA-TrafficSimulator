// ===========================================================
// Name         : Bus.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Bus` subclass
// ===========================================================

#ifndef TRAFFICSIMULATION_BUS_H
#define TRAFFICSIMULATION_BUS_H

#include "../Vehicle.h"

const double busLength = 12.0;
const double busMaxSpeed = 11.4;
const double busMaxAcceleration = 1.22;
const double busMaxBrakeFactor = 4.29;
const double busMinFollowDistance = 12.0;

class Bus : public Vehicle{
    Bus* _initCheck;

    double fWaitTime;

public:
    /*
     * ENSURE(properlyInitialized(), "Bus constructor did not end in an initialized state")
     */
    Bus(const std::string &street, double position);

    ~Bus();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling getLength()")
     */
    double getLength() const;

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling getType()")
     */
    double getWaitTime() const;

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling addWaitTime()")
     */
    void addWaitTime(double time);

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling clearWaitTime()")
     */
    void clearWaitTime();

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling getType()")
     */
    std::string getType() const;

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling getAcronym()")
     */
    char getAcronym() const;

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling drive()")
     *
     * ENSURE(fPosition >= startPosition || std::abs(fPosition-startPosition) < 0.001, "drive() postcondition")
     */
    void drive(Vehicle* vehicleInFront);

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling brake()")
     *
     * ENSURE(fMaxSpeed <= busMaxSpeed, "brake() postcondition");
     * ENSURE(fMaxSpeed <= startMaxSpeed, "brake() postcondition");
     */
    void brake();

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling stop()")
     *
     * ENSURE(fAcceleration <= startAcceleration, "stop() postcondition")
     */
    void stop();

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling setMaxSpeed()")
     */
    void setMaxSpeed();

    /*
     * REQUIRE(properlyInitialized(), "Bus wasn't initialized when calling hasPriority()")
     */
    bool hasPriority() const;
};


#endif