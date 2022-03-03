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
#include "tinyxml/tinyxml.h"
#include "ParseException.h"

class TrafficLight;

class TrafficLightParser {
    TrafficLight* trafficLight;

public:
    TrafficLightParser();
    virtual ~TrafficLightParser();

    void parseTrafficLight(TiXmlElement* VERKEERSLICHT);
    TrafficLight* getTrafficLight() const;
};


#endif //PSE_TRAFFICLIGHTPARSER_H
