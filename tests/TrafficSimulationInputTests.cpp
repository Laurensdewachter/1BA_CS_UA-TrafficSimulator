// ===========================================================
// Name         : TrafficSimulationInputTests.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code tests the parsers of the TrafficSimulation.
// ===========================================================

#include "gtest/gtest.h"
#include "../TrafficSimulation.h"
#include "../Utils.h"

class TrafficSimulationInputTest : public ::testing::Test {
protected:
    virtual void SetUp() {}

    virtual void TearDown() {}

    TrafficSimulation sim;
};

TEST_F(TrafficSimulationInputTest, InputHappyDay) {
    EXPECT_TRUE(sim.properlyInitialized());
    EXPECT_TRUE(DirectoryExists("testInput"));
    EXPECT_TRUE(DirectoryExists("testOutput"));

    std::ofstream myFile;
    myFile.open("testInput/HappyDayIn.xml");
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

    std::ofstream errStream;
    errStream.open("testOutput/HappyDayInErrors.txt");
    EParserSucces parserSucces = sim.parseInputFile("testInput/HappyDayIn.xml", errStream);
    errStream.close();

    EXPECT_TRUE(parserSucces == Success);

    EXPECT_TRUE(FileIsEmpty("testOutput/HappyDayInErrors.txt"));

    sim.clearSimulation();
}

TEST_F(TrafficSimulationInputTest, InputLegalSimulations) {
    EXPECT_TRUE(sim.properlyInitialized());
    EXPECT_TRUE(DirectoryExists("testInput"));
    EXPECT_TRUE(DirectoryExists("testOutput"));

    int fileCounter = 1;
    std::string fileName = "testInput/legalSimulation" + ToString(fileCounter) + ".xml";

    std::ofstream errStream;

    while (FileExists(fileName)) {
        errStream.open("testOutput/legalOut.txt");
        EParserSucces parserSucces = sim.parseInputFile(fileName, errStream);
        errStream.close();

        EXPECT_TRUE(parserSucces == Success);

        ASSERT_TRUE(FileIsEmpty("testOutput/legalOut.txt"));

        fileCounter++;
        fileName = "testInput/legalSimulation" + ToString(fileCounter) + ".xml";

        sim.clearSimulation();
    }
}


TEST_F(TrafficSimulationInputTest, InputXMLSyntaxErrors) {
    EXPECT_TRUE(sim.properlyInitialized());
    EXPECT_TRUE(DirectoryExists("testInput"));
    ASSERT_TRUE(DirectoryExists("testOutput"));

    int fileCounter = 1;
    std::string filename = "testInput/syntaxError" + ToString(fileCounter) + ".xml";

    std::ofstream errStream;
    std::string errStreamName = "testOutput/syntaxError" + ToString(fileCounter) + ".txt";

    std::string compareFilename = "testInput/syntaxError" + ToString(fileCounter) + ".txt";

    while (FileExists(filename)) {
        errStream.open(errStreamName.c_str());
        EParserSucces parserSucces = sim.parseInputFile(filename, errStream);
        errStream.close();

        EXPECT_FALSE(parserSucces == Success);

        EXPECT_TRUE(FileCompare(errStreamName, compareFilename));

        fileCounter++;
        filename = "testInput/syntaxError" + ToString(fileCounter) + ".xml";
        errStreamName = "testOutput/syntaxError" + ToString(fileCounter) + ".txt";
        compareFilename = "testInput/syntaxError" + ToString(fileCounter) + ".txt";

        sim.clearSimulation();
    }
}

TEST_F(TrafficSimulationInputTest, InputConsistencyErrors) {
    EXPECT_TRUE(sim.properlyInitialized());
    EXPECT_TRUE(DirectoryExists("testInput"));
    ASSERT_TRUE(DirectoryExists("testOutput"));

    int fileCounter = 1;
    std::string filename = "testInput/consistencyError" + ToString(fileCounter) + ".xml";

    std::ofstream errStream;
    std::string errStreamName = "testOutput/consistencyError" + ToString(fileCounter) + ".txt";

    while (FileExists(filename)) {
        errStream.open(errStreamName.c_str());
        EParserSucces parserSucces = sim.parseInputFile(filename, errStream);
        errStream.close();

        EXPECT_FALSE(parserSucces == Success);

        EXPECT_TRUE(FileCompare(errStreamName, "testInput/consistencyError.txt"));

        fileCounter++;
        filename = "testInput/consistencyError" + ToString(fileCounter) + ".xml";
        errStreamName = "testOutput/consistencyError" + ToString(fileCounter) + ".txt";

        sim.clearSimulation();
    }
}