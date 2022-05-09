#ifndef TRAFFICSIMULATION_CAR_H
#define TRAFFICSIMULATION_CAR_H

#include "../Vehicle.h"

const double carLength = 4.0;
const double carMaxSpeed = 16.6;
const double carMaxAcceleration = 1.44;
const double carMaxBrakeFactor = 4.61;
const double carMinFollowDistance = 4.0;

class Car : public Vehicle {
public:
    Car(const std::string &street, double position);

    ~Car();

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
