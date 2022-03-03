#ifndef PSE_VEHICLE_H
#define PSE_VEHICLE_H

#include <iostream>

class Vehicle {
    std::string street;
    int position;

public:
    Vehicle();
    virtual ~Vehicle();

    void setStreet(const std::string &street);
    void setPosition(int position);

    const std::string &getStreet() const;
    int getPosition() const;
};


#endif //PSE_VEHICLE_H
