#ifndef SHAPESTATE
#define SHAPESTATE
#include <vector>
#include <map>
#include "Shape.hpp"
#include "Utils.hpp"

using std::vector;
using std::map;

class ShapeState {
    public:
    // Initalize shape, just get shape by returning coordinates
    // Constructor
    // rotation -> 0, 1, 
    // validates based on rulebook? or constraints?
    ShapeState(Shape shape, int xPosition, int yPosition, Direction rotation);
    
    // Return all coordinates in shape...
    // Should I have a shape validator
    // coorindates takes into consideration pivot of shape, x position, y position, and returns int of where the shape is on the board
    // this is validated by the grid
    // update position should update it and then be validated
    // can move
    // if can move then update
    // else if cant move then dont update it?

    /*
        tell shape to move left
        get coordinates
        if can move, then update
        else update does not move through

        tell shape to rotate
        get coordinates
        if cant rotate then update position kick until can?

    */
    vector<vector<int>> getPixels();

    // Rotates shape 90 degrees
    // Do we need to know the rotation of the shape? Wouldn't that be just be stored in position
    // Or shape is static representation and rotation is visual

    bool moveLeft();
    bool moveRight();
    bool moveDown();
    bool rotate();

    protected:
    bool updateShape(Shape newShape);

    private:
    Shape* shape;
    int xPosition;
    int yPosition;
    Direction rotation;

    void removeCurrentShape();
    void addNewShape();

    bool updateShapeXPosition(int xPosition);
    bool updateShapeYPosition(int yPosition);
    std::map<Direction, vector<vector<int>>>* rotationMap;

};

#endif