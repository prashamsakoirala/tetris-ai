// #include "GridState.hpp"

// GridState::GridState(Grid* grid, vector<vector<int>>& existingBlocks){
//     if (validateExistingBlocks(existingBlocks, grid->getXDimension(), grid->getYDimension())){
//         this->grid = grid;
//         this->filledBlocks = existingBlocks;
//     } else {
//         throw std::invalid_argument("Invalid existing blocks");
//     }
// }

// GridState::GridState(Grid* grid){
//     this->grid = grid;
//     this->filledBlocks = vector<vector<int>>(grid->getXDimension(), std::vector<int>(grid->getYDimension(), 0));
// }

// bool GridState::isOccupied(int xPosition, int yPosition){
//     //if position not within bounds return false?
//     for (auto &block : filledBlocks){
//         int xPos = block[0];
//         int yPos = block[1];
//         if ((xPos == xPosition) && (yPos == yPosition)){
//             return true;
//         }
//     }
//     return false;
// }

// bool GridState::addCoordinate(int xCoordinate, int yCoordinate){
//     // if coordinate is out of bounds, then return false? or make sure to check bounds before calling
//     if (!isOccupied(xCoordinate, yCoordinate)){
//         vector<int> updatedCoords;
//         updatedCoords.push_back(xCoordinate);
//         updatedCoords.push_back(yCoordinate);
//         this->filledBlocks.push_back(updatedCoords);
//         return true;
//     } else {
//         return false;
//     }
// }

// bool GridState::inBounds(int xPosition, int yPosition){
//     if ((xPosition >= 0 && xPosition < this->grid->getXDimension()) && (yPosition >= 0 && yPosition < this->grid->getYDimension())){
//         return true;
//     } else {
//         return false;
//     }
// }

// bool GridState::clearRow(int row){
//     bool rowWasFilled = rowFilled(row);
//     if (!rowWasFilled) return false;

//     vector<vector<int>> newFilled;
//     for (auto &block : filledBlocks){
//         if (block[1] < row){ 
//             newFilled.push_back({block[0], block[1] + 1});
//         } else if (block[1] > row){
//             newFilled.push_back(block);
//         }
//     }

//     filledBlocks = newFilled;
//     return true;
// }

// bool GridState::rowFilled(int row){
//     int count = 0;
//     for (auto &block : filledBlocks){
//         if (block[1] == row){
//             count++;
//         }
//     }
//     return count == this->grid->getXDimension();
// }

// bool GridState::checkAndClearRows(){
//     bool anyCleared = false;
//     int maxRow = this->grid->getYDimension();

//     for (int row = maxRow - 1; row >= 0; row--){
//         if (rowFilled(row)){
//             clearRow(row);
//             anyCleared = true;
//             row++;
//         }
//     }

//     return anyCleared;
// }

// bool validateExistingBlocks(vector<vector<int>> blocks, int xDimensions, int yDimensions){
//     int totalBlocks = 0;
//     for (auto &block : blocks){
//         totalBlocks += 1;
//         int xPos = block[0];
//         int yPos = block[1];
//         if ((xPos < 0 || xPos >= xDimensions) || (yPos < 0 || yPos >= yDimensions)){
//             return false;
//         }
//     }
//     if (totalBlocks > (xDimensions * yDimensions)){
//         return false;
//     }
//     return true;
// }

#include <gtest/gtest.h>
#include "GridState.hpp"

class GridStateTest : public ::testing::Test {
protected:
    Grid* grid;
    GridState* gridStateClean;

    void SetUp() override {
        grid = new Grid(10, 20);
        gridStateClean = new GridState(grid);
    }

    void TearDown() override {
        delete grid;
        delete gridStateClean;
    }

};

/*

    isOccupied(x, y)
    if out of bounds, throw out of grid bounds error
    inBounds(x, y)

    test add coordinate out of bounds throws error
    test add coordinate valid

    test in bounds

*/

// in bounds
TEST_F(GridStateTest, TestInBoundsFalse) {
    EXPECT_FALSE(gridStateClean->inBounds(15, 25));
}

TEST_F(GridStateTest, TestInBoundsTrue) {
    EXPECT_TRUE(gridStateClean->inBounds(5, 5));
}

// is occupied
TEST_F(GridStateTest, TestIsOccupiedFalse) {
    EXPECT_FALSE(gridStateClean->isOccupied(5, 5));
}

TEST_F(GridStateTest, TestIsOccupiedTrue) {
    gridStateClean->addCoordinate(5, 5);
    EXPECT_TRUE(gridStateClean->isOccupied(5, 5));
    gridStateClean->clearRow(5);
}

// add coordinate
TEST_F(GridStateTest, TestAddCoordinateValid) {
    EXPECT_TRUE(gridStateClean->addCoordinate(5, 5));
}

TEST_F(GridStateTest, TestRowFilledFalse){
    EXPECT_FALSE(gridStateClean->addCoordinate(5, 5))
}

TEST_F(GridStateTest, TestRowFilledTrue){
    EXPECT_TRUE()
}