// ===========================================================
// Name         : TrafficSimulationDomainTests.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code contains the domain tests for the traffic simulation
// ===========================================================

#include "gtest/gtest.h"
#include "../TrafficSimulation.h"
#include "../objects/Street.h"
#include "../objects/Vehicle.h"
#include "../Variables.h"
#include "../Utils.h"

class TrafficSimulationDomainTests : public ::testing::Test {
protected:
    virtual void SetUp() {}

    virtual void TearDown() {}

    TrafficSimulation sim;
};

TEST_F(TrafficSimulationDomainTests, HappyDay) {
    EXPECT_TRUE(sim.properlyInitialized());
    EXPECT_TRUE(DirectoryExists("testInput"));
    EXPECT_TRUE(DirectoryExists("testOutput"));

    std::ofstream errStream;
    errStream.open("testOutput/legalOut.txt");
    EParserSucces parserSucces = sim.parseInputFile("testInput/domainTest.xml", errStream);
    errStream.close();

    EXPECT_EQ(Success, parserSucces);
    EXPECT_TRUE(FileIsEmpty("testOutput/legalOut.txt"));

    for (int i = 0; i < 2000; i++) {

    }

    sim.clearSimulation();
    EXPECT_TRUE(sim.getStreets().empty());
}