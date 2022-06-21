// ===========================================================
// Name         : VehicleDomainTests.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code tests the `Vehicle` class of the TrafficSimulation.
// ===========================================================

#include "gtest/gtest.h"
#include "../objects/Vehicle.h"
#include "../objects/vehicles/Ambulance.h"
#include "../objects/vehicles/Bus.h"
#include "../objects/vehicles/Car.h"
#include "../objects/vehicles/FireEngine.h"
#include "../objects/vehicles/PoliceCar.h"

class VehicleDomainTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        ambulance = new Ambulance("Testbaan", 10);
        bus = new Bus("Testbaan", 20);
        car = new Car("Testbaan", 30);
        fireEngine = new FireEngine("Testbaan", 40);
        policeCar = new PoliceCar("Testbaan", 50);
    }

    virtual void TearDown() {
        delete ambulance;
        delete bus;
        delete car;
        delete fireEngine;
        delete policeCar;
    }

    Ambulance* ambulance;
    Bus* bus;
    Car* car;
    FireEngine* fireEngine;
    PoliceCar* policeCar;
};

TEST_F(VehicleDomainTest, Constructor) {
    // Ambulance
    EXPECT_EQ("Testbaan", ambulance->getStreet());
    EXPECT_EQ(10, ambulance->getPosition());
    EXPECT_EQ(0, ambulance->getSpeed());
    EXPECT_EQ(ambulanceMaxSpeed, ambulance->getMaxSpeed());
    EXPECT_EQ('Z', ambulance->getAcronym());
    EXPECT_EQ("Ambulance", ambulance->getType());
    EXPECT_TRUE(ambulance->hasPriority());
    EXPECT_TRUE(ambulance->properlyInitialized());

    // Bus
    EXPECT_EQ("Testbaan", bus->getStreet());
    EXPECT_EQ(20, bus->getPosition());
    EXPECT_EQ(0, bus->getSpeed());
    EXPECT_EQ(busMaxSpeed, bus->getMaxSpeed());
    EXPECT_EQ('B', bus->getAcronym());
    EXPECT_EQ("Bus", bus->getType());
    EXPECT_FALSE(bus->hasPriority());
    EXPECT_TRUE(bus->properlyInitialized());

    // Car
    EXPECT_EQ("Testbaan", car->getStreet());
    EXPECT_EQ(30, car->getPosition());
    EXPECT_EQ(0, car->getSpeed());
    EXPECT_EQ(carMaxSpeed, car->getMaxSpeed());
    EXPECT_EQ('A', car->getAcronym());
    EXPECT_EQ("Car", car->getType());
    EXPECT_FALSE(car->hasPriority());
    EXPECT_TRUE(car->properlyInitialized());

    // FireEngine
    EXPECT_EQ("Testbaan", fireEngine->getStreet());
    EXPECT_EQ(40, fireEngine->getPosition());
    EXPECT_EQ(0, fireEngine->getSpeed());
    EXPECT_EQ(fireEngineMaxSpeed, fireEngine->getMaxSpeed());
    EXPECT_EQ('F', fireEngine->getAcronym());
    EXPECT_EQ("FireEngine", fireEngine->getType());
    EXPECT_TRUE(fireEngine->hasPriority());
    EXPECT_TRUE(fireEngine->properlyInitialized());

    // PoliceCar
    EXPECT_EQ("Testbaan", policeCar->getStreet());
    EXPECT_EQ(50, policeCar->getPosition());
    EXPECT_EQ(0, policeCar->getSpeed());
    EXPECT_EQ(policeCarMaxSpeed, policeCar->getMaxSpeed());
    EXPECT_EQ('P', policeCar->getAcronym());
    EXPECT_EQ("PoliceCar", policeCar->getType());
    EXPECT_TRUE(policeCar->hasPriority());
    EXPECT_TRUE(policeCar->properlyInitialized());
}

TEST_F(VehicleDomainTest, AmbulanceMaxSpeed) {
    ambulance->brake();
    EXPECT_NE(ambulanceMaxSpeed, ambulance->getMaxSpeed());

    ambulance->setMaxSpeed();
    EXPECT_EQ(ambulanceMaxSpeed, ambulance->getMaxSpeed());
}

TEST_F(VehicleDomainTest, BusMaxSpeed) {
    bus->brake();
    EXPECT_NE(busMaxSpeed, bus->getMaxSpeed());

    bus->setMaxSpeed();
    EXPECT_EQ(busMaxSpeed, bus->getMaxSpeed());
}

TEST_F(VehicleDomainTest, CarMaxSpeed) {
    car->brake();
    EXPECT_NE(carMaxSpeed, car->getMaxSpeed());

    car->setMaxSpeed();
    EXPECT_EQ(carMaxSpeed, car->getMaxSpeed());
}

TEST_F(VehicleDomainTest, FireEngineMaxSpeed) {
    fireEngine->brake();
    EXPECT_NE(fireEngineMaxSpeed, fireEngine->getMaxSpeed());

    fireEngine->setMaxSpeed();
    EXPECT_EQ(fireEngineMaxSpeed, fireEngine->getMaxSpeed());
}

TEST_F(VehicleDomainTest, PoliceCarMaxSpeed) {
    policeCar->brake();
    EXPECT_NE(policeCarMaxSpeed, policeCar->getMaxSpeed());

    policeCar->setMaxSpeed();
    EXPECT_EQ(policeCarMaxSpeed, policeCar->getMaxSpeed());
}

TEST_F(VehicleDomainTest, ContractViolations) {
    // Ambulance
    Ambulance illegalAmbulance = *ambulance;

    EXPECT_DEATH(illegalAmbulance.getStreet(), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.getPosition(), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.getSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.getMaxSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.getLength(), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.getAcronym(), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.getType(), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.drive(NULL), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.brake(), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.stop(), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.setMaxSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.hasPriority(), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.hasTurned(), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.setTurn(true), "Assertion.*failed");
    EXPECT_DEATH(illegalAmbulance.setTurn(false), "Assertion.*failed");

    // Bus
    Bus illegalBus = *bus;

    EXPECT_DEATH(illegalBus.getStreet(), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.getPosition(), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.getSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.getMaxSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.getLength(), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.getAcronym(), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.getType(), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.drive(NULL), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.brake(), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.stop(), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.setMaxSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.hasPriority(), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.hasTurned(), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.setTurn(true), "Assertion.*failed");
    EXPECT_DEATH(illegalBus.setTurn(false), "Assertion.*failed");

    // Car
    Car illegalCar = *car;

    EXPECT_DEATH(illegalCar.getStreet(), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.getPosition(), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.getSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.getMaxSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.getLength(), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.getAcronym(), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.getType(), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.drive(NULL), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.brake(), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.stop(), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.setMaxSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.hasPriority(), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.hasTurned(), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.setTurn(true), "Assertion.*failed");
    EXPECT_DEATH(illegalCar.setTurn(false), "Assertion.*failed");

    // FireEngine
    FireEngine illegalFireEngine = *fireEngine;

    EXPECT_DEATH(illegalFireEngine.getStreet(), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.getPosition(), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.getSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.getMaxSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.getLength(), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.getAcronym(), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.getType(), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.drive(NULL), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.brake(), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.stop(), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.setMaxSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.hasPriority(), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.hasTurned(), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.setTurn(true), "Assertion.*failed");
    EXPECT_DEATH(illegalFireEngine.setTurn(false), "Assertion.*failed");

    // PoliceCar
    PoliceCar illegalPoliceCar = *policeCar;

    EXPECT_DEATH(illegalPoliceCar.getStreet(), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.getPosition(), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.getSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.getMaxSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.getLength(), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.getAcronym(), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.getType(), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.drive(NULL), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.brake(), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.stop(), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.setMaxSpeed(), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.hasPriority(), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.hasTurned(), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.setTurn(true), "Assertion.*failed");
    EXPECT_DEATH(illegalPoliceCar.setTurn(false), "Assertion.*failed");
}
