#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "parsers/ElementParser.h"


int main(int argc, char** argv) {
    if (argc < 2) std::cerr << "No files given" << std::endl;

    ElementParser parser;
    for (int i = 1; i < argc; i++) {
        try {
            parser.parseFile(argv[i]);
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}