// ===========================================================
// Name         : Ambulance.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Ambulance` subclass
// ===========================================================

#ifndef TRAFFICSIMULATION_AMBULANCE_H
#define TRAFFICSIMULATION_AMBULANCE_H

#include "../Vehicle.h"

const double ambulanceLength = 8.0;
const double ambulanceMaxSpeed = 15.5;
const double ambulanceMaxAcceleration = 1.44;
const double ambulanceMaxBrakeFactor = 4.47;
const double ambulanceMinFollowDistance = 8.0;

class Ambulance : public Vehicle{
    Ambulance* _initCheck;

public:
    Ambulance(const std::string &street, double position);

    ~Ambulance();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling getLength()")
     */
    double getLength() const;

    /*
     * REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling getType()")
     */
    std::string getType() const;

    /*
     * REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling getAcronym()")
     */
    char getAcronym() const;

    /*
     * REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling getMinFollowDistance()")
     *
     * ENSURE(fPosition >= startPosition || std::abs(fPosition-startPosition) < 0.001, "drive() postcondition")
     */
    void drive(Vehicle* vehicleInFront);

    /*
     * REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling getMinFollowDistance()")
     *
     * ENSURE(fMaxSpeed <= ambulanceMaxSpeed, "brake() postcondition")
     * ENSURE(fMaxSpeed <= startMaxSpeed, "brake() postcondition")
     */
    void brake();

    /*
     * REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling getMinFollowDistance()")
     *
     * ENSURE (fAcceleration <= startAcceleration, "stop() postcondition")
     */
    void stop();

    /*
     * REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling getMinFollowDistance()")
     */
    void setMaxSpeed();

    /*
     * REQUIRE(properlyInitialized(), "Ambulance wasn't initialized when calling getMinFollowDistance()")
     */
    bool hasPriority() const;
};


#endif