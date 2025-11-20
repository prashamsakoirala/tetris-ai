#include "Shape.hpp"
#include <stdexcept>

Shape::Shape(string name, vector<vector<int>> position){
    this->name = name;
    if (validateShape(position)){
        this->position = position;
    }
    else {
        throw std::invalid_argument("Shape's bounds should be within a 4x4 square");
    }

}

vector<vector<int>> Shape::getShape(){
    return this->position;
}

string Shape::getShapeName(){
    return this->name;
}

bool validateShape(vector<vector<int>> shape){
    int totalBlocks = 0;
    for (auto &block : shape){
        totalBlocks += 1;
        int xPos = block[0];
        int yPos = block[1];
        if ((xPos < 0 || xPos >=4) || (yPos < 0 || yPos >=4)){
            return false;
        }
    }
    if (totalBlocks > 16){
        return false;
    }
    return true;
}