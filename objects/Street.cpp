// ===========================================================
// Name         : Street.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Street` class
// ===========================================================

#include "Street.h"

Street::Street() {
    Street::_initCheck = this;
    ENSURE(properlyInitialized(), "Street constructor did not end in an initialized state");
}

Street::~Street() {}

bool Street::properlyInitialized() const {
    return Street::_initCheck == this;
}

void Street::setName(const std::string &n) {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling setName()");
    Street::fName = n;
    ENSURE(this->getName() == n, "setName() postcondition");
}

void Street::setLength(int l) {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling setLength()");
    Street::fLength = l;
    ENSURE(this->getLength() == l, "setLength() postcondition");
}

const std::string &Street::getName() const {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling getName()");
    return Street::fName;
}

int Street::getLength() const {
    REQUIRE(properlyInitialized(), "Street wasn't initialized when calling getLength()");
    return Street::fLength;
}
