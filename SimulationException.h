// ===========================================================
// Name         : SimulationException.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code contains the `SimulationException` that is used in the `TrafficSimulation` class.
// ===========================================================

#ifndef TRAFFICSIMULATION_SIMULATIONEXCEPTION_H
#define TRAFFICSIMULATION_SIMULATIONEXCEPTION_H

#include <exception>

class SimulationException : public std::exception{
    const char* fMessage;

public:
    SimulationException(const char* message);
    const char * what() const throw();
};


#endif