// ===========================================================
// Name         : TrafficLightParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `TrafficLight`.
// ===========================================================

#include "TrafficLightParser.h"
#include "../objects/TrafficLight.h"

TrafficLightParser::TrafficLightParser() {
    trafficLight = new TrafficLight();
    TrafficLightParser::_initCheck = this;
    ENSURE(properlyInitialized(), "TrafficLightParser constructor did not end in an initialized state");
}

TrafficLightParser::~TrafficLightParser() {}

bool TrafficLightParser::properlyInitialized() const {
    return TrafficLightParser::_initCheck == this;
}

void TrafficLightParser::parseTrafficLight(TiXmlElement* VERKEERSLICHT) {
    REQUIRE(properlyInitialized(), "TrafficLightParser wasn't initialized when calling parseTrafficLight()");

    TiXmlElement* streetElem = VERKEERSLICHT->FirstChildElement("baan");
    TiXmlElement* positionElem = VERKEERSLICHT->FirstChildElement("positie");
    TiXmlElement* cycleElem = VERKEERSLICHT->FirstChildElement("cyclus");
    if (streetElem == NULL && positionElem == NULL && cycleElem == NULL) {
        throw ParseException("The traffic light has no contents.\nIt needs a street, a position and a cycle.");
    }
    if (streetElem == NULL) {
        throw ParseException("The traffic light has no street.");
    }
    if (positionElem == NULL) {
        throw ParseException("The traffic light has no position.");
    }
    if (cycleElem == NULL) {
        throw ParseException("The traffic light has no cycle.");
    }
    TiXmlText* streetText = streetElem->FirstChild()->ToText();
    std::string street = streetText->Value();

    TiXmlText* PositionText = positionElem->FirstChild()->ToText();
    std::string positionString = PositionText->Value();
    int position;
    std::istringstream(positionString) >> position;

    TiXmlText* cycleText = cycleElem->FirstChild()->ToText();
    std::string cycleString = cycleText->Value();
    int cycle;
    std::istringstream(cycleString) >> cycle;

    trafficLight->setStreet(street);
    trafficLight->setPosition(position);
    trafficLight->setCycle(cycle);
    ENSURE(trafficLight->getStreet() == street, "parseTrafficLight() postcondition");
    ENSURE(trafficLight->getPosition() == position, "parseTrafficLight() postcondition");
    ENSURE(trafficLight->getCycle() == cycle, "parseTrafficLight() postcondition");
}

TrafficLight* TrafficLightParser::getTrafficLight() const {
    REQUIRE(properlyInitialized(), "TrafficLightParser wasn't initialized when calling getTrafficLight()");
    return trafficLight;
}
