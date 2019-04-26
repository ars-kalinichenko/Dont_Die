#ifndef GAME_COLLISIONSYSTEM_H
#define GAME_COLLISIONSYSTEM_H

#include <vector>
#include <systems/System.h>
#include <EntityManager.h>
#include "Entity.h"

class CollisionSystem : public System {
    EntityManager *entityManager;
public:
    explicit CollisionSystem(EntityManager *entityManager);

    void update() override;

    ~CollisionSystem() override = default;


};


#endif //GAME_COLLISIONSYSTEM_H
