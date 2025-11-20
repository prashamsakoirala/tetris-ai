// is a shapestate, just makes setnewshape accessible 
/*

*/
#include "ShapeState.hpp"

#ifndef ACTIVEPIECE
#define ACTIVEPIECE

class ActivePiece : public ShapeState {

    public:

    void setNewShape(Shape s);
    
};

#endif