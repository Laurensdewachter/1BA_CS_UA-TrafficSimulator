// ===========================================================
// Name         : StreetParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `Street`.
// ===========================================================

#include "StreetParser.h"
#include "../objects/Street.h"

StreetParser::StreetParser() {
    StreetParser::fStreet = new Street();
    StreetParser::_initCheck = this;
    ENSURE(properlyInitialized(), "StreetParser constructor did not end in an initialized state");
}

StreetParser::~StreetParser() {}

bool StreetParser::properlyInitialized() const {
    return StreetParser::_initCheck == this;
}

void StreetParser::parseStreet(TiXmlElement* BAAN) {
    REQUIRE(properlyInitialized(), "StreetParser wasn't initialized when calling parseStreet()");

    TiXmlElement* nameElem = BAAN->FirstChildElement("naam");
    TiXmlElement* lengthElem = BAAN->FirstChildElement("lengte");
    if (nameElem == NULL && lengthElem == NULL) {
        throw ParseException("The fStreet has no contents.\nIt needs both a name and a length.");
    }
    if (nameElem == NULL) {
        throw ParseException("The fStreet has no name.");
    }
    if (lengthElem == NULL) {
        throw ParseException("The fStreet has no length.");
    }
    if (nameElem->FirstChild() == NULL) {
        throw ParseException("The fStreets name is empty");
    }
    TiXmlText* nameText = nameElem->FirstChild()->ToText();
    std::string name = nameText->Value();

    if (lengthElem->FirstChild() == NULL) {
        throw ParseException("The fStreets length is empty");
    }
    TiXmlText* lengthText = lengthElem->FirstChild()->ToText();
    std::string lengthString = lengthText->Value();
    int length;
    std::istringstream(lengthString) >> length;

    fStreet->setName(name);
    fStreet->setLength(length);

    ENSURE(fStreet->getName() == name, "parseStreet() postcondition");
    ENSURE(fStreet->getLength() == length, "parseStreet() postcondition");
}

Street* StreetParser::getStreet() const {
    REQUIRE(properlyInitialized(), "StreetParser wasn't initialized when calling getStreet()");
    return fStreet;
}
