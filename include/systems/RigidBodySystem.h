#ifndef GAME_RIGIDBODYSYSTEM_H
#define GAME_RIGIDBODYSYSTEM_H


#include <Entity.h>
#include <vector>
#include <EntityManager.h>

#include "System.h"

class RigidBodySystem : public System {
    EntityManager *&entityManager;
public:
    explicit RigidBodySystem(EntityManager *&entityManager);

    void update() override;

    ~RigidBodySystem() override = default;
};


#endif //GAME_RIGIDBODYSYSTEM_H
