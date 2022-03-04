// ===========================================================
// Name         : Street.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code is contains the `Street` class
// ===========================================================

#ifndef PSE_STREET_H
#define PSE_STREET_H

#include <iostream>
#include "../DesignByContract.h"

class Street {
    Street* _initCheck;
    std::string name;
    int length;

public:
    /*
     * ENSURE(properlyInitialized(), "Constructor must end in properlyInitialized state.")
     */
    Street();

    virtual ~Street();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling `setName()`.")
     * ENSURE(name == n, "`setName()` postcondition failed.")
     */
    void setName(const std::string &name);

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling `setLength()`.")
     * ENSURE(Street::length == l, "`setLength()` postcondition failed.")
     */
    void setLength(int length);

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling `getName()`.")
     */
    const std::string &getName() const;

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling `getLength()`.")
     */
    int getLength() const;
};


#endif
