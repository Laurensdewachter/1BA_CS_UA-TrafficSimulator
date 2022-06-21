// ===========================================================
// Name         : BusStopDomainTests.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code tests the `BusStop` class of the TrafficSimulation.
// ===========================================================

#include "gtest/gtest.h"
#include "../objects/BusStop.h"
#include "../objects/vehicles/Bus.h"

class BusStopDomainTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        stop = new BusStop("street", 10, 30);
    }

    virtual void TearDown() {
        delete stop;
    }

    BusStop* stop;
};

TEST_F(BusStopDomainTest, Constructor) {
    EXPECT_EQ(stop->getStreet(), "street");
    EXPECT_EQ(stop->getPosition(), 10);
    EXPECT_EQ(stop->getWaitTime(), 30);
    EXPECT_TRUE(stop->getArrivedBusses().empty());
    EXPECT_TRUE(stop->properlyInitialized());
}

TEST_F(BusStopDomainTest, HappyDay) {
    Bus* bus = new Bus("street", 30);

    stop->addArrivedBus(bus);
    long unsigned int expectedSize = 1;
    EXPECT_EQ(stop->getArrivedBusses().size(), expectedSize);
}

TEST_F(BusStopDomainTest, ContractViolations) {
    BusStop illegalCopy = *stop;
    Bus* bus = new Bus("street", 30);

    EXPECT_DEATH(illegalCopy.getStreet(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getPosition(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getWaitTime(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getArrivedBusses(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.addArrivedBus(bus), "Assertion.*failed");
}