#ifndef GAME_ENTITYMANAGER_H
#define GAME_ENTITYMANAGER_H


#include <vector>
#include "Entity.h"

class EntityManager {
private:
    std::vector<Entity *> entities;
public:
    std::vector<Entity *> &get_all();

    std::vector<Entity *> get_all_by_tag(const std::string &tag);

    void add_entity(Entity *entity);

    void clear();

    ~EntityManager() = default;
};


#endif //GAME_ENTITYMANAGER_H
