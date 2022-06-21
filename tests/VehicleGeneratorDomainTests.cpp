// ===========================================================
// Name         : VehicleGeneratorDomainTests.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code tests the `VehicleGenerator` class of the TrafficSimulation.
// ===========================================================

#include "gtest/gtest.h"
#include "../objects/VehicleGenerator.h"

class VehicleGeneratorDomainTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        generator = new VehicleGenerator("Testbaan", 200, "auto");
    }

    virtual void TearDown() {
        delete generator;
    }

    VehicleGenerator* generator;
};

TEST_F(VehicleGeneratorDomainTest, Constructor) {
    EXPECT_EQ("Testbaan", generator->getStreet());
    EXPECT_EQ(200, generator->getFrequency());
    EXPECT_EQ("auto", generator->getType());
    EXPECT_EQ(0, generator->getTimeSinceLastSpawn());
    EXPECT_TRUE(generator->properlyInitialized());
}

TEST_F(VehicleGeneratorDomainTest, GeneratorTime) {
    generator->setTimeSinceLastSpawn(10);
    EXPECT_EQ(10, generator->getTimeSinceLastSpawn());
}

TEST_F(VehicleGeneratorDomainTest, ContractViolations) {
    // Test properlyInitialized condition
    VehicleGenerator illegalCopy = *generator;

    EXPECT_DEATH(illegalCopy.getStreet(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getFrequency(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getType(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getTimeSinceLastSpawn(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.setTimeSinceLastSpawn(10), "Assertion.*failed");

    // Test setTimeSinceLastSpawn() conditions
    EXPECT_DEATH(generator->setTimeSinceLastSpawn(-1), "Assertion.*failed");
}
