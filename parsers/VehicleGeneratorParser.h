// ===========================================================
// Name         : VehicleGeneratorParser.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is used to parse an XML file that contains a `VehicleGenerator`.
// ===========================================================

#ifndef PSE_VEHICLEGENERATORPARSER_H
#define PSE_VEHICLEGENERATORPARSER_H

#include <iostream>
#include <sstream>
#include "ParseException.h"
#include "tinyxml/tinyxml.h"

class VehicleGenerator;

class VehicleGeneratorParser {
    VehicleGenerator* vehicleGenerator;

public:
    VehicleGeneratorParser();
    virtual ~VehicleGeneratorParser();

    void parseVehicleGenerator(TiXmlElement* VOERTUIGGENERATOR);
    VehicleGenerator* getVehicleGenerator() const;
};


#endif
