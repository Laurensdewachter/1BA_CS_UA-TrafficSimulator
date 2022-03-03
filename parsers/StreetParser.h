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
#include "tinyxml/tinyxml.h"
#include "ParseException.h"

class Street;

class StreetParser {
    Street* street;

public:
    StreetParser();
    virtual ~StreetParser();

    void parseStreet(TiXmlElement* BAAN);
    Street* getStreet() const;
};


#endif //PSE_STREETPARSER_H
