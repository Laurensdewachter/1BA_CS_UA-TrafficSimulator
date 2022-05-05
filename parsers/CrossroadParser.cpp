// ===========================================================
// Name         : CrossroadParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.2
// Description  : This code is used to parse an XML file that contains either a `Crossroad`.
// ===========================================================


#include "CrossroadParser.h"
#include "../DesignByContract.h"
#include "../parsers/ElementParser.h"
#include "../objects/Street.h"

CrossroadParser::CrossroadParser() {
    CrossroadParser::_initCheck = this;
    ENSURE(properlyInitialized(), "CrossroadParser constructor did not end in an initialized state");
}

CrossroadParser::~CrossroadParser() {}

bool CrossroadParser::properlyInitialized() const {
    return CrossroadParser::_initCheck == this;
}

bool CrossroadParser::parseCrossroad(TiXmlElement *KRUISPUNT, std::ostream &errStream, ElementParser* streets) {
    REQUIRE(properlyInitialized(), "CrossroadParser wasn't initialized when calling parseCrossroad()");
    REQUIRE(errStream.good(), "The errorStream wasn't good");

    TiXmlElement* baanElem1 = KRUISPUNT->FirstChildElement("baan");



    std::string firstStreet;
    int firstPosition;
    std::string secondStreet;
    int secondPosition;

    bool wrongTypes = false;
    bool missingElements = false;

    if (baanElem1 == NULL || baanElem1->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <baan positie=\"\"> ... </baan>." << std::endl;
        missingElements = true;
    } else {
        TiXmlText* streetText = baanElem1->FirstChild()->ToText();
        firstStreet = streetText->Value();
    }
    if (missingElements) {
        return false;
    }

    TiXmlAttribute* positionElem1 = KRUISPUNT->FirstChildElement("baan")->FirstAttribute();
    if (positionElem1 == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <baan positie = '...' ></baan>" << std::endl;
        missingElements = true;
    } else {
        std::string positionString = positionElem1->Value();
        if(!isDigits(positionString)){
            errStream << "XML PARTIAL IMPORT: Expected <positie> to be an integer." << std::endl;
            wrongTypes = true;
        }else{
            std::istringstream(positionString) >> firstPosition;
        }
    }
    if (missingElements || wrongTypes) {
        return false;
    }

    TiXmlElement* baanElem2 = KRUISPUNT->FirstChildElement("baan")->NextSiblingElement("baan");
    if (baanElem2 == NULL || baanElem2->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <baan positie=\"\"> ... </baan>." << std::endl;
        missingElements = true;
    } else {
        TiXmlText* streetText = baanElem2->FirstChild()->ToText();
        secondStreet = streetText->Value();
    }
    if (missingElements) {
        return false;
    }

    TiXmlAttribute* positionElem2 = KRUISPUNT->FirstChildElement("baan")->NextSiblingElement()->FirstAttribute();
    if (positionElem2 == NULL ) {
        errStream << "XML PARTIAL IMPORT: Expected <baan positie = '...' ></baan>" << std::endl;
        missingElements = true;
    } else {
        std::string positionString = positionElem2->Value();
        if(!isDigits(positionString)){
            errStream << "XML PARTIAL IMPORT: Expected <positie> to be an integer." << std::endl;
            wrongTypes = true;
        }else{
            std::istringstream(positionString) >> secondPosition;
        }
    }
    if (missingElements || wrongTypes) {
        return false;
    }

//    std::cout << "__ Kruispunt __" <<std::endl;
//    std::cout << "Baan : " << firstStreet << " -> Positie: " << firstPosition << std::endl;
//    std::cout << "Baan : " << secondStreet << " -> Positie: " << secondPosition << std::endl;
//    std::cout << std::endl;


    bool exists1 = false; bool exists2 = false;
    Street* street1; Street* street2;

    for(unsigned int i = 0; i< streets->getStreets().size(); i++){

        if (firstStreet == streets->getStreets()[i]->getName()){
            street1 = streets->getStreets()[i];
            exists1 = true;
        }

        if (secondStreet == streets->getStreets()[i]->getName()){
            street2 = streets->getStreets()[i];
            exists2 = true;
        }
    }

    bool missing = false;

    if(!exists1 || !exists2){
        errStream << "XML PARTIAL IMPORT: Street not found" << std::endl;
        missing = true;
    }
    if(firstPosition > street1->getLength()){
        errStream << "XML PARTIAL IMPORT: Crossing position of first street is higher than the length" << std::endl;
        missing = true;
    }
    if(secondPosition > street2->getLength()){
        errStream << "XML PARTIAL IMPORT: Crossing position of second street is higher than the length" << std::endl;
        missing = true;
    }

    if (!missing){
        street1->addCrossroad(secondPosition,street2);
        street2->addCrossroad(firstPosition,street1);
    }



    //ENSURE(fCrossroad != NULL, "CrossroadParser could not create a Crossroad");
    //ENSURE(fCrossroad->getCrossroads() == firstStreet, "parseCrossroad() postcondition");
    //ENSURE(fCrossroad->getPosition() == firstPosition, "parseCrossroad() postcondition");
    //ENSURE(fCrossroad->getStreet() == secondStreet, "parseCrossroad() postcondition");
    //ENSURE(fCrossroad->getPosition() == secondPosition, "parseCrossroad() postcondition");

    return true;
}

bool CrossroadParser::isDigits(std::string &input) const {
    return input.find_first_not_of("0123456789") == std::string::npos;
}