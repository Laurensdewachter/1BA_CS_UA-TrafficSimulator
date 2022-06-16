// ===========================================================
// Name         : TrafficLightParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is used to parse an XML file that contains a `TrafficLight`.
// ===========================================================

#ifndef PSE_TRAFFICLIGHTPARSER_H
#define PSE_TRAFFICLIGHTPARSER_H

#include "tinyxml/tinyxml.h"

class TrafficLight;

class TrafficLightParser {
    TrafficLightParser* _initCheck;

    TrafficLight* fTrafficLight;

public:
    /*
     * ENSURE(properlyInitialized(), "TrafficLightParser constructor did not end in an initialized state")
     */
    TrafficLightParser();

    virtual ~TrafficLightParser();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "TrafficLightParser wasn't initialized when calling parseTrafficLight()")
     * REQUIRE(errStream.good(), "The errorStream wasn't good at the beginning of parseTrafficLight()")
     *
     * ENSURE(fTrafficLight != NULL, "TrafficLightParser could not create a TrafficLight")
     * ENSURE(fTrafficLight->getStreet() == street, "parseTrafficLight() postcondition")
     * ENSURE(fTrafficLight->getPosition() == position, "parseTrafficLight() postcondition")
     * ENSURE(fTrafficLight->getCycle() == cycle, "parseTrafficLight() postcondition")
     * ENSURE(errStream.good(), "The errorStream wasn't good at the end of parseTrafficLight()")
     */
    bool parseTrafficLight(TiXmlElement* VERKEERSLICHT, std::ostream &errStream);

    /*
     * REQUIRE(properlyInitialized(), "TrafficLightParser wasn't initialized when calling getTrafficLight()")
     * REQUIRE(fTrafficLight != NULL, "TrafficLightParser had no traffic light when calling getTrafficLight()")
     */
    TrafficLight* getTrafficLight() const;
};


#endif