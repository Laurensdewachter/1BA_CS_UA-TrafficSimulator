// ===========================================================
// Name         : VehicleParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is used to parse an XML file that contains either a `Vehicle`.
// ===========================================================

#include "VehicleParser.h"
#include "../objects/Vehicle.h"

VehicleParser::VehicleParser() {
    VehicleParser::_initCheck = this;
    ENSURE(properlyInitialized(), "VehicleParser constructor did not end in an initialized state");
}

VehicleParser::~VehicleParser() {}

bool VehicleParser::properlyInitialized() const {
    return VehicleParser::_initCheck == this;
}

bool VehicleParser::parseVehicle(TiXmlElement *VOERTUIG, std::ostream &errStream) {
    REQUIRE(properlyInitialized(), "VehicleParser wasn't initialized when calling parseVehicle()");
    REQUIRE(errStream.good(), "The errorStream wasn't good");

    TiXmlElement* baanElem = VOERTUIG->FirstChildElement("baan");
    TiXmlElement* positionElem = VOERTUIG->FirstChildElement("positie");

    std::string street;
    int position;

    bool wrongTypes = false;
    bool missingElements = false;
    if (baanElem == NULL || baanElem->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <baan> ... </baan>." << std::endl;
        missingElements = true;
    } else {
        TiXmlText* streetText = baanElem->FirstChild()->ToText();
        street = streetText->Value();
    }
    if (positionElem == NULL || positionElem->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <positie> ... </positie>." << std::endl;
        missingElements = true;
    } else {
        std::string positionString = positionElem->FirstChild()->ToText()->Value();
        if ((std::istringstream(positionString) >> position).fail()) {
            errStream << "XML PARTIAL IMPORT: Expected <positie> to be an integer." << std::endl;
            wrongTypes = true;
        }
    }

    if (missingElements || wrongTypes) {
        return false;
    }

    fVehicle = new Vehicle();
    fVehicle->setStreet(street);
    fVehicle->setPosition(position);

    ENSURE(fVehicle->getStreet() == street, "parseVehicle() postcondition");
    ENSURE(fVehicle->getPosition() == position, "parseVehicle() postcondition");

    return true;
}

Vehicle *VehicleParser::getVehicle() const {
    REQUIRE(properlyInitialized(), "VehicleParser wasn't initialized when calling getVehicle()");
    REQUIRE(fVehicle != NULL, "VehicleParser had no vehicle when calling getVehicle()");
    return fVehicle;
}
