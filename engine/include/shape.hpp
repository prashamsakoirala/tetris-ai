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
    Shape(string name, vector<vector<int>> position);
    
    // Return all coordinates in shape...
    // Should I have a shape validator
    vector<vector<int>> getShape();
    string getShapeName();

    private:

    string name;
    vector<vector<int>> position;

};

#endif