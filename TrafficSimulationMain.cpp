#include <iostream>
#include <sstream>
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
        bool visualize = false;
        bool graph = false;
        bool simpleGraph = false;
        bool help = false;
        bool image = false;
        for (long unsigned int i = 0; i < args.size(); i++) {
            if (args[i] == "-h" || args[i] == "--help") {
                help = true;
                std::cout << "Usage: ./TrafficSimulation [-h] [-f FILENAME] [-r REPETITIONS]" << std::endl << std::endl
                << "This program runs a traffic simulation based on a given xml-file." << std::endl <<std::endl
                << "Required arguments:" << std::endl
                << "\t-f FILENAME\t\t\tthe xml-file that contains the simulation specifications" << std::endl
                << "\t-r REPETITIONS\t\t\tthe amount of times the simulation should be run" <<std::endl <<std::endl
                << "Optional arguments:" << std::endl
                << "\t-v\t\t\t\toutput to use together with the python visualizer" << std::endl
                << "\t-g\t\t\t\tget a graphical representation in the terminal" << std::endl
                << "\t-h, --help\t\t\tshow this help message and exit" << std::endl
                << "\t-sg\t\t\t\tget a simple graphical representation in the terminal" << std::endl;
                break;
            } else {
                if (args[i] == "-f") {
                    fileName = args[i+1];
                    i++;
                    continue;
                } else if (args[i] == "-r") {
                    std::string repetitionsString = args[i+1];
                    if ((std::istringstream(repetitionsString) >> repetitions).fail()) {
                        std::cout << "the amount of repetitions must be a number" << std::endl;
                        repetitions = -1;
                    }
                    else if (repetitions < 1) {
                        std::cout << "the amount of repetitions must be greater than 0" << std::endl;
                        repetitions = -1;
                    }
                    i++;
                    continue;
                } else if (args[i] == "-v") {
                    visualize = true;
                    continue;
                } else if (args[i] == "-g") {
                    graph = true;
                    continue;
                } else if (args[i] == "-sg") {
                    simpleGraph = true;
                    continue;
                } else if (args[i] == "-i") {
                    image = true;
                    continue;
                } else {
                    std::cout << "Argument " << args[i] << " not recognized. Use \"-h\" for help." << std::endl;
                }
            }
        }

        TrafficSimulation sim;
        if (fileName != "noFile" && repetitions != -1) {
            sim.parseInputFile(fileName);
            for (int k = 0; k < repetitions; k++) {
                sim.simulate();
                if (visualize) {
                    sim.visualize();
                }
                if (graph) {
                    sim.graph();
                }
                if (simpleGraph) {
                    sim.writeOn();
                } if (image) {
                    if (k % 5 == 0) {
                        sim.createImage(k);
                    }
                }
            }
        } else if (!help) {
            std::cout << "both a file and the amount of repetitions must be given" <<std::endl;
        }
    }

    return retValue;
}