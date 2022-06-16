// ===========================================================
// Name         : BusStopParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `BusStop`.
// ===========================================================

#ifndef TRAFFICSIMULATION_BUSSTOPPARSER_H
#define TRAFFICSIMULATION_BUSSTOPPARSER_H

#include <fstream>
#include "tinyxml/tinyxml.h"

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
     * REQUIRE(errStream.good(), "The errorStream wasn't good at the beginning of parseBusStop()")
     *
     * ENSURE(fBusStop != NULL, "BusStopParser could not create a BusStop");
     * ENSURE(fBusStop->getStreet() == street, "parseBusStop() postcondition");
     * ENSURE(fBusStop->getPosition() == position, "parseBusStop() postcondition");
     * ENSURE(fBusStop->getWaitTime() == waitTime, "parseBusStop() postcondition");
     * ENSURE(errStream.good(), "The errorStream wasn't good at the end of parseBusStop()");
     */
    bool parseBusStop(TiXmlElement* BUSHALTE, std::ostream &errStream);

    /*
     * REQUIRE(properlyInitialized(), "BusStopParser wasn't initialized when calling getBusStop()")
     * REQUIRE(fBusStop != NULL, "BusStopParser had no bus stop when calling getBusStop()")
     */
    BusStop* getBusStop() const;
};


#endif