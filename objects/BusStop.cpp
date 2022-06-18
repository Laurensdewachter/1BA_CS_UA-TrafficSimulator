// ===========================================================
// Name         : BusStop.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `BusStop` class
// ===========================================================

#include "BusStop.h"
#include "../DesignByContract.h"

BusStop::BusStop(const std::string &street, int position, int waitTime) : fStreet(street), fPosition(position), fWaitTime(waitTime) {
    BusStop::_initCheck = this;

    ENSURE(properlyInitialized(), "BusStop constructor did not end in an initialized state");
}

BusStop::~BusStop() {}

bool BusStop::properlyInitialized() const {
    return BusStop::_initCheck == this;
}

const std::string &BusStop::getStreet() const {
    REQUIRE(properlyInitialized(), "BusStop wasn't initialized when calling getStreet()");

    return fStreet;
}

int BusStop::getPosition() const {
    REQUIRE(properlyInitialized(), "BusStop wasn't initialized when calling getPosition()");

    return fPosition;
}

int BusStop::getWaitTime() const {
    REQUIRE(properlyInitialized(), "BusStop wasn't initialized when calling getWaitTime()");

    return fWaitTime;
}

std::vector<Vehicle *> BusStop::getArrivedBusses() const {
    REQUIRE(properlyInitialized(), "BusStop wasn't initialized when calling getArrivedBusses()");

    return arrivedBusses;
}

void BusStop::addArrivedBus(Vehicle *bus) {
    REQUIRE(properlyInitialized(), "BusStop wasn't initialized when calling addArrivedBus()");

    unsigned int originalLength = arrivedBusses.size();
    arrivedBusses.push_back(bus);

    ENSURE(arrivedBusses.size() == originalLength + 1, "addArrivedBus() did not add a bus to the vector");
}
