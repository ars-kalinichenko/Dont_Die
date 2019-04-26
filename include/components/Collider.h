#ifndef GAME_COLLIDER_H
#define GAME_COLLIDER_H

#include <vector>
#include <Entity.h>

class Collider : public IComponent {
public:
    std::vector<Entity *> collisions;
};


#endif //GAME_COLLIDER_H
