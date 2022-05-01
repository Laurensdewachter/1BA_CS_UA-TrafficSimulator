// ===========================================================
// Name         : Crossroad.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is contains the `Crossroad` class
// ===========================================================

#include "Crossroad.h"
#include "../DesignByContract.h"

Crossroad::Crossroad(const std::string &street, double position) : fStreet(street), fPosition(position){

    _initCheck = this;

    ENSURE(properlyInitialized(), "Crossroad constructor did not end in an initialized state");
}

Crossroad::~Crossroad() {}

bool Crossroad::properlyInitialized() const {
    return _initCheck == this;
}

const std::string &Crossroad::getStreet() const {
    REQUIRE(properlyInitialized(), "Crossroad wasn't initialized when calling getStreet()");

    return fStreet;
}

double Crossroad::getPosition() const {
    REQUIRE(properlyInitialized(), "Crossroad wasn't initialized when calling getPosition()");

    return fPosition;
}