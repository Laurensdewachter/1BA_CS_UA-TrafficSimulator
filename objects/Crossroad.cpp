#include "Crossroad.h"
#include "../DesignByContract.h"

Crossroad::Crossroad() {
    _initCheck = this;

    ENSURE(properlyInitialized(), "Crossroad constructor did not end in an initialized state");
}

Crossroad::~Crossroad() {}

bool Crossroad::properlyInitialized() const {
    return _initCheck == this;
}

const std::pair<Street *, unsigned int> &Crossroad::getStreet1() const {
    REQUIRE(properlyInitialized(), "Crossroad wasn't initialized when calling getStreet1()");

    return fStreet1;
}

const std::pair<Street *, unsigned int> &Crossroad::getStreet2() const {
    REQUIRE(properlyInitialized(), "Crossroad wasn't initialized when calling getStreet2()");

    return fStreet2;
}
