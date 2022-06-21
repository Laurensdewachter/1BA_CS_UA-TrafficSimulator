// ===========================================================
// Name         : TrafficLight.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `TrafficLight` class
// ===========================================================

#ifndef PSE_TRAFFICLIGHT_H
#define PSE_TRAFFICLIGHT_H

#include <iostream>

class TrafficLight {
    TrafficLight* _initCheck;

    std::string fStreet;
    int fPosition;
    int fCycle;
    bool fIsgreen;
    double fLastUpdateTime;

public:
    /*
     * ENSURE(properlyInitialized(), "TrafficLight constructor did not end in an initialized state");
     */
    TrafficLight(const std::string &street, int position, int cycle);

    virtual ~TrafficLight();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setLastUpdateTime()")
     * REQUIRE(u >= 0, "LastUpdateTime must be greater than 0")
     *
     * ENSURE(this->getLastUpdateTime() == u, "setLastUpdateTime() postcondition")
     */
    void setLastUpdateTime(double u);

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

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling isGreen()")
     */
    bool isGreen() const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling getLastUpdateTime()")
     */
    double getLastUpdateTime() const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling changeLight()")
     */
    void changeLight();
};


#endif