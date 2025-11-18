#ifndef GRIDSTATE
#define GRIDSTATE
#include <vector>
#include <Grid.hpp>

using std::vector;

class GridState {
    public:
    
    GridState(Grid* grid, vector<vector<int>>& filledBlocks);
    
    GridState(Grid* grid);

    bool isOccupied(int xPosition, int yPosition);
    
    bool addCoordinate(int xCoordinate, int yCoordinate);

    bool inBounds(int xPosition, int yPosition);

    private:
    Grid* grid;
    vector<vector<int>> filledBlocks;
    
    bool clearRow(int row);
    bool rowFilled(int row);

    bool checkAndClearRows();


};

#endif