#include <iostream>
#include <sstream>
#include "Utils.h"
#include "TrafficSimulation.h"

int main(int argc, char** argv) {
    int retValue = 0;

    if (argc < 2) {
        std::cout << "No arguments given." << std::endl
        << "Use -h or --help to get an overview of all available options." << std::endl;
        retValue = -1;
    }
    else {
        std::vector<std::string> args = std::vector<std::string>(argv+1, argv+argc);
        std::string fileName = "noFile";
        int repetitions = -1;
        for (long unsigned int i = 0; i < args.size(); i++) {
            if (args[i] == "-h" || args[i] == "--help") {
                std::cout << "Usage: ./TrafficSimulation [-h] [-f FILENAME] [-r REPETITIONS]" << std::endl << std::endl
                << "This program runs a traffic simulation based on a given xml-file" << std::endl <<std::endl
                << "Required arguments:" << std::endl
                << "\t-f FILENAME\t\t\tthe xml-file that contains the simulation specifications" << std::endl
                << "\t-r REPETITIONS\t\tthe amount of times the simulation should be run" <<std::endl <<std::endl
                << "Optional arguments:" << std::endl
                << "-h, --help\t\t\tshow this help message and exit" << std::endl;
                break;
            } else {
                if (args[i] == "-f") {
                    fileName = args[i+1];
                    i++;
                    continue;
                    }
                if (args[i] == "-r") {
                    std::string repetitionsString = args[i+1];
                    std::istringstream(repetitionsString) >> repetitions;
                    if (repetitions < 1) {
                        std::cout << "the amount of repetitions must be greater than 0" << std::endl;
                        repetitions = -1;
                    }
                    i++;
                    continue;
                }
            }
        }
        TrafficSimulation sim;
        if (fileName != "noFile" && repetitions != -1) {
            sim.parseInputFile(fileName);

            for (int i = 0; i < repetitions; i++) {
                sim.simulate();
                //sim.visualize();
                //sim.writeOn();
            }
        } else {
            std::cout << "both a file and the amount of repetitions must be given" <<std::endl;
        }
    }

    return retValue;
}