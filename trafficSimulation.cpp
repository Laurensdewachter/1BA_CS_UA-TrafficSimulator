#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "parsers/ElementParser.h"


int main(int argc, char** argv) {
    std::vector<std::string> args = std::vector<std::string>(argv+1, argv+argc);
    if (args.empty()) {
        std::ifstream fileIn("filelist.txt");
        std::string filelistName;
        while (std::getline(fileIn, filelistName)) {
            args.push_back(filelistName);
        }
    }

    ElementParser parser;
    for (long unsigned int i = 0; i < args.size(); i++) {
        try {
            parser.parseFile(args[i]);
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}