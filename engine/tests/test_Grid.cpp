// done
#include <gtest/gtest.h>
#include "Grid.hpp"

class GridTest : public ::testing::Test {
protected:
    Grid* grid;

    void SetUp() override {
        grid = new Grid(10, 20);
    }

    void TearDown() override {
        delete grid;
    }

};

TEST_F(GridTest, GetXDimension) {
    EXPECT_EQ(grid->getXDimension(), 10);
}

TEST_F(GridTest, GetYDimension) {
    EXPECT_EQ(grid->getYDimension(), 20);
}

TEST(GridConstructorTest, ConstructorGreaterThanBoundsThrows) {
    EXPECT_THROW(Grid g(15, 25), std::invalid_argument);
}

TEST(GridConstructorTest, ConstructorLessThanBoundsThrows) {
    EXPECT_THROW(Grid g(3, 6), std::invalid_argument);
}