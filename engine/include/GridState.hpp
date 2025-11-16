#ifndef GRIDSTATE
#define GRIDSTATE
#include <Grid.hpp>
#include <vector>


class GridState {
    public:
    
    GridState(Grid* grid, std::vector<int> filledBlocks);
    
    GridState(Grid* grid);

    bool isCollision(int xPosition, int yPosition);
    
    bool addCoordinate(int xCoordinate, int yCoordinate);

    bool inBounds(int xPosition, int yPosition);

    private:
    Grid* grid;
    std::vector<int> filledBlocks;
    
    bool clearRow(int row);
    bool rowFilled(int row);

    bool checkAndClearRows();


};

#endif