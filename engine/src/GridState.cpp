#include "GridState.hpp"

/*
should i check in bounds for isoccupied?
*/

GridState::GridState(Grid* grid, vector<vector<int>>& existingBlocks){
    if (validateExistingBlocks(existingBlocks, grid->getXDimension(), grid->getYDimension())){
        this->grid = grid;
        this->filledBlocks = existingBlocks;
    } else {
        throw std::invalid_argument("Invalid existing blocks");
    }
}

GridState::GridState(Grid* grid){
    this->grid = grid;
    this->filledBlocks = vector<vector<int>>(grid->getXDimension(), std::vector<int>(grid->getYDimension(), 0));
}

bool GridState::isOccupied(int xPosition, int yPosition){
    if (inBounds(xPosition, yPosition) == false){
        return false;
    }
    //if position not within bounds return false?
    for (auto &block : filledBlocks){
        int xPos = block[0];
        int yPos = block[1];
        if ((xPos == xPosition) && (yPos == yPosition)){
            return true;
        }
    }
    return false;
}

bool GridState::isValidCoordinate(int xCoordinate, int yCoordinate){
    return !isOccupied(xCoordinate, yCoordinate) && inBounds(xCoordinate, yCoordinate);
}

vector<vector<int>> GridState::getFilledBlocks(){
    return this->filledBlocks;
}

void GridState::addCoordinate(int xCoordinate, int yCoordinate){
    vector<int> updatedCoords;
    updatedCoords.push_back(xCoordinate);
    updatedCoords.push_back(yCoordinate);
    this->filledBlocks.push_back(updatedCoords);
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

bool validateExistingBlocks(vector<vector<int>> blocks, int xDimensions, int yDimensions){
    int totalBlocks = 0;
    for (auto &block : blocks){
        totalBlocks += 1;
        int xPos = block[0];
        int yPos = block[1];
        if ((xPos < 0 || xPos >= xDimensions) || (yPos < 0 || yPos >= yDimensions)){
            return false;
        }
    }
    if (totalBlocks > (xDimensions * yDimensions)){
        return false;
    }
    return true;
}