// ===========================================================
// Name         : StreetParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is used to parse an XML file that contains a `Street`.
// ===========================================================

#ifndef PSE_STREETPARSER_H
#define PSE_STREETPARSER_H

#include <iostream>
#include <sstream>
#include "tinyxml/tinyxml.h"
#include "../DesignByContract.h"

class Street;

class StreetParser {
    Street* fStreet;
    StreetParser* _initCheck;

public:
    /*
     * ENSURE(properlyInitialized(), "StreetParser constructor did not end in an initialized state")
     */
    StreetParser();

    virtual ~StreetParser();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "StreetParser wasn't initialized when calling parseStreet()")
     * REQUIRE(errStream.good(), "The errorStream wasn't good")
     * ENSURE(fStreet != NULL, "StreetParser could not create a Street")
     * ENSURE(fStreet->getName() == name, "parseStreet() postcondition")
     * ENSURE(fStreet->getLength() == length, "parseStreet() postcondition")
     */
    bool parseStreet(TiXmlElement* BAAN, std::ostream &errStream);

    /*
     * REQUIRE(properlyInitialized(), "StreetParser wasn't initialized when calling getStreet()")
     * REQUIRE(fStreet != NULL, "StreetParser had no street when calling getStreet()")
     */
    Street* getStreet() const;
};


#endif
