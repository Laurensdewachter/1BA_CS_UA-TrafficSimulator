// ===========================================================
// Name         : CrossroadParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains either a `Crossroad`.
// ===========================================================

#ifndef TRAFFICSIMULATION_CROSSROADPARSER_H
#define TRAFFICSIMULATION_CROSSROADPARSER_H

#include <iostream>
#include <map>
#include "tinyxml/tinyxml.h"

class Street;
class ElementParser;

class CrossroadParser {
    CrossroadParser* _initCheck;

    std::pair<std::string, unsigned int> fStreet1;
    std::pair<std::string, unsigned int> fStreet2;

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
     */
    bool parseCrossroad(TiXmlElement* KRUISPUNT, std::ostream &errStream);

    /*
     * REQUIRE(properlyInitialized(), "CrossroadParser wasn't initialized when calling getStreet1()")
     */
    const std::pair<std::string, unsigned int> &getStreet1() const;

    /*
     * REQUIRE(properlyInitialized(), "CrossroadParser wasn't initialized when calling getStreet2()")
     */
    const std::pair<std::string, unsigned int> &getStreet2() const;
};

#endif
