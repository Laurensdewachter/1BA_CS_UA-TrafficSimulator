// ===========================================================
// Name         : TrafficSimulationInputTests.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code tests the parsers of the TrafficSimulation.
// ===========================================================

#include <fstream>
#include "gtest/gtest.h"
#include "../TrafficSimulation.h"
#include "../Utils.h"
#include "../parsers/ParseException.h"

class TrafficSimulationInputTest : public ::testing::Test {
protected:
    virtual void SetUp() {}

    virtual void TearDown() {}

    TrafficSimulation sim;
};

TEST_F(TrafficSimulationInputTest, InputHappyDay) {
    ASSERT_TRUE(sim.properlyInitialized());
    ASSERT_TRUE(DirectoryExists("testInput"));

    std::ofstream myFile;
    myFile.open("testInput/testHappyDay.xml");
    myFile << "<?xml version=\"1.0\" ?>" << std::endl
        << "<SIMULATIE>" << std::endl
        << "<BAAN>" << std::endl
        << "<naam>Middelheimlaan</naam>" << std::endl
        << "<lengte>500</lengte>" << std::endl
        << "</BAAN>" << std::endl
        << "<VOERTUIG>" << std::endl
        << "<baan>Middelheimlaan</baan>" << std::endl
        << "<positie>20</positie>" << std::endl
        << "</VOERTUIG>" << std::endl
        << "<VERKEERSLICHT>" << std::endl
        << "<baan>Middelheimlaan</baan>" << std::endl
        << "<positie>400</positie>" << std::endl
        << "<cyclus>20</cyclus>" << std::endl
        << "</VERKEERSLICHT>" << std::endl
        << "<VOERTUIGGENERATOR>" << std::endl
        << "<baan>Middelheimlaan</baan>" << std::endl
        << "<frequentie>5</frequentie>" << std::endl
        << "</VOERTUIGGENERATOR>" << std::endl
        << "</SIMULATIE>" << std::endl;
    myFile.close();

    try {
        sim.parseInputFile("testInput/testHappyDay.xml");
    }
    catch (ParseException &e) {
        FAIL();
    }
}

TEST_F(TrafficSimulationInputTest, InputLegalSimulations) {
    ASSERT_TRUE(sim.properlyInitialized());
    ASSERT_TRUE(DirectoryExists("testInput"));

    int fileCounter = 1;
    std::string fileName = "testInput/legalSimulation" + ToString(fileCounter) + ".xml";

    while (FileExists(fileName)) {
        try {
            sim.parseInputFile(fileName);
        }
        catch (std::exception &e) {
            FAIL();
        }

        fileCounter++;
        fileName = "testInput/legalSimulation" + ToString(fileCounter) + ".xml";
    }
}

TEST_F(TrafficSimulationInputTest, InputIllegalSimulations) {
    ASSERT_TRUE(sim.properlyInitialized());
    ASSERT_TRUE(DirectoryExists("testInput"));

    int fileCounter = 1;
    std::string fileName = "testInput/illegalSimulation" + ToString(fileCounter) + ".xml";

    while (FileExists(fileName)) {
        // https://stackoverflow.com/questions/23270078/test-a-specific-exception-type-is-thrown-and-the-exception-has-the-right-propert
        EXPECT_THROW({
             try {
                 sim.parseInputFile(fileName);
             }
             catch (ParseException &e) {
                 throw;
             }
        }, ParseException);

        fileCounter++;
        fileName = "testInput/illegalSimulation" + ToString(fileCounter) + ".xml";
    }
}

TEST_F(TrafficSimulationInputTest, InputException) {
    ASSERT_TRUE(sim.properlyInitialized());
    ASSERT_TRUE(DirectoryExists("testInput"));

    int fileCounter = 1;
    std::string fileName = "testInput/illegalSimulation" + ToString(fileCounter) + ".xml";

    EXPECT_THROW({
        try {
            sim.parseInputFile("testInput/illegalSimulation1.xml");
        }
        catch (ParseException &e) {
            EXPECT_STREQ("Street name is empty", e.what());
            throw;
        }
    }, ParseException);

    EXPECT_THROW({
         try {
             sim.parseInputFile("testInput/illegalSimulation2.xml");
         }
         catch (ParseException &e) {
             EXPECT_STREQ("Error reading Attributes.", e.what());
             throw;
         }
     }, ParseException);

    EXPECT_THROW({
         try {
             sim.parseInputFile("testInput/illegalSimulation3.xml");
         }
         catch (ParseException &e) {
             EXPECT_STREQ("Street length is not a number", e.what());
             throw;
         }
     }, ParseException);
}