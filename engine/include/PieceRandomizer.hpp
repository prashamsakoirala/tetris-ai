// should pass in a list of shapes
// should randomize the output shape

#include "ShapeState.hpp"

#ifndef ACTIVEPIECE
#define ACTIVEPIECE

class PieceRandomizer{

    public:

    PieceRandomizer(std::vector<Shape> shapes);
    Shape getNextPiece();

    private:
    std::vector<Shape> shapes;
    
};

#endif