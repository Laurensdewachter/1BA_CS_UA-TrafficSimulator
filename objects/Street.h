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
#include <map>

class TrafficLight;
class Vehicle;
class VehicleGenerator;
class BusStop;

class Street {
    Street* _initCheck;

    std::string fName;
    int fLength;
    std::vector<TrafficLight*> fTrafficLights;
    std::vector<Vehicle*> fVehicles;
    std::vector<BusStop*> fBusStops;
    VehicleGenerator* fVehicleGenerator;
    std::vector<std::pair<Street*, unsigned int> > fCrossroads;

public:
    /*
     * ENSURE(properlyInitialized(), "Street constructor did not end in an initialized state")
     */
    Street(const std::string &name, int length);

    virtual ~Street();

    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling addTrafficLight()")
     *     ENSURE(fTrafficLights.size() == trafficLightsSize+1, "addTrafficLight() postcondition")
     */
    void addTrafficLight(TrafficLight* t);

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling addVehicle()")
     *     ENSURE(fVehicles.size() == vehiclesSize+1, "addVehicle() postcondition")
     */
    void addVehicle(Vehicle* v);

     /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling addBusStop()")
     * ENSURE(fBusStops.size() == busStopsSize+1, "addBusStop() postcondition")
     */
    void addBusStop(BusStop* b);
  
    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling addCrossroad()")
     * ENSURE(fVehicles.size() >= 1, "addCrossroad() postcondition")
     */
    void addCrossroad(Street* crossingStreet, unsigned int position);

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
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling getBusStops()")
     */
    std::vector<BusStop*> getBusStops() const;

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling getCrossroads()")
     */
    std::vector<std::pair<Street*, unsigned int> > getCrossroads() const;


    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling hasVehicleGenerator()")
     */
    bool hasVehicleGenerator() const;

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling driveVehicles()")
     * for (unsigned int i = 0; i < fVehicles.size(); i++) ENSURE(fVehicles[i]->getPosition() >= originalPositions[i] - 0.001, "driveVehicles() postcondition")
     */
    void driveVehicles();

    /*
    * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling simTrafficLights()")
    */
    void simTrafficLights(double &time);

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling simGenerator()")
     * if (spawn) ENSURE(fVehicles.size() == startSize+1, "simGenerator() postcondition")
     * else ENSURE(fVehicles.size() == startSize, "simGenerator() postcondition")
     */
    void simGenerator(double &time);

    /*
     * REQUIRE(properlyInitialized(), "Street wasn't initialized when calling sortVehicles()")
     * ENSURE(!fVehicles.empty(), "sortVehicles() postcondition")
     */
    void sortVehicles();
};


#endif
