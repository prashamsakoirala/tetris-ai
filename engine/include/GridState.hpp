#ifndef GRIDSTATE
#define GRIDSTATE
#include <vector>
#include <Grid.hpp>

using std::vector;

class GridState {
    public:
    
    GridState(Grid* grid, vector<vector<int>>& filledBlocks);
    
    GridState(Grid* grid);

    vector<vector<int>> getFilledBlocks();
    
    // add and then check and clear rows
    void addPiece(const vector<vector<int>>& pieceCoords); 

    private:
    Grid* grid;
    vector<vector<int>> filledBlocks;

    bool isValidCoordinate(int xCoordinate, int yCoordinate);
    void addCoordinate(int xCoordinate, int yCoordinate);

    void addMultipleCoordinates(const vector<vector<int>>& pieceCoords);

    bool isOccupied(int xPosition, int yPosition);
    bool inBounds(int xPosition, int yPosition);
    
    bool clearRow(int row);
    bool rowFilled(int row);
    bool checkAndClearRows();



};

#endif