// ===========================================================
// Name         : SimulationException.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code contains the `SimulationException` that is used in the `TrafficSimulation` class.
// ===========================================================

#include "SimulationException.h"

SimulationException::SimulationException(const char *message) : fMessage(message) {}

const char * SimulationException::what() const throw() {
    return fMessage;
}