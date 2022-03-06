// ===========================================================
// Name         : TrafficLight.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `TrafficLight` class
// ===========================================================

#ifndef PSE_TRAFFICLIGHT_H
#define PSE_TRAFFICLIGHT_H

#include <iostream>
#include "../DesignByContract.h"

class TrafficLight {
    TrafficLight* _initCheck;
    std::string street;
    int position;
    int cycle;

public:
    /*
     * ENSURE(properlyInitialized(), "TrafficLight constructor dit not end in an initialized state");
     */
    TrafficLight();

    virtual ~TrafficLight();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setStreet()")
     * ENSURE(this->getStreet() == s, "setStreet() postcondition")
     */
    void setStreet(const std::string &street);

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setPosition()")
     * ENSURE(this->getPosition() == p, "setPosition() postcondition")
     */
    void setPosition(int position);

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setCycle()")
     * ENSURE(this->getCycle() == c, "setCycle() postcondition")
     */
    void setCycle(int cycle);

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling getStreet()")
     */
    const std::string &getStreet() const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling getPosition()")
     */
    int getPosition() const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling getCycle()")
     */
    int getCycle() const;
};


#endif