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
public:
    Ambulance(const std::string &street, double position);

    ~Ambulance();

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