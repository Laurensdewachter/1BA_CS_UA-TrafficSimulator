// ===========================================================
// Name         : Crossroad.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Crossroad` class
// ===========================================================

#include "Crossroad.h"
#include "../DesignByContract.h"

Crossroad::Crossroad() {
    Crossroad::_initCheck = this;

    ENSURE(properlyInitialized(), "Crossroad constructor did not end in an initialized state");
}

Crossroad::~Crossroad() {}

bool Crossroad::properlyInitialized() const {
    return Crossroad::_initCheck == this;
}

const std::pair<Street *, unsigned int> &Crossroad::getStreet1() const {
    REQUIRE(properlyInitialized(), "Crossroad wasn't initialized when calling getStreet1()");

    return fStreet1;
}

const std::pair<Street *, unsigned int> &Crossroad::getStreet2() const {
    REQUIRE(properlyInitialized(), "Crossroad wasn't initialized when calling getStreet2()");

    return fStreet2;
}
