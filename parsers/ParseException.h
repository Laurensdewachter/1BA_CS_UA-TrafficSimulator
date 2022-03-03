// ===========================================================
// Name         : ParseException.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code contains the `ParseException` that is used in all parsers of the simulation project.
// ===========================================================

#ifndef PSE_PARSEEXCEPTION_H
#define PSE_PARSEEXCEPTION_H

#include <exception>

class ParseException : public std::exception {
    const char* message;

public:
    ParseException(const char* message);
    const char * what() const throw();
};


#endif //PSE_PARSEEXCEPTION_H
