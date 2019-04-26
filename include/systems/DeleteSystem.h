#ifndef GAME_DELETESYSTEM_H
#define GAME_DELETESYSTEM_H


#include <EntityManager.h>
#include "System.h"

class DeleteSystem : public System {
    EntityManager *entityManager;
public:
    explicit DeleteSystem(EntityManager *entityManager);

    void update() override;

    ~DeleteSystem() override = default;
};


#endif //GAME_DELETESYSTEM_H
