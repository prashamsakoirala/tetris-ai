#include "ShapeState.hpp"
#include "Utils.hpp"

ShapeState::ShapeState(Shape shape, int xPosition, int yPosition, Direction rotation){
    this->shape = &shape;
    this->xPosition = xPosition;
    this->yPosition = yPosition;
    this->rotation = rotation;

}

vector<vector<int>> ShapeState::getPixels(){

    vector<vector<int>> newMat = this->shape->getShape();

    for (int i = 0; i<(this->rotation); i++){
        rotateClockwise(newMat);
    }
    return newMat;
}

bool ShapeState::updateShape(Shape newShape){
    this->shape = &newShape;
}

bool ShapeState::removeCurrentShape(){
    this->shape = nullptr;
}

// get position and just increment -1
bool ShapeState::moveLeft(){
    this->xPosition -= 1;
}

bool ShapeState::moveRight(){
    this->xPosition += 1;
}

bool ShapeState::moveDown(){
    this->yPosition += 1;
}

bool ShapeState::rotate(){
    this->rotation = nextDirection(this->rotation);
}

bool ShapeState::updateShapeXPosition(int xPosition){
    this->xPosition = xPosition;
    
}
bool ShapeState::updateShapeYPosition(int yPosition){
    this->xPosition = yPosition;
}

void transpose(vector<vector<int>>& mat){
    int n = mat.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) { 
            mat[i][j] = mat[j][i];
        }
    }
};

void verticalFlip(vector<vector<int>>& mat) {
    for (auto& block : mat) {
        block[1] = 3 - block[1];  // flip vertically in 4x4 grid
    }
}

void rotateClockwise(vector<vector<int>>& mat){
    transpose(mat);
    verticalFlip(mat);
}