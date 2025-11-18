#include "GridState.hpp"

GridState::GridState(Grid* grid, vector<vector<int>>& existingBlocks){
    this->grid = grid;
    this->filledBlocks = existingBlocks;
}

GridState::GridState(Grid* grid){
    this->grid = grid;
    this->filledBlocks = vector<vector<int>>(grid->getXDimension(), std::vector<int>(grid->getYDimension(), 0));
}

bool GridState::isOccupied(int xPosition, int yPosition){
    for (auto &block : filledBlocks){
        int xPos = block[0];
        int yPos = block[1];
        if ((xPos == xPosition) && (yPos == yPosition)){
            return true;
        }
    }
    return false;
}

bool GridState::addCoordinate(int xCoordinate, int yCoordinate){
    if (!isOccupied(xCoordinate, yCoordinate)){
        vector<int> updatedCoords;
        updatedCoords.push_back(xCoordinate);
        updatedCoords.push_back(yCoordinate);
        this->filledBlocks.push_back(updatedCoords);
        return true;
    } else {
        return false;
    }
}

bool GridState::inBounds(int xPosition, int yPosition){
    if ((xPosition >= 0 && xPosition < this->grid->getXDimension()) && (yPosition >= 0 && yPosition < this->grid->getYDimension())){
        return true;
    } else {
        return false;
    }
}

bool GridState::clearRow(int row){
    bool rowWasFilled = rowFilled(row);
    if (!rowWasFilled) return false;

    vector<vector<int>> newFilled;
    for (auto &block : filledBlocks){
        if (block[1] < row){ 
            newFilled.push_back({block[0], block[1] + 1});
        } else if (block[1] > row){
            newFilled.push_back(block);
        }
    }

    filledBlocks = newFilled;
    return true;
}

bool GridState::rowFilled(int row){
    int count = 0;
    for (auto &block : filledBlocks){
        if (block[1] == row){
            count++;
        }
    }
    return count == this->grid->getXDimension();
}

bool GridState::checkAndClearRows(){
    bool anyCleared = false;
    int maxRow = this->grid->getYDimension();

    for (int row = maxRow - 1; row >= 0; row--){
        if (rowFilled(row)){
            clearRow(row);
            anyCleared = true;
            row++;
        }
    }

    return anyCleared;
}