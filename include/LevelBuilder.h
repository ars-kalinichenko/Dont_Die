#ifndef GAME_LEVELBUILDER_H
#define GAME_LEVELBUILDER_H

#include "Entity.h"
#include "ILevelBuilder.h"
#include "IReader.h"
#include <fstream>

class LevelBuilder : public ILevelBuilder {
private:
    IReader *reader;


public:
    std::vector<Entity *> build() override;

    Entity *player_tile = new Entity("Player");

    explicit LevelBuilder(IReader *);

    ~LevelBuilder() override = default;
};

#endif //GAME_LEVELBUILDER_H
