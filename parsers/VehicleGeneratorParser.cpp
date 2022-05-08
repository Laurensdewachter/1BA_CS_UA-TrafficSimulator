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
    TiXmlElement* typeElem = VOERTUIGGENERATOR->FirstChildElement("type");

    std::string street;
    int frequency;
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
    if (typeElem == NULL || typeElem->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <type> ... </type>." << std::endl;
        missingElements = true;
    } else {
        TiXmlText* typeText = typeElem->FirstChild()->ToText();
        type = typeText->Value();
        if (type != "auto" && type != "bus" && type != "brandweerwagen" && type != "ziekenwagen" && type != "politiecombi") {
            errStream << "XML PARTIAL IMPORT: Expected <type> to be one of the following: auto, bus, brandweerwagen, ziekenwagen, politiecombi." << std::endl;
            return false;
        }
    }

    if (missingElements || wrongTypes) {
        return false;
    }

    fVehicleGenerator = new VehicleGenerator(street, frequency, type);
    fVehicleGenerator->setStreet(street);
    fVehicleGenerator->setFrequency(frequency);

    ENSURE(fVehicleGenerator != NULL, "VehicleGeneratorParser could not create a VehicleGenerator");
    ENSURE(fVehicleGenerator->getStreet() == street, "parseVehicleGenerator() postcondition");
    ENSURE(fVehicleGenerator->getFrequency() == frequency, "parseVehicleGenerator() postcondition");

    return true;
}

VehicleGenerator *VehicleGeneratorParser::getVehicleGenerator() const {
    REQUIRE(properlyInitialized(), "VehicleGeneratorParser wasn't initialized when calling getVehicleGenerator()");
    REQUIRE(fVehicleGenerator != NULL, "VehicleGeneratorParser had no vehicle generator when calling getVehicleGenerator()");
    return fVehicleGenerator;
}