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
    double fWaitTime;
public:
    Bus(const std::string &street, double position);

    ~Bus();

    double getLength() const;

    double getWaitTime() const;

    void addWaitTime(double time);

    void clearWaitTime();

    std::string getType() const;

    char getAcronym() const;

    void drive(Vehicle* vehicleInFront);

    void brake();

    void stop();

    void setMaxSpeed();

    bool hasPriority() const;
};

#endif
