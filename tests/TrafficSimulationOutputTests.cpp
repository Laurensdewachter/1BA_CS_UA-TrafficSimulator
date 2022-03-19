// ===========================================================
// Name         : TrafficSimulationOutputTests.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code tests the output of the TrafficSimulation.
// ===========================================================

#include "gtest/gtest.h"
#include "../TrafficSimulation.h"
#include "../Utils.h"

class TrafficSimulationOutputTest : public ::testing::Test {
protected:
    virtual void SetUp() {}

    virtual void TearDown() {}

    TrafficSimulation sim;
};

TEST_F(TrafficSimulationOutputTest, OutputHappyDay) {
    EXPECT_TRUE(sim.properlyInitialized());
    EXPECT_TRUE(DirectoryExists("testInput"));
    EXPECT_TRUE(DirectoryExists("testOutput"));

    std::ofstream myFile;
    myFile.open("testInput/HappyDayOut.xml");
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
           << "<VOERTUIG>" <<std::endl
           << "<baan>Middelheimlaan</baan >" << std::endl
           << "<positie>480</positie>" << std::endl
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

    std::fstream errStream;
    sim.parseInputFile("testInput/HappyDayOut.xml", errStream);

    EXPECT_TRUE(FileIsEmpty("testOutput/HappyDayOutErrors.txt"));

    myFile.open("testOutput/HappyDayOut1.txt");
    sim.writeOn(myFile);
    myFile.close();

    EXPECT_TRUE(FileCompare("testOutput/HappyDayOut1.txt", "testInput/expectedHappyDayOut1.txt"));

    for (unsigned int i = 0; i < 3000; i++) {
        sim.simulate();
    }

    myFile.open("testOutput/HappyDayOut2.txt");
    sim.writeOn(myFile);
    myFile.close();

    EXPECT_TRUE(FileCompare("testOutput/HappyDayOut2.txt", "testInput/expectedHappyDayOut2.txt"));

    sim.clearSimulation();
}

TEST_F(TrafficSimulationOutputTest, correctOutput) {
    EXPECT_TRUE(sim.properlyInitialized());
    EXPECT_TRUE(DirectoryExists("testInput"));
    EXPECT_TRUE(DirectoryExists("testOutput"));

    int fileCounter = 1;
    std::string filename = "testInput/legalSimulation" + ToString(fileCounter) + ".xml";

    std::string writeOutName = "testOutput/writeOut" + ToString(fileCounter) + ".txt";

    std::string compareFilename = "testInput/expectedWriteOut" + ToString(fileCounter) + ".txt";

    while (FileExists(filename)) {
        sim.parseInputFile(filename);

        std::ofstream myFile;
        myFile.open(writeOutName.c_str());
        sim.writeOn(myFile);
        myFile.close();

        EXPECT_TRUE(FileCompare(writeOutName, compareFilename));

        fileCounter++;
        filename = "testInput/legalSimulation" + ToString(fileCounter) + ".xml";
        writeOutName = "testOutput/writeOut" + ToString(fileCounter) + ".txt";
        compareFilename = "testInput/expectedWriteOut" + ToString(fileCounter) + ".txt";

        sim.clearSimulation();
    }
}