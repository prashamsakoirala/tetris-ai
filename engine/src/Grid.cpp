// Done
#include "Grid.hpp"
#include <stdexcept>

Grid::Grid(int xDimension, int yDimension){
    if (validateGrid(xDimension, yDimension)){
        this->xDimension = xDimension;
        this->yDimension = yDimension;
    } else {
        throw std::invalid_argument("Shape's bounds should be within a 4x4 square");
    }
};

int Grid::getXDimension(){
    return this->xDimension;
};

int Grid::getYDimension(){
    return this->yDimension;
};

bool validateGrid(int xDimension, int yDimension){
    if (xDimension > 10 || yDimension > 20 || xDimension < 4 || yDimension < 8){
        return false;
    } else {
        return true;
    }
}