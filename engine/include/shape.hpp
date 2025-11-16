#ifndef SHAPE
#define SHAPE
#include <vector>

class Shape {
    public:
    // Initalize shape, just get shape by returning coordinates
    // Constructor
    // validates based on rulebook? or constraints?
    Shape(char name[10], std::vector<int> position, int xPivot, int yPivot);
    
    // Return all coordinates in shape...
    // Should I have a shape validator
    std::vector<int> getShape();
    char* getShapeName();

    private:

    char[10] name;
    std::vector<int> coordinates;
    int xPivot, int yPivot;

};

#endif