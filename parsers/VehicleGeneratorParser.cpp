// ===========================================================
// Name         : VehicleGeneratorParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `VehicleGenerator`.
// ===========================================================

#include "VehicleGeneratorParser.h"
#include "../objects/VehicleGenerator.h"

VehicleGeneratorParser::VehicleGeneratorParser() {
    vehicleGenerator = new VehicleGenerator;
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
        throw ParseException("The fVehicle-generator has no contents.\nIt needs both a fStreet and a fFrequency.");
    }
    if (baanElem == NULL) {
        throw ParseException("The fVehicle-generator has no fStreet.");
    }
    if (frequencyElem == NULL) {
        throw ParseException("The fVehicle-generator has no fFrequency.");
    }

    if (baanElem->FirstChild() == NULL) {
        throw ParseException("The fVehicle-generators fStreet name is empty");
    }
    TiXmlText* streetText = baanElem->FirstChild()->ToText();
    std::string street = streetText->Value();

    if (frequencyElem->FirstChild() == NULL) {
        throw ParseException("The fVehicle-generators fFrequency is empty");
    }
    TiXmlText* frequencyText = frequencyElem->FirstChild()->ToText();
    std::string positionString = frequencyText->Value();
    int frequency;
    std::istringstream(positionString) >> frequency;

    vehicleGenerator->setStreet(street);
    vehicleGenerator->setFrequency(frequency);

    ENSURE(vehicleGenerator->getStreet() == street, "parseVehicleGenerator() postcondition");
    ENSURE(vehicleGenerator->getFrequency() == frequency, "parseVehicleGenerator() postcondition");
}

VehicleGenerator *VehicleGeneratorParser::getVehicleGenerator() const {
    REQUIRE(properlyInitialized(), "VehicleGeneratorParser wasn't initialized when calling getVehicleGenerator()");
    return vehicleGenerator;
}