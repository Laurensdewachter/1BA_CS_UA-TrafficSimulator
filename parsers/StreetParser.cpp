// ===========================================================
// Name         : StreetParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is used to parse an XML file that contains a `Street`.
// ===========================================================

#include <sstream>
#include "StreetParser.h"
#include "../DesignByContract.h"
#include "../objects/Street.h"

StreetParser::StreetParser() {
    StreetParser::_initCheck = this;

    ENSURE(properlyInitialized(), "StreetParser constructor did not end in an initialized state");
}

StreetParser::~StreetParser() {}

bool StreetParser::properlyInitialized() const {
    return StreetParser::_initCheck == this;
}

bool StreetParser::parseStreet(TiXmlElement* BAAN, std::ostream &errStream) {
    REQUIRE(properlyInitialized(), "StreetParser wasn't initialized when calling parseStreet()");
    REQUIRE(errStream.good(), "The errorStream wasn't good at the beginning of parseStreet()");

    TiXmlElement* nameElem = BAAN->FirstChildElement("naam");
    TiXmlElement* lengthElem = BAAN->FirstChildElement("lengte");

    std::string name;
    int length;

    bool wrongTypes = false;
    bool missingElements = false;
    if (nameElem == NULL || nameElem->FirstChild() == NULL) {
        errStream<< "XML PARTIAL IMPORT: Expected <naam> ... </naam>." << std::endl;
        missingElements = true;
    } else {
        TiXmlText* nameText = nameElem->FirstChild()->ToText();
        name = nameText->Value();
    }
    if (lengthElem == NULL || lengthElem->FirstChild() == NULL) {
        errStream<< "XML PARTIAL IMPORT: Expected <lengte> ... </lengte>." << std::endl;
        missingElements = true;
    } else {
        std::string lengthString = lengthElem->FirstChild()->ToText()->Value();
        if ((std::istringstream(lengthString) >> length).fail()) {
            errStream << "XML PARTIAL IMPORT: Expected <lengte> to be an integer." << std::endl;
            wrongTypes = true;
        }
    }

    if (missingElements || wrongTypes) {
        return false;
    }

    fStreet = new Street(name, length);

    ENSURE(fStreet != NULL, "StreetParser could not create a Street");
    ENSURE(fStreet->getName() == name, "parseStreet() postcondition");
    ENSURE(fStreet->getLength() == length, "parseStreet() postcondition");
    ENSURE(errStream.good(), "The errorStream wasn't good at the end of parseStreet()");

    return true;
}

Street* StreetParser::getStreet() const {
    REQUIRE(properlyInitialized(), "StreetParser wasn't initialized when calling getStreet()");
    REQUIRE(fStreet != NULL, "StreetParser had no street when calling getStreet()");

    return fStreet;
}
