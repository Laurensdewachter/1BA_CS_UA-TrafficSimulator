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

void StreetParser::parseStreet(TiXmlElement* BAAN, std::ostream &errStream) {
    REQUIRE(properlyInitialized(), "StreetParser wasn't initialized when calling parseStreet()");

    TiXmlElement* nameElem = BAAN->FirstChildElement("naam");
    TiXmlElement* lengthElem = BAAN->FirstChildElement("lengte");
    if (nameElem == NULL && lengthElem == NULL) {
        errStream<< "Street has no contents. It needs both a name and a length." << std::endl;
        return;
    }
    if (nameElem == NULL) {
        errStream<< "Street has no name." << std::endl;
        return;
    }
    if (lengthElem == NULL) {
        errStream<< "Street has no length." << std::endl;
        return;
    }
    if (nameElem->FirstChild() == NULL) {
        errStream << "Street name is empty" << std::endl;
        return;
    }
    TiXmlText* nameText = nameElem->FirstChild()->ToText();
    std::string name = nameText->Value();

    if (lengthElem->FirstChild() == NULL) {
        errStream << "Street length is empty" << std::endl;
        return;
    }
    TiXmlText* lengthText = lengthElem->FirstChild()->ToText();
    std::string lengthString = lengthText->Value();
    int length ;
    if ((std::istringstream(lengthString) >> length).fail()) {
        errStream << "Street length is not a number" << std::endl;
        return;
    }

    fStreet->setName(name);
    fStreet->setLength(length);

    ENSURE(fStreet->getName() == name, "parseStreet() postcondition");
    ENSURE(fStreet->getLength() == length, "parseStreet() postcondition");
}

Street* StreetParser::getStreet() const {
    REQUIRE(properlyInitialized(), "StreetParser wasn't initialized when calling getStreet()");
    return fStreet;
}
