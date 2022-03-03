#ifndef PSE_TRAFFICLIGHT_H
#define PSE_TRAFFICLIGHT_H

#include <iostream>

class TrafficLight {
    std::string street;
    int position;
    int cycle;

public:
    TrafficLight();
    virtual ~TrafficLight();

    void setStreet(const std::string &street);
    void setCycle(int cycle);
    void setPosition(int position);

    const std::string &getStreet() const;
    int getPosition() const;
    int getCycle() const;
};


#endif //PSE_TRAFFICLIGHT_H
