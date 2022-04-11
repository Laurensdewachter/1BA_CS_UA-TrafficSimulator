#include <iostream>
#include <fstream>
#include "TrafficSimulation.h"

int main(int argc, char** argv) {
    int retValue = 0;

    TrafficSimulation sim;

    if (argc != 2) {
        std::cerr << "There is no input file given." << std::endl;
        retValue = -1;
    }
    else {
        sim.parseInputFile(argv[1]);
    }

    return retValue;
}