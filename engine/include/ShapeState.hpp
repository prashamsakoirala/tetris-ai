#ifndef SHAPESTATE
#define SHAPESTATE
#include <vector>
#include "Shape.hpp"

enum Direction : uint8_t {
    UP = 0b00,
    LEFT = 0b01,
    DOWN = 0b10,
    RIGHT = 0b11
};

class ShapeState {
    public:
    // Initalize shape, just get shape by returning coordinates
    // Constructor
    // rotation -> 0, 1, 
    // validates based on rulebook? or constraints?
    ShapeState(Shape* shape, int xPosition, int yPosition, Direction rotation);
    
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
    std::vector<int> getCoordinates();
    int getShapeXPosition();
    int getShapeYPosition();

    bool updateShapeXPosition();
    bool updateShapeYPosition();

    // Rotates shape 90 degrees
    // Do we need to know the rotation of the shape? Wouldn't that be just be stored in position
    // Or shape is static representation and rotation is visual
    bool rotateShape();

    private:
    Shape* shape;
    int xPosition;
    int yPosition;
    Direction direction;


};

#endif