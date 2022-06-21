// ===========================================================
// Name         : TrafficLightDomainTests.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code tests the `TrafficLight` class of the TrafficSimulation.
// ===========================================================

#include "gtest/gtest.h"
#include "../objects/TrafficLight.h"

class TrafficLightDomainTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        light = new TrafficLight("Testbaan", 200, 10);
    }

    virtual void TearDown() {
        delete light;
    }

    TrafficLight* light;
};

TEST_F(TrafficLightDomainTest, Constructor) {
    EXPECT_EQ("Testbaan", light->getStreet());
    EXPECT_EQ(200, light->getPosition());
    EXPECT_EQ(10, light->getCycle());
    EXPECT_EQ(0, light->getLastUpdateTime());
    EXPECT_TRUE(light->isGreen());
    EXPECT_TRUE(light->properlyInitialized());
}

TEST_F(TrafficLightDomainTest, ChangeLight) {
    light->changeLight();
    EXPECT_FALSE(light->isGreen());
}

TEST_F(TrafficLightDomainTest, ChangeLastUpdatedTime) {
    light->setLastUpdateTime(15.00);
    EXPECT_EQ(15.00, light->getLastUpdateTime());
}

TEST_F(TrafficLightDomainTest, ContractViolations) {
    // Test properlyInitialized condition
    TrafficLight illegalCopy = *light;

    EXPECT_DEATH(illegalCopy.getStreet(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getPosition(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getCycle(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.isGreen(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getLastUpdateTime(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.changeLight(), "Assertion.*failed");

    // Test setLastUpdateTime() conditions
    EXPECT_DEATH(light->setLastUpdateTime(-1), "Assertion.*failed");
}
