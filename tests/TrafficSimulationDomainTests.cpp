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
        double initialTime = sim.getTime();
        std::vector<Street*> streets = sim.getStreets();
        Vehicle* car0 = streets[0]->getVehicles()[0];
        Vehicle* car1 = streets[1]->getVehicles()[0];
        double initialLocationCar1 = car0->getPosition();
        double initialLocationCar2 = car1->getPosition();

        sim.simulate();

        EXPECT_TRUE(sim.getTime() > initialTime);
        if (&streets[0]->getVehicles()[0] == &car0) {
            EXPECT_TRUE(streets[0]->getVehicles()[0]->getPosition() > initialLocationCar1);
        }
        if (&streets[1]->getVehicles()[0] == &car1) {
            EXPECT_TRUE(streets[1]->getVehicles()[0]->getPosition() > initialLocationCar2);
        }
    }

    EXPECT_EQ(2000*gSimulationTime, sim.getTime());

    sim.clearSimulation();
    EXPECT_TRUE(sim.getStreets().empty());
}