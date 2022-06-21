// ===========================================================
// Name         : StreetDomainTests.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code tests the `Street` class of the TrafficSimulation.
// ===========================================================

#include "gtest/gtest.h"
#include "../objects/Street.h"
#include "../objects/vehicles/Car.h"
#include "../objects/TrafficLight.h"
#include "../objects/BusStop.h"
#include "../objects/VehicleGenerator.h"

class StreetDomainTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        street = new Street("Testbaan", 200);
    }

    virtual void TearDown() {
        delete street;
    }

    Street* street;
};

TEST_F(StreetDomainTest, Constructor) {
    EXPECT_EQ("Testbaan", street->getName());
    EXPECT_EQ(200, street->getLength());
    EXPECT_TRUE(street->getTrafficLights().empty());
    EXPECT_TRUE(street->getBusStops().empty());
    EXPECT_TRUE(street->getVehicles().empty());
    EXPECT_TRUE(street->getCrossroads().empty());
    EXPECT_TRUE(street->properlyInitialized());
}

TEST_F(StreetDomainTest, addTrafficLight) {
    TrafficLight* trafficLight = new TrafficLight("Testbaan", 20, 10);

    street->addTrafficLight(trafficLight);
    long unsigned int expectedSize = 1;
    EXPECT_EQ(expectedSize, street->getTrafficLights().size());
    EXPECT_EQ(street->getTrafficLights()[0], trafficLight);
}

TEST_F(StreetDomainTest, addVehicle) {
    Car* car = new Car("Testbaan", 10);

    street->addVehicle(car);
    long unsigned int expectedSize = 1;
    EXPECT_EQ(expectedSize, street->getVehicles().size());
    EXPECT_EQ(car, street->getVehicles()[0]);
}

TEST_F(StreetDomainTest, addBusStop) {
    BusStop* busStop = new BusStop("Testbaan", 50, 10);

    street->addBusStop(busStop);
    long unsigned int expectedSize = 1;
    EXPECT_EQ(expectedSize, street->getBusStops().size());
    EXPECT_EQ(busStop, street->getBusStops()[0]);
}

TEST_F(StreetDomainTest, addVehicleGenerator) {
    VehicleGenerator* generator = new VehicleGenerator("Testbaan", 10, "Car");

    street->setVehicleGenerator(generator);
    EXPECT_TRUE(street->hasVehicleGenerator());
}

TEST_F(StreetDomainTest, ContractViolations) {
    // Test properlyInitialized condition
    Street illegalCopy = *street;

    EXPECT_DEATH(illegalCopy.getName(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getLength(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getTrafficLights(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getBusStops(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getVehicles(), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.getCrossroads(), "Assertion.*failed");

    // Test addTrafficLight() conditions
    TrafficLight* trafficLight1 = new TrafficLight("Testbaan", 300, 10);
    TrafficLight* trafficLight2 = new TrafficLight("Testbaan", -100, 10);
    TrafficLight* trafficLight3 = new TrafficLight("Anderebaan", 100, 10);
    EXPECT_DEATH(street->addTrafficLight(trafficLight1), "Assertion.*failed");
    EXPECT_DEATH(street->addTrafficLight(trafficLight2), "Assertion.*failed");
    EXPECT_DEATH(street->addTrafficLight(trafficLight3), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.addTrafficLight(trafficLight1), "Assertion.*failed");
    delete trafficLight1;
    delete trafficLight2;
    delete trafficLight3;

    // Test addVehicle() conditions
    Car* vehicle1 = new Car("Testbaan", 300);
    Car* vehicle2 = new Car("Testbaan", -100);
    Car* vehicle3 = new Car("Anderebaan", 100);
    EXPECT_DEATH(street->addVehicle(vehicle1), "Assertion.*failed");
    EXPECT_DEATH(street->addVehicle(vehicle2), "Assertion.*failed");
    EXPECT_DEATH(street->addVehicle(vehicle3), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.addVehicle(vehicle1), "Assertion.*failed");
    delete vehicle1;
    delete vehicle2;
    delete vehicle3;

    // Test addBusStop() conditions
    BusStop* busStop1 = new BusStop("Testbaan", 300, 10);
    BusStop* busStop2 = new BusStop("Testbaan", -100, 10);
    BusStop* busStop3 = new BusStop("Anderebaan", 100, 10);
    EXPECT_DEATH(street->addBusStop(busStop1), "Assertion.*failed");
    EXPECT_DEATH(street->addBusStop(busStop2), "Assertion.*failed");
    EXPECT_DEATH(street->addBusStop(busStop3), "Assertion.*failed");
    EXPECT_DEATH(illegalCopy.addBusStop(busStop1), "Assertion.*failed");
    delete busStop1;
    delete busStop2;
    delete busStop3;

    // Test setVehicleGenerator() conditions
    VehicleGenerator* generator1 = new VehicleGenerator("Anderebaan", 10, "Car");
    EXPECT_DEATH(street->setVehicleGenerator(generator1), "Assertion.*failed");
    EXPECT_FALSE(street->hasVehicleGenerator());
    EXPECT_DEATH(illegalCopy.setVehicleGenerator(generator1), "Assertion.*failed");
    delete generator1;
}
