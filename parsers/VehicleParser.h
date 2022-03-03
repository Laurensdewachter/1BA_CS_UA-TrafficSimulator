// ===========================================================
// Name         : VehicleParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `Vehicle`.
// ===========================================================

#ifndef PSE_VEHICLEPARSER_H
#define PSE_VEHICLEPARSER_H

#include <iostream>
#include <sstream>
#include "ParseException.h"
#include "tinyxml/tinyxml.h"

class Vehicle;

class VehicleParser {
    Vehicle* vehicle;

public:
    VehicleParser();
    virtual ~VehicleParser();

    void parseVehicle(TiXmlElement* VOERTUIG);

    Vehicle *getVehicle() const;
};


#endif //PSE_VEHICLEPARSER_H
