// ===========================================================
// Name         : CrossroadParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains either a `Crossroad`.
// ===========================================================

#ifndef TRAFFICSIMULATION_CROSSROADPARSER_H
#define TRAFFICSIMULATION_CROSSROADPARSER_H

#include <iostream>
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
     *
     * REQUIRE(!fStreet1.first.empty(), "The first street is empty")
     * REQUIRE(!fStreet2.first.empty(), "The first street is empty")
     * REQUIRE(fStreet1.first == street1, "The first street is not the same as the first street in the XML")
     * REQUIRE(fStreet2.first == street2, "The second street is not the same as the second street in the XML")
     * REQUIRE(fStreet1.second == position1, "The first position is not the same as the first position in the XML")
     * REQUIRE(fStreet2.second == position2, "The second position is not the same as the second position in the XML")
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