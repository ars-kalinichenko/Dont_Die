#ifndef GAME_GRAPHICS_H
#define GAME_GRAPHICS_H

#include <string>
#include "IComponent.h"

class Graphics : public IComponent {
public:
    int symbol;
    char *color;

    Graphics(int symbol, char *color);

    ~Graphics() override = default;
};


#endif //GAME_GRAPHICS_H
