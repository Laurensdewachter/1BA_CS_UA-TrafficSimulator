// ===========================================================
// Name         : StreetParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `Street`.
// ===========================================================

#include "StreetParser.h"
#include "../objects/Street.h"

StreetParser::StreetParser() {
    street = new Street();
}

StreetParser::~StreetParser() {}

void StreetParser::parseStreet(TiXmlElement* BAAN) {
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
}

Street* StreetParser::getStreet() const {
    return street;
}
