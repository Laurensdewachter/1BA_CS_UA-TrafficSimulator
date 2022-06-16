// ===========================================================
// Name         : BusStopParser.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `BusStop`.
// ===========================================================

#include <sstream>
#include "BusStopParser.h"
#include "../DesignByContract.h"
#include "../objects/BusStop.h"

BusStopParser::BusStopParser() {
    BusStopParser::_initCheck = this;

    ENSURE(properlyInitialized(), "BusStopParser constructor did not end in an initialized state");
}

BusStopParser::~BusStopParser() {}

bool BusStopParser::properlyInitialized() const {
    return BusStopParser::_initCheck == this;
}

bool BusStopParser::parseBusStop(TiXmlElement *BUSHALTE, std::ostream &errStream) {
    REQUIRE(properlyInitialized(), "BusStopParser wasn't initialized when calling parseBusStop()");
    REQUIRE(errStream.good(), "The errorStream wasn't good at the beginning of parseBusStop()");

    TiXmlElement* streetElem = BUSHALTE->FirstChildElement("baan");
    TiXmlElement* positionElem = BUSHALTE->FirstChildElement("positie");
    TiXmlElement* waitTimeElem = BUSHALTE->FirstChildElement("wachttijd");

    std::string street;
    int position;
    int waitTime;

    bool wrongTypes = false;
    bool missingElements = false;
    if (streetElem == NULL || streetElem->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <baan> ... </baan>." << std::endl;
        missingElements = true;
    } else {
        TiXmlText* streetText = streetElem->FirstChild()->ToText();
        street = streetText->Value();
    }
    if (positionElem == NULL || positionElem->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <positie> .. </positie>." << std::endl;
        missingElements = true;
    } else {
        std::string positionString = positionElem->FirstChild()->ToText()->Value();
        if ((std::istringstream(positionString) >> position).fail()) {
            errStream << "XML PARTIAL IMPORT: Expected <positie> to be an integer." << std::endl;
            wrongTypes = true;
        }
    }
    if (waitTimeElem == NULL || waitTimeElem->FirstChild() == NULL) {
        errStream << "XML PARTIAL IMPORT: Expected <wachttijd> .. </wachttijd>." << std::endl;
        missingElements = true;
    } else {
        std::string waitTimeString = waitTimeElem->FirstChild()->ToText()->Value();
        if ((std::istringstream(waitTimeString) >> waitTime).fail()) {
            errStream << "XML PARTIAL IMPORT: Expected <wachttijd> to be an integer." << std::endl;
            wrongTypes = true;
        }
    }

    if (missingElements || wrongTypes) {
        return false;
    }

    fBusStop = new BusStop(street, position, waitTime);

    ENSURE(fBusStop != NULL, "BusStopParser could not create a BusStop");
    ENSURE(fBusStop->getStreet() == street, "parseBusStop() postcondition");
    ENSURE(fBusStop->getPosition() == position, "parseBusStop() postcondition");
    ENSURE(fBusStop->getWaitTime() == waitTime, "parseBusStop() postcondition");

    ENSURE(errStream.good(), "The errorStream wasn't good at the end of parseBusStop()");

    return true;
}

BusStop* BusStopParser::getBusStop() const {
    REQUIRE(properlyInitialized(), "BusStopParser wasn't initialized when calling getBusStop()");
    REQUIRE(fBusStop != NULL, "BusStopParser had no bus stop when calling getBusStop()");

    return fBusStop;
}
