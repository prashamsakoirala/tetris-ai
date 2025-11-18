#ifndef SHAPE
#define SHAPE
#include <vector>
#include <string>

class Shape {
    public:
    // Initalize shape, just get shape by returning coordinates
    // Constructor
    // validates based on rulebook? or constraints?
    Shape(std::string name, std::vector<int> position, int xPivot, int yPivot);
    
    // Return all coordinates in shape...
    // Should I have a shape validator
    std::vector<int> getShape();
    std::string getShapeName();

    private:

    std::string name;
    std::vector<int> position;
    int xPivot, int yPivot;

};

#endif