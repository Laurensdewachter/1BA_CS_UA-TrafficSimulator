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
    std::string fStreet;
    int fPosition;
    int fCycle;
    bool fIsgreen;
    double fLastUpdateTime;

public:
    /*
     * ENSURE(properlyInitialized(), "TrafficLight constructor did not end in an initialized state");
     */
    TrafficLight();

    virtual ~TrafficLight();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setStreet()")
     * ENSURE(this->getStreet() == s, "setStreet() postcondition")
     */
    void setStreet(const std::string &s);

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setPosition()")
     * ENSURE(this->getPosition() == p, "setPosition() postcondition")
     */
    void setPosition(int p);

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setCycle()")
     * ENSURE(this->getCycle() == c, "setCycle() postcondition")
     */
    void setCycle(int c);

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setLight()")
     */
    void setLight(bool s);

    /*
     * REQUIRE(properlyInitialized(), "TrafficLight wasn't initialized when calling setLastUpdateTime()")
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
