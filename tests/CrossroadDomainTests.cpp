// ===========================================================
// Name         : CrossroadDomainTests.cpp
// Author       : Laurens De Wachter & Nabil El Ouaamari
// Version      : 1.0
// Description  : This code tests the `Crossraod` class of the TrafficSimulation.
// ===========================================================

#include "gtest/gtest.h"
#include "../objects/Street.h"

class CrossroadDomainTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        crossroad1 = new Street("Turnhoutsebaan",500);;
        crossroad2 = new Street("Middelheimbaan",500);

        crossroad1->addCrossroad(crossroad2, 100);
        crossroad2->addCrossroad(crossroad1, 50);

    }

    virtual void TearDown() {
        delete crossroad1;
        delete crossroad2;
    }

    Street* crossroad1;
    Street* crossroad2;

};

TEST_F(CrossroadDomainTest, Constructor) {
    EXPECT_EQ(crossroad1->getName(), "Turnhoutsebaan");
    EXPECT_EQ(crossroad1->getLength(), 500);
    EXPECT_TRUE(crossroad1->properlyInitialized());

    EXPECT_EQ(crossroad2->getName(), "Middelheimbaan");
    EXPECT_EQ(crossroad2->getLength(), 500);
    EXPECT_TRUE(crossroad2->properlyInitialized());


}

TEST_F(CrossroadDomainTest, HappyDay) {
    EXPECT_EQ(crossroad1->getCrossroads().begin()->first,crossroad2);
    EXPECT_EQ(crossroad1->getCrossroads().begin()->second,100);

    EXPECT_EQ(crossroad2->getCrossroads().begin()->first,crossroad1);
    EXPECT_EQ(crossroad2->getCrossroads().begin()->second,50);
}