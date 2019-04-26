#ifndef GAME_IGRAPHICS_H
#define GAME_IGRAPHICS_H

#include "Position.h"

class IGraphics {
    virtual void render(Position *) = 0;
};


#endif //GAME_IGRAPHICS_H
