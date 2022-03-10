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
        throw ParseException("Traffic light has no contents.\nIt needs a street, a position and a cycle.");
    }
    if (streetElem == NULL) {
        throw ParseException("Traffic light has no street.");
    }
    if (positionElem == NULL) {
        throw ParseException("Traffic light has no position.");
    }
    if (cycleElem == NULL) {
        throw ParseException("Traffic light has no cycle.");
    }
    if (streetElem->FirstChild() == NULL) {
        throw ParseException("Traffic light street name is empty");
    }
    TiXmlText* streetText = streetElem->FirstChild()->ToText();
    std::string street = streetText->Value();

    if (positionElem->FirstChild() == NULL) {
        throw ParseException("Traffic light position is empty");
    }
    TiXmlText* PositionText = positionElem->FirstChild()->ToText();
    std::string positionString = PositionText->Value();
    int position;
    if ((std::istringstream(positionString) >> position).fail()) {
        throw ParseException("Traffic light position is not a number");
    }

    if (positionElem->FirstChild() == NULL) {
        throw ParseException("Traffic light cycle is empty");
    }
    TiXmlText* cycleText = cycleElem->FirstChild()->ToText();
    std::string cycleString = cycleText->Value();
    int cycle;
    if ((std::istringstream(cycleString) >> cycle).fail()) {
        throw ParseException("Traffic light cycle is not a number");
    }

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
