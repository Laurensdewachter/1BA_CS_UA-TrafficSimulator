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
     * ENSURE(properlyInitialized(), "TrafficLight constructor dit not end in a initialized state.")
     */
    TrafficLight();

    virtual ~TrafficLight();

    bool properlyInitialized() const;

    /*
     * REQUIRE(TrafficLight::properlyInitialized(), "TrafficLight wasn't initialized when calling `setStreet()`.")
     * ENSURE(TrafficLight::street == s, "`setStreet()` postcondition failed.")
     */
    void setStreet(const std::string &street);

    /*
     * REQUIRE(TrafficLight::properlyInitialized(), "TrafficLight wasn't initialized when calling `setPosition()`.")
     * ENSURE(TrafficLight::position == p, "`setPosition()` postcondition failed.")
     */
    void setCycle(int cycle);

    /*
     * REQUIRE(TrafficLight::properlyInitialized(), "TrafficLight wasn't initialized when calling `setCycle()`.")
     * ENSURE(TrafficLight::position == c, "`setCycle()` postcondition failed.")
     */
    void setPosition(int position);

    /*
     * REQUIRE(TrafficLight::properlyInitialized(), "TrafficLight wasn't initialized when calling `getStreet()`.")
     */
    const std::string &getStreet() const;

    /*
     * REQUIRE(TrafficLight::properlyInitialized(), "TrafficLight wasn't initialized when calling `getPosition()`.")
     */
    int getPosition() const;

    /*
     * REQUIRE(TrafficLight::properlyInitialized(), "TrafficLight wasn't initialized when calling `getCycle()`.")
     */
    int getCycle() const;
};


#endif
