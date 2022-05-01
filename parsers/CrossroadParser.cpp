// ===========================================================
// Name         : CrossroadParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.2
// Description  : This code is used to parse an XML file that contains either a `Crossroad`.
// ===========================================================


#include "CrossroadParser.h"
#include "../objects/Crossroad.h"
#include "../DesignByContract.h"


CrossroadParser::CrossroadParser() {
    CrossroadParser::_initCheck = this;
    ENSURE(properlyInitialized(), "CrossroadParser constructor did not end in an initialized state");
}

CrossroadParser::~CrossroadParser() {}

bool CrossroadParser::properlyInitialized() const {
    return CrossroadParser::_initCheck == this;
}

bool CrossroadParser::parseCrossroad(TiXmlElement *KRUISPUNT, std::ostream &errStream) {
    REQUIRE(properlyInitialized(), "CrossroadParser wasn't initialized when calling parseCrossroad()");
    REQUIRE(errStream.good(), "The errorStream wasn't good");

    TiXmlElement* baanElem1 = KRUISPUNT->FirstChildElement("baan");
    TiXmlAttribute* positionElem1 = KRUISPUNT->FirstChildElement("baan")->FirstAttribute();

    TiXmlElement* baanElem2 = KRUISPUNT->FirstChildElement("baan")->NextSiblingElement("baan");
    TiXmlAttribute* positionElem2 = KRUISPUNT->FirstChildElement("baan")->NextSiblingElement()->FirstAttribute();

    std::string firstStreet;
    int firstPosition;
    std::string secondStreet;
    int secondPosition;

    bool wrongTypes = false;
    bool missingElements = false;

    if (baanElem1 == NULL || baanElem1->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <baan> ... </baan>." << std::endl;
        missingElements = true;
    } else {
        TiXmlText* streetText = baanElem1->FirstChild()->ToText();
        firstStreet = streetText->Value();
    }
    if (baanElem2 == NULL || baanElem2->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <baan> ... </baan>." << std::endl;
        missingElements = true;
    } else {
        TiXmlText* streetText = baanElem2->FirstChild()->ToText();
        secondStreet = streetText->Value();
    }

    if (positionElem1 == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <positie = '...' >" << std::endl;
        missingElements = true;
    } else {
        std::string positionString = positionElem1->Value();
        if ((std::istringstream(positionString) >> firstPosition).fail()) {
            errStream << "XML PARTIAL IMPORT: Expected <positie> to be an integer." << std::endl;
            wrongTypes = true;
        }
    }
    if (positionElem2 == NULL ) {
        errStream << "XML PARTIAL IMPORT: Expected <positie = '...' >" << std::endl;
        missingElements = true;
    } else {
        std::string positionString = positionElem2->Value();
        if ((std::istringstream(positionString) >> secondPosition).fail()) {
            errStream << "XML PARTIAL IMPORT: Expected <positie> to be an integer." << std::endl;
            wrongTypes = true;
        }
    }
    std::cout << "Baan : " << firstStreet << " -> Positie: " << firstPosition << std::endl;
    std::cout << "Baan : " << secondStreet << " -> Positie: " << secondPosition << std::endl;

    if (missingElements || wrongTypes) {
        return false;
    }

    ENSURE(fCrossroad != NULL, "CrossroadParser could not create a Crossroad");
    //ENSURE(fCrossroad->getStreet() == firstStreet, "parseCrossroad() postcondition");
    //ENSURE(fCrossroad->getPosition() == firstPosition, "parseCrossroad() postcondition");
    //ENSURE(fCrossroad->getStreet() == secondStreet, "parseCrossroad() postcondition");
    //ENSURE(fCrossroad->getPosition() == secondPosition, "parseCrossroad() postcondition");

    return true;
}

Crossroad *CrossroadParser::getCrossroad() const {
    REQUIRE(properlyInitialized(), "CrossroadParser wasn't initialized when calling getCrossroad()");
    REQUIRE(fCrossroad != NULL, "CrossroadParser had no crossroad when calling getCrossroad()");
    return fCrossroad;
}