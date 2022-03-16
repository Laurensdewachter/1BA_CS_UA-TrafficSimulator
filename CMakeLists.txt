cmake_minimum_required(VERSION 3.6)
project(TrafficSimulation)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(gtest/include)

# Set Library dir
link_directories(gtest/lib)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES TrafficSimulationMain.cpp parsers/tinyxml/tinyxml.cpp parsers/tinyxml/tinyxmlparser.cpp
        parsers/tinyxml/tinyxmlerror.cpp parsers/tinyxml/tinyxmlerror.cpp parsers/tinyxml/tinystr.cpp
        parsers/ElementParser.cpp objects/Street.cpp objects/TrafficLight.cpp objects/Vehicle.cpp parsers/StreetParser.cpp
        parsers/ParseException.cpp parsers/TrafficLightParser.cpp parsers/VehicleParser.cpp parsers/VehicleGeneratorParser.cpp
        objects/VehicleGenerator.cpp TrafficSimulation.cpp)

# Set source files for DEBUG target
set(DEBUG_SOURCE_FILES tests/TrafficSimulationTests.cpp parsers/tinyxml/tinyxml.cpp parsers/tinyxml/tinyxmlparser.cpp
        parsers/tinyxml/tinyxmlerror.cpp parsers/tinyxml/tinyxmlerror.cpp parsers/tinyxml/tinystr.cpp tests/TrafficSimulationInputTests.cpp
        Utils.cpp TrafficSimulation.cpp parsers/ElementParser.cpp parsers/VehicleParser.cpp parsers/VehicleGeneratorParser.cpp
        parsers/StreetParser.cpp parsers/TrafficLightParser.cpp objects/Street.cpp objects/TrafficLight.cpp objects/Vehicle.cpp
        objects/VehicleGenerator.cpp parsers/ParseException.cpp)

# Create RELEASE target
add_executable(main ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(tests ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(tests gtest)
