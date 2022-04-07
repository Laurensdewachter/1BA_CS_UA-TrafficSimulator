// ===========================================================
// Name         : Street.h
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.1
// Description  : This code is contains the `Street` class
// ===========================================================

#ifndef PSE_STREET_H
#define PSE_STREET_H

#include <iostream>
#include <vector>
#include "../DesignByContract.h"
class TrafficLight;
class Vehicle;
class VehicleGenerator;
class TrafficSimulation;

class Street {
    Street* _initCheck;

    std::string fName;
    int fLength;
    std::vector<TrafficLight*> fTrafficLights;
    std::vector<Vehicle*> fVehicles;
    VehicleGenerator* fVehicleGenerator;

public:
    /*
     * ENSURE(properlyInitialized(), "Street constructor did not end in an initialized state")
     */
    Street();

    virtual ~Street();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling setName()")
     * ENSURE(this->getName() == n, "setName() postcondition")
     */
    void setName(const std::string &n);

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling setLength()")
     * ENSURE(this->getLength() == l, "setLength() postcondition")
     */
    void setLength(int l);

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling addTrafficLight()")
     * ENSURE(!fTrafficLights.empty(), "addTrafficLight() postcondition")
     */
    void addTrafficLight(TrafficLight* t);

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling addVehicle()")
     * ENSURE(fVehicles.size() >= 1, "addVehicle() postcondition")
     */
    void addVehicle(Vehicle* v);

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling addVehicleGenerator()")
     * ENSURE(fVehicleGenerator == vg, "addVehicleGenerator() postcondition")
     */
    void setVehicleGenerator(VehicleGenerator* vg);

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling removeVehicle()")
     * ENSURE(fVehicles.size() == vehiclesSize-1, "removeVehicle() postcondition")
     */
    void removeVehicle();

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling getName()")
     */
    const std::string &getName() const;

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling getLength()")
     */
    int getLength() const;

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling getTrafficLights()")
     */
    std::vector<TrafficLight*> getTrafficLights() const;

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling getVehicles()")
     */
    std::vector<Vehicle*> getVehicles() const;

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling hasVehicleGenerator()")
     */
    bool hasVehicleGenerator() const;

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling driveVehicles()")
     */
    void driveVehicles();

    /*
    * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling simTrafficLights()")
    */
    void simTrafficLights(double &time);

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling simGenerator()")
     */
    void simGenerator(double &time);

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling sortVehicles()")
     * ENSURE(!fVehicles.empty(), "sortVehicles() postcondition")
     */
    void sortVehicles();
};


#endif
