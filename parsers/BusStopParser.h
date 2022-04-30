// ===========================================================
// Name         : BusStopParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `BusStop`.
// ===========================================================

#ifndef TRAFFICSIMULATION_BUSSTOPPARSER_H
#define TRAFFICSIMULATION_BUSSTOPPARSER_H

#include <iostream>
#include <sstream>
#include "tinyxml/tinyxml.h"
#include "../DesignByContract.h"

class BusStop;

class BusStopParser {
    BusStopParser* _initCheck;

    BusStop* fBusStop;

public:
    /*
     * ENSURE(properlyInitialized(), "BusStopParser constructor did not end in an initialized state")
     */
    BusStopParser();

    virtual ~BusStopParser();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "BusStopParser wasn't initialized when calling parseBusStop()")
     * REQUIRE(errStream.good(), "The errorStream wasn't good")
     * ENSURE(fBusStop != NULL, "BusStopParser could not create a BusStop");
     * ENSURE(fBusStop->getStreet() == street, "parseBusStop() postcondition");
     * ENSURE(fBusStop->getPosition() == position, "parseBusStop() postcondition");
     * ENSURE(fBusStop->getWaitTime() == waitTime, "parseBusStop() postcondition");
     */
    bool parseBusStop(TiXmlElement* BUSHALTE, std::ostream &errStream);

    /*
     * REQUIRE(properlyInitialized(), "BusStopParser wasn't initialized when calling getBusStop()")
     * REQUIRE(fBusStop != NULL, "BusStopParser had no bus stop when calling getBusStop()")
     */
    BusStop* getBusStop() const;
};


#endif