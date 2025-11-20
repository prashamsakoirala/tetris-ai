#ifndef SHAPE
#define SHAPE
#include <vector>
#include <string>

using std::vector;
using std::string;

class Shape {
    public:
    
    Shape(string name, vector<vector<int>> position);
    
    vector<vector<int>> getShape();
    string getShapeName();

    private:

    string name;
    vector<vector<int>> position;

};

#endif