// ===========================================================
// Name         : VehicleParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains either a `Vehicle`.
// ===========================================================

#include "VehicleParser.h"
#include "../objects/Vehicle.h"

VehicleParser::VehicleParser() {
    vehicle = new Vehicle;
    VehicleParser::_initCheck =this;
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
        throw ParseException("The vehicle has no contents.\nIt needs both a street and a position.");
    }
    if (baanElem == NULL) {
        throw ParseException("The vehicle has no street.");
    }
    if (positionElem == NULL) {
        throw ParseException("The vehicle has no position.");
    }
    TiXmlText* streetText = baanElem->FirstChild()->ToText();
    std::string street = streetText->Value();

    TiXmlText* positionText = positionElem->FirstChild()->ToText();
    std::string positionString = positionText->Value();
    int position;
    std::istringstream(positionString) >> position;

    vehicle->setStreet(street);
    vehicle->setPosition(position);

    ENSURE(vehicle->getStreet() == street, "parseVehicle() postcondition");
    ENSURE(vehicle->getPosition() == position, "parseVehicle() postcondition");
}

Vehicle *VehicleParser::getVehicle() const {
    REQUIRE(properlyInitialized(), "VehicleParser wasn't initialized when calling getVehicle()");
    return vehicle;
}
