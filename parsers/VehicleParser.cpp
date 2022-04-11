// ===========================================================
// Name         : VehicleParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.2
// Description  : This code is used to parse an XML file that contains either a `Vehicle`.
// ===========================================================

#include "VehicleParser.h"
#include "../DesignByContract.h"
#include "../objects/Car.h"
#include "../objects/Bus.h"
#include "../objects/FireEngine.h"
#include "../objects/Ambulance.h"
#include "../objects/PoliceCar.h"

#include <sstream>

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
    TiXmlElement* typeElem = VOERTUIG->FirstChildElement("type");

    std::string street;
    int position;
    std::string type;

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

    if (typeElem == NULL || typeElem->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <type> ... </type>." << std::endl;
        missingElements = true;
    } else {
        type = typeElem->FirstChild()->ToText()->Value();
    }

    if (missingElements || wrongTypes) {
        return false;
    }

    if (type == "auto") {
        fVehicle = new Car(street, position);
    } else if (type == "bus") {
        fVehicle = new Bus(street, position);
    } else if (type == "brandweerwagen") {
        fVehicle = new FireEngine(street, position);
    } else if (type == "ziekenwagen") {
        fVehicle = new Ambulance(street, position);
    } else if (type == "politiecombi") {
        fVehicle = new PoliceCar(street, position);
    } else {
        errStream << "XML PARTIAL IMPORT: Expected <type> to be one of the following: auto, bus, brandweerwagen, ziekenwagen, politiecombi." << std::endl;
        return false;
    }

    ENSURE(fVehicle != NULL, "VehicleParser could not create a Vehicle");
    ENSURE(fVehicle->getStreet() == street, "parseVehicle() postcondition");
    ENSURE(fVehicle->getPosition() == position, "parseVehicle() postcondition");

    return true;
}

Vehicle *VehicleParser::getVehicle() const {
    REQUIRE(properlyInitialized(), "VehicleParser wasn't initialized when calling getVehicle()");
    REQUIRE(fVehicle != NULL, "VehicleParser had no vehicle when calling getVehicle()");
    return fVehicle;
}
