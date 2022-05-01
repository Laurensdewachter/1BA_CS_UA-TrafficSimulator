//
// Created by sunaj on 28/04/22.
//

#ifndef TRAFFICSIMULATION_CROSSROADPARSER_H
#define TRAFFICSIMULATION_CROSSROADPARSER_H

#include <iostream>
#include "tinyxml/tinyxml.h"
#include <sstream>

class Crossroad;

class CrossroadParser {
    CrossroadParser* _initCheck;
    Crossroad* fCrossroad;

public:
    /*
     * ENSURE(properlyInitialized(), "CrossroadParser constructor did not end in an initialized state")
     */
    CrossroadParser();

    virtual ~CrossroadParser();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "CrossroadParser wasn't initialized when calling parseCrossroad()")
     * REQUIRE(errStream.good(), "The errorStream wasn't good")
     * ENSURE(fCrossroad != NULL, "CrossroadParser could not create a Crossroad")
     * ENSURE(fCrossroad->getStreets() == fStreets, "parseCrossroad() postcondition")
     */
    bool parseCrossroad(TiXmlElement* KRUISPUNT, std::ostream &errStream);

    /*
    * REQUIRE(properlyInitialized(), "CrossroadParser wasn't initialized when calling getCrossroad()")
    * REQUIRE(fCrossroad != NULL, "CrossroadParser had no crossroad when calling getCrossroad()")
    */
    Crossroad *getCrossroad() const;
};


#endif //TRAFFICSIMULATION_CROSSROADPARSER_H
