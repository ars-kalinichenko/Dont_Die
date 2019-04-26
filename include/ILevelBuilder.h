#ifndef GAME_ILVLBUILDER_H
#define GAME_ILVLBUILDER_H

#include <vector>
#include "Entity.h"

class ILevelBuilder {
public:
    virtual std::vector<Entity *> build() = 0;

    virtual ~ILevelBuilder() = default;
};

#endif //GAME_ILVLBUILDER_H
