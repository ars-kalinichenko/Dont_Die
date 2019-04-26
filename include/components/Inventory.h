#ifndef GAME_INVENTORY_H
#define GAME_INVENTORY_H

#include <vector>
#include <Entity.h>

#include "IComponent.h"

class Inventory : public IComponent {
private:
    std::vector<Entity *> bag;
public:

    std::vector<Entity *> &get_all();

    std::vector<Entity *> get_all_by_tag(const std::string &tag);

    void add_entity(Entity *entity);

    void clear();

    ~Inventory() override = default;
};


#endif //GAME_INVENTORY_H
