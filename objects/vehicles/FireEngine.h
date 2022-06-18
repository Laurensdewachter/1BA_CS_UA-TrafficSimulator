// ===========================================================
// Name         : FireEngine.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `FireEngine` subclass
// ===========================================================

#ifndef TRAFFICSIMULATION_FIREENGINE_H
#define TRAFFICSIMULATION_FIREENGINE_H

#include "../Vehicle.h"

const double fireEngineLength = 10.0;
const double fireEngineMaxSpeed = 14.6;
const double fireEngineMaxAcceleration = 1.33;
const double fireEngineMaxBrakeFactor = 4.56;
const double fireEngineMinFollowDistance = 10.0;

class FireEngine : public Vehicle{
    FireEngine* _initCheck;

public:
    /*
     * ENSURE(properlyInitialized(), "FireEngine constructor did not end in an initialized state")
     */
    FireEngine(const std::string &street, double position);

    ~FireEngine();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling getLength()")
     */
    double getLength() const;

    /*
     * REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling getType()")
     */
    std::string getType() const;

    /*
     * REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling getAcronym()")
     */
    char getAcronym() const;

    /*
     * REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling drive()")
     *
     * ENSURE(fPosition >= startPosition || std::abs(fPosition-startPosition) < 0.001, "drive() postcondition")
     */
    void drive(Vehicle* vehicleInFront);

    /*
     * REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling brake()")
     *
     * ENSURE(fMaxSpeed <= fireEngineMaxSpeed, "brake() postcondition");
     * ENSURE(fMaxSpeed <= startMaxSpeed, "brake() postcondition");
     */
    void brake();

    /*
     * REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling stop()")
     *
     * ENSURE(fAcceleration <= startAcceleration, "stop() postcondition")
     */
    void stop();

    /*
     * REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling setMaxSpeed()")
     */
    void setMaxSpeed();

    /*
     * REQUIRE(properlyInitialized(), "FireEngine wasn't initialized when calling hasPriority()")
     */
    bool hasPriority() const;
};


#endif