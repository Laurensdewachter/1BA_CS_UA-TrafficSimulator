// ===========================================================
// Name         : StreetParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `Street`.
// ===========================================================

#ifndef PSE_STREETPARSER_H
#define PSE_STREETPARSER_H

#include <iostream>
#include <sstream>
#include "ParseException.h"
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
     * ENSURE(fStreet->getName() == name, "parseStreet() postcondition")
     * ENSURE(fStreet->getLength() == length, "parseStreet() postcondition")
     */
    void parseStreet(TiXmlElement* BAAN);

    /*
     * REQUIRE(properlyInitialized(), "StreetParser wasn't initialized when calling getStreet()")
     */
    Street* getStreet() const;
};


#endif
