// ===========================================================
// Name         : TrafficLightParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `TrafficLight`.
// ===========================================================

#include "TrafficLightParser.h"
#include "../objects/TrafficLight.h"

TrafficLightParser::TrafficLightParser() {
    fTrafficLight = new TrafficLight();
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
        throw ParseException("The traffic light has no contents.\nIt needs a fStreet, a fPosition and a fCycle.");
    }
    if (streetElem == NULL) {
        throw ParseException("The traffic light has no fStreet.");
    }
    if (positionElem == NULL) {
        throw ParseException("The traffic light has no fPosition.");
    }
    if (cycleElem == NULL) {
        throw ParseException("The traffic light has no fCycle.");
    }
    if (streetElem->FirstChild() == NULL) {
        throw ParseException("The traffic lights fStreet name is empty");
    }
    TiXmlText* streetText = streetElem->FirstChild()->ToText();
    std::string street = streetText->Value();

    if (positionElem->FirstChild() == NULL) {
        throw ParseException("The traffic lights fPosition is empty");
    }
    TiXmlText* PositionText = positionElem->FirstChild()->ToText();
    std::string positionString = PositionText->Value();
    int position;
    std::istringstream(positionString) >> position;

    if (positionElem->FirstChild() == NULL) {
        throw ParseException("The traffic lights fCycle is empty");
    }
    TiXmlText* cycleText = cycleElem->FirstChild()->ToText();
    std::string cycleString = cycleText->Value();
    int cycle;
    std::istringstream(cycleString) >> cycle;

    fTrafficLight->setStreet(street);
    fTrafficLight->setPosition(position);
    fTrafficLight->setCycle(cycle);
    ENSURE(fTrafficLight->getStreet() == street, "parseTrafficLight() postcondition");
    ENSURE(fTrafficLight->getPosition() == position, "parseTrafficLight() postcondition");
    ENSURE(fTrafficLight->getCycle() == cycle, "parseTrafficLight() postcondition");
}

TrafficLight* TrafficLightParser::getTrafficLight() const {
    REQUIRE(properlyInitialized(), "TrafficLightParser wasn't initialized when calling getTrafficLight()");
    return fTrafficLight;
}
