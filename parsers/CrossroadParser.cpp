// ===========================================================
// Name         : CrossroadParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains either a `Crossroad`.
// ===========================================================


#include "CrossroadParser.h"
#include "../DesignByContract.h"
#include "../parsers/ElementParser.h"
#include "../objects/Street.h"
#include <sstream>

CrossroadParser::CrossroadParser() {
    CrossroadParser::_initCheck = this;

    ENSURE(properlyInitialized(), "CrossroadParser constructor did not end in an initialized state");
}

CrossroadParser::~CrossroadParser() {}

bool CrossroadParser::properlyInitialized() const {
    return _initCheck == this;
}

bool CrossroadParser::parseCrossroad(TiXmlElement* KRUISPUNT, std::ostream &errStream) {
    REQUIRE(properlyInitialized(), "CrossroadParser wasn't initialized when calling parseCrossroad()");
    REQUIRE(errStream.good(), "The errorStream wasn't good");

    TiXmlElement* baanElem1 = KRUISPUNT->FirstChildElement("baan");

    std::string street1;
    unsigned int position1;
    std::string street2;
    unsigned int position2;

    bool wrongTypes = false;
    bool missingElements = false;

    if (baanElem1 == NULL || baanElem1->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <baan positie=\"...\"> ... </baan>." << std::endl;
        missingElements = true;
    } else {
        TiXmlText* streetText = baanElem1->FirstChild()->ToText();
        street1 = streetText->Value();
    }
    if (missingElements) {
        return false;
    }

    TiXmlAttribute* positionAtr1 = baanElem1->FirstAttribute();
    std::string compareString = "positie";
    if (positionAtr1 == NULL || positionAtr1->Name() != compareString) {
        errStream << "XML PARTIAL IMPORT: Expected <baan positie=\"...\"> ... </baan>" << std::endl;
        missingElements = true;
    } else {
        std::string positionString = positionAtr1->Value();
        if((std::istringstream(positionString) >> position1).fail()){
            errStream << "XML PARTIAL IMPORT: Expected attribute \"positie\" to be an integer." << std::endl;
            wrongTypes = true;
        }
    }
    if (missingElements || wrongTypes) {
        return false;
    }

    TiXmlElement* baanElem2 = KRUISPUNT->FirstChildElement("baan")->NextSiblingElement("baan");

    if (baanElem2 == NULL || baanElem2->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <baan positie=\"\"> ... </baan>." << std::endl;
        missingElements = true;
    } else {
        TiXmlText* streetText = baanElem2->FirstChild()->ToText();
        street2 = streetText->Value();
    }
    if (missingElements) {
        return false;
    }

    TiXmlAttribute* positionAtr2 = baanElem1->FirstAttribute();
    if (positionAtr2 == NULL || positionAtr1->Name() != compareString) {
        errStream << "XML PARTIAL IMPORT: Expected <baan positie=\"...\"> ... </baan>" << std::endl;
        missingElements = true;
    } else {
        std::string positionString = positionAtr2->Value();
        if((std::istringstream(positionString) >> position2).fail()){
            errStream << "XML PARTIAL IMPORT: Expected attribute \"positie\" to be an integer." << std::endl;
            wrongTypes = true;
        }
    }
    if (missingElements || wrongTypes) {
        return false;
    }

    fStreet1.first = street1;
    fStreet1.second = position1;
    fStreet2.first = street2;
    fStreet2.second = position2;

    return true;
}

const std::pair<std::string, unsigned int> &CrossroadParser::getStreet1() const {
    REQUIRE(properlyInitialized(), "CrossroadParser wasn't initialized when calling getStreet1()");

    return fStreet1;
}

const std::pair<std::string, unsigned int> &CrossroadParser::getStreet2() const {
    REQUIRE(properlyInitialized(), "CrossroadParser wasn't initialized when calling getStreet2()");

    return fStreet2;
}
