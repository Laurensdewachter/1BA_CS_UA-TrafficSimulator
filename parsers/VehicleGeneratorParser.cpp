// ===========================================================
// Name         : VehicleGeneratorParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `VehicleGenerator`.
// ===========================================================

#include "VehicleGeneratorParser.h"
#include "../objects/VehicleGenerator.h"

VehicleGeneratorParser::VehicleGeneratorParser() {
    fVehicleGenerator = new VehicleGenerator;
    VehicleGeneratorParser::_initCheck = this;
    ENSURE(properlyInitialized(), "VehicleGeneratorParser constructor did not end in an initialized state");
}

VehicleGeneratorParser::~VehicleGeneratorParser() {}

bool VehicleGeneratorParser::properlyInitialized() const {
    return VehicleGeneratorParser::_initCheck == this;
}

void VehicleGeneratorParser::parseVehicleGenerator(TiXmlElement *VOERTUIGGENERATOR) {
    REQUIRE(properlyInitialized(), "VehicleGeneratorParser wasn't initialized when calling parseVehicleGenerator()");

    TiXmlElement* baanElem = VOERTUIGGENERATOR->FirstChildElement("baan");
    TiXmlElement* frequencyElem = VOERTUIGGENERATOR->FirstChildElement("frequentie");
    if (baanElem == NULL && frequencyElem == NULL) {
        throw ParseException("The vehicle-generator has no contents.\nIt needs both a street and a frequency.");
    }
    if (baanElem == NULL) {
        throw ParseException("Vehicle-generator has no street.");
    }
    if (frequencyElem == NULL) {
        throw ParseException("Vehicle-generator has no frequency.");
    }

    if (baanElem->FirstChild() == NULL) {
        throw ParseException("Vehicle-generator street name is empty");
    }
    TiXmlText* streetText = baanElem->FirstChild()->ToText();
    std::string street = streetText->Value();

    if (frequencyElem->FirstChild() == NULL) {
        throw ParseException("Vehicle-generator frequency is empty");
    }
    TiXmlText* frequencyText = frequencyElem->FirstChild()->ToText();
    std::string positionString = frequencyText->Value();
    int frequency;
    if ((std::istringstream(positionString) >> frequency).fail()) {
        throw ParseException("Vehicle-generator frequency is not a number");
    }

    fVehicleGenerator->setStreet(street);
    fVehicleGenerator->setFrequency(frequency);

    ENSURE(fVehicleGenerator->getStreet() == street, "parseVehicleGenerator() postcondition");
    ENSURE(fVehicleGenerator->getFrequency() == frequency, "parseVehicleGenerator() postcondition");
}

VehicleGenerator *VehicleGeneratorParser::getVehicleGenerator() const {
    REQUIRE(properlyInitialized(), "VehicleGeneratorParser wasn't initialized when calling getVehicleGenerator()");
    return fVehicleGenerator;
}