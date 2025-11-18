#ifndef SHAPE
#define SHAPE
#include <vector>
#include <string>

using std::vector;
using std::string;

class Shape {
    public:
    // Initalize shape, just get shape by returning coordinates
    // Constructor
    // validates based on rulebook? or constraints?
    Shape(string name, vector<vector<int>> position, int xPivot, int yPivot);
    
    // Return all coordinates in shape...
    // Should I have a shape validator
    vector<vector<int>> getShape();
    string getShapeName();
    int getShapeXPivot();
    int getShapeYPivot();

    private:

    string name;
    vector<vector<int>> position;

};

#endif