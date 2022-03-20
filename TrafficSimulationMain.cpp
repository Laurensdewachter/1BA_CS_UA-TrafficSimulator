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

        for (int i = 0; i < 4000; i++) {
            sim.simulate();
            sim.visualize();
        }
        //sim.writeOn();
    }

    return retValue;
}