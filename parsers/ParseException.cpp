// ===========================================================
// Name         : ParseException.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code contains the `ParseException` that is used in all parsers of the simulation project.
// ===========================================================

#include "ParseException.h"

ParseException::ParseException(const char *message) : message(message) {}

const char * ParseException::what() const throw() {
    return message;
}