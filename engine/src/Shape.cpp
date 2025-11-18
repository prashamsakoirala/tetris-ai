#include "Shape.hpp"

Shape::Shape(string name, vector<vector<int>> position, int xPivot, int yPivot){
    this->name = name;
    this->position = position;
}

vector<vector<int>> Shape::getShape(){
    return this->position;
}

string Shape::getShapeName(){
    return this->name;
}