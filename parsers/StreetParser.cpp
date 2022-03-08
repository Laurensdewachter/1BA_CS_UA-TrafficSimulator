// ===========================================================
// Name         : StreetParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `Street`.
// ===========================================================

#include "StreetParser.h"
#include "../objects/Street.h"

StreetParser::StreetParser() {
    StreetParser::street = new Street();
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
        throw ParseException("The street has no contents.\nIt needs both a name and a length.");
    }
    if (nameElem == NULL) {
        throw ParseException("The street has no name.");
    }
    if (lengthElem == NULL) {
        throw ParseException("The street has no length.");
    }
    TiXmlText* nameText = nameElem->FirstChild()->ToText();
    std::string name = nameText->Value();

    TiXmlText* lengthText = lengthElem->FirstChild()->ToText();
    std::string lengthString = lengthText->Value();
    int length;
    std::istringstream(lengthString) >> length;

    street->setName(name);
    street->setLength(length);

    ENSURE(street->getName() == name, "parseStreet() postcondition");
    ENSURE(street->getLength() == length, "parseStreet() postcondition");
}

Street* StreetParser::getStreet() const {
    REQUIRE(properlyInitialized(), "StreetParser wasn't initialized when calling getStreet()");
    return street;
}
