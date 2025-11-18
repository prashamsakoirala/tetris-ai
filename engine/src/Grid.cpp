#include "Grid.hpp"

Grid::Grid(int xDimension, int yDimension){
    this->xDimension = xDimension;
    this->yDimension = yDimension;
};

int Grid::getXDimension(){
    return this->xDimension;
};

int Grid::getYDimension(){
    return this->yDimension;
};