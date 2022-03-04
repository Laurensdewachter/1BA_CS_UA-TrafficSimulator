// ===========================================================
// Name         : Street.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Street` class
// ===========================================================

#include "Street.h"

Street::Street() {
    Street::_initCheck = this;
    ENSURE(Street::properlyInitialized(), "Street constructor dit not end in a initialized state.");
}

Street::~Street() {}

bool Street::properlyInitialized() const {
    return Street::_initCheck == this;
}

void Street::setName(const std::string &n) {
    REQUIRE(Street::properlyInitialized(), "Street wasn't initialized when calling `setName()`.");
    Street::name = n;
    ENSURE(Street::name == n, "`setName()` postcondition failed.");
}

void Street::setLength(int l) {
    REQUIRE(Street::properlyInitialized(), "Street wasn't initialized when calling `setLength()`.");
    Street::length = l;
    ENSURE(Street::length == l, "`setLength()` postcondition failed.");
}

const std::string &Street::getName() const {
    REQUIRE(Street::properlyInitialized(), "Street wasn't initialized when calling `getName()`.");
    return Street::name;
}

int Street::getLength() const {
    REQUIRE(Street::properlyInitialized(), "Street wasn't initialized when calling `getLength()`.");
    return Street::length;
}
