#ifndef TRAFFICSIMULATION_POLICECAR_H
#define TRAFFICSIMULATION_POLICECAR_H

#include "../Vehicle.h"

const double policeCarLength = 6.0;
const double policeCarMaxSpeed = 17.2;
const double policeCarMaxAcceleration = 1.55;
const double policeCarMaxBrakeFactor = 4.92;
const double policeCarMinFollowDistance = 6.0;

class PoliceCar : public Vehicle {
public:
    PoliceCar(const std::string &street, double position);

    ~PoliceCar();

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
