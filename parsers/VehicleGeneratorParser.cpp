// ===========================================================
// Name         : VehicleGeneratorParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is used to parse an XML file that contains a `VehicleGenerator`.
// ===========================================================

#include "VehicleGeneratorParser.h"
#include "../objects/VehicleGenerator.h"

VehicleGeneratorParser::VehicleGeneratorParser() {
    VehicleGeneratorParser::_initCheck = this;
    ENSURE(properlyInitialized(), "VehicleGeneratorParser constructor did not end in an initialized state");
}

VehicleGeneratorParser::~VehicleGeneratorParser() {}

bool VehicleGeneratorParser::properlyInitialized() const {
    return VehicleGeneratorParser::_initCheck == this;
}

bool VehicleGeneratorParser::parseVehicleGenerator(TiXmlElement *VOERTUIGGENERATOR, std::ostream &errStream) {
    REQUIRE(properlyInitialized(), "VehicleGeneratorParser wasn't initialized when calling parseVehicleGenerator()");
    REQUIRE(errStream.good(), "The errorStream wasn't good");

    TiXmlElement* baanElem = VOERTUIGGENERATOR->FirstChildElement("baan");
    TiXmlElement* frequencyElem = VOERTUIGGENERATOR->FirstChildElement("frequentie");

    std::string street;
    int frequency;

    bool wrongTypes = false;
    bool missingElements = false;
    if (baanElem == NULL || baanElem->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <baan> .. </baan>." << std::endl;
        missingElements = true;
    } else {
        TiXmlText* streetText = baanElem->FirstChild()->ToText();
        street = streetText->Value();
    }
    if (frequencyElem == NULL || frequencyElem->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <frequentie> ... </frequentie>." << std::endl;
        missingElements = true;
    } else {
        std::string positionString = frequencyElem->FirstChild()->ToText()->Value();
        if ((std::istringstream(positionString) >> frequency).fail()) {
            errStream << "XML PARTIAL IMPORT: Expected <frequentie> to be an integer." << std::endl;
            wrongTypes = true;
        }
    }

    if (missingElements || wrongTypes) {
        return false;
    }

    fVehicleGenerator = new VehicleGenerator();
    fVehicleGenerator->setStreet(street);
    fVehicleGenerator->setFrequency(frequency);

    ENSURE(fVehicleGenerator->getStreet() == street, "parseVehicleGenerator() postcondition");
    ENSURE(fVehicleGenerator->getFrequency() == frequency, "parseVehicleGenerator() postcondition");

    return true;
}

VehicleGenerator *VehicleGeneratorParser::getVehicleGenerator() const {
    REQUIRE(properlyInitialized(), "VehicleGeneratorParser wasn't initialized when calling getVehicleGenerator()");
    REQUIRE(fVehicleGenerator != NULL, "VehicleGeneratorParser had no vehicle generator when calling getVehicleGenerator()");
    return fVehicleGenerator;
}