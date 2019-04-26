#ifndef GAME_STARSCOLLECTIONSYSTEM_H
#define GAME_STARSCOLLECTIONSYSTEM_H

#include <EntityManager.h>
#include "System.h"

class StarsCollectionSystem : public System {
    EntityManager *&entityManager;
    int stars = 0;
public:

    explicit StarsCollectionSystem(EntityManager *&entityManager);

    void update() override;

    ~StarsCollectionSystem() override = default;
};


#endif //GAME_STARSCOLLECTIONSYSTEM_H
