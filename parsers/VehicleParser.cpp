// ===========================================================
// Name         : VehicleParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains either a `Vehicle`.
// ===========================================================

#include "VehicleParser.h"
#include "../objects/Vehicle.h"

VehicleParser::VehicleParser() {
    fVehicle = new Vehicle;
    VehicleParser::_initCheck = this;
    ENSURE(properlyInitialized(), "VehicleParser constructor did not end in an initialized state");
}

VehicleParser::~VehicleParser() {}

bool VehicleParser::properlyInitialized() const {
    return VehicleParser::_initCheck == this;
}

void VehicleParser::parseVehicle(TiXmlElement *VOERTUIG) {
    REQUIRE(properlyInitialized(), "VehicleParser wasn't initialized when calling parseVehicle()");

    TiXmlElement* baanElem = VOERTUIG->FirstChildElement("baan");
    TiXmlElement* positionElem = VOERTUIG->FirstChildElement("positie");
    if (baanElem == NULL && positionElem == NULL) {
        throw ParseException("The fVehicle has no contents.\nIt needs both a fStreet and a fPosition.");
    }
    if (baanElem == NULL) {
        throw ParseException("The fVehicle has no fStreet.");
    }
    if (positionElem == NULL) {
        throw ParseException("The fVehicle has no fPosition.");
    }
    if (baanElem->FirstChild() == NULL) {
        throw ParseException("The fVehicles fStreet name is empty");
    }
    TiXmlText* streetText = baanElem->FirstChild()->ToText();
    std::string street = streetText->Value();

    if (positionElem->FirstChild() == NULL) {
        throw ParseException("The fVehicles fPosition is empty");
    }
    TiXmlText* positionText = positionElem->FirstChild()->ToText();
    std::string positionString = positionText->Value();
    int position;
    std::istringstream(positionString) >> position;

    fVehicle->setStreet(street);
    fVehicle->setPosition(position);

    ENSURE(fVehicle->getStreet() == street, "parseVehicle() postcondition");
    ENSURE(fVehicle->getPosition() == position, "parseVehicle() postcondition");
}

Vehicle *VehicleParser::getVehicle() const {
    REQUIRE(properlyInitialized(), "VehicleParser wasn't initialized when calling getVehicle()");
    return fVehicle;
}
