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
}

VehicleParser::~VehicleParser() {}

void VehicleParser::parseVehicle(TiXmlElement *VOERTUIG) {
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
}

Vehicle *VehicleParser::getVehicle() const {
    return vehicle;
}
