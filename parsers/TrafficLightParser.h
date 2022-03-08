// ===========================================================
// Name         : TrafficLightParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `TrafficLight`.
// ===========================================================

#ifndef PSE_TRAFFICLIGHTPARSER_H
#define PSE_TRAFFICLIGHTPARSER_H


#include <iostream>
#include <sstream>
#include "ParseException.h"
#include "tinyxml/tinyxml.h"

class TrafficLight;

class TrafficLightParser {
    TrafficLight* trafficLight;
    TrafficLightParser* _initCheck;

public:
    /*
     * ENSURE(properlyInitialized(), "TrafficLightParser constructor did not end in an initialized state")
     */
    TrafficLightParser();

    virtual ~TrafficLightParser();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficLightParser wasn't initialized when calling parseTrafficLight()");
     * ENSURE(trafficLight->getStreet() == street, "parseTrafficLight() postcondition")
     * ENSURE(trafficLight->getPosition() == position, "parseTrafficLight() postcondition")
     * ENSURE(trafficLight->getCycle() == cycle, "parseTrafficLight() postcondition")
     */
    void parseTrafficLight(TiXmlElement* VERKEERSLICHT);

    /*
     * REQUIRE(properlyInitialized(), "TrafficLightParser wasn't initialized when calling getTrafficLight()")
     */
    TrafficLight* getTrafficLight() const;
};


#endif
