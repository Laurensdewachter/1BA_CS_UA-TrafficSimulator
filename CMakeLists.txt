cmake_minimum_required(VERSION 3.6)
project(PSE)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(gtest/include)

# Set Library dir
link_directories(gtest/lib)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES main.cpp parsers/tinyxml/tinyxml.h parsers/tinyxml/tinyxml.cpp parsers/tinyxml/tinyxmlparser.cpp
        parsers/tinyxml/tinyxmlerror.cpp parsers/tinyxml/tinyxmlerror.cpp parsers/tinyxml/tinystr.h parsers/tinyxml/tinystr.cpp
        DesignByContract.h parsers/ElementParser.cpp parsers/ElementParser.h objects/Street.cpp objects/Street.h objects/TrafficLight.cpp objects/TrafficLight.h objects/Vehicle.cpp objects/Vehicle.h parsers/StreetParser.cpp parsers/StreetParser.h parsers/ParseException.cpp parsers/ParseException.h parsers/TrafficLightParser.cpp parsers/TrafficLightParser.h parsers/VehicleParser.cpp parsers/VehicleParser.h)

# Set source files for DEBUG target
set(DEBUG_SOURCE_FILES tests.cpp parsers/tinyxml/tinyxml.h parsers/tinyxml/tinyxml.cpp parsers/tinyxml/tinyxmlparser.cpp
        parsers/tinyxml/tinyxmlerror.cpp parsers/tinyxml/tinyxmlerror.cpp parsers/tinyxml/tinystr.h parsers/tinyxml/tinystr.cpp)

# Create RELEASE target
add_executable(main ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(tests ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(tests gtest)
