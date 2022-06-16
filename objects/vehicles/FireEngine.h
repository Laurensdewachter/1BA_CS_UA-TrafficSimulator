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
public:
    FireEngine(const std::string &street, double position);

    ~FireEngine();

    double getLength() const;

    std::string getType() const;

    char getAcronym() const;

    void drive(Vehicle* vehicleInFront);

    void brake();

    void stop();

    void setMaxSpeed();

    bool hasPriority() const;
};

#endif
