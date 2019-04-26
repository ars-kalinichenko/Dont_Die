#ifndef GAME_INVENTORYCOLLECTIONSYSTEM_H
#define GAME_INVENTORYCOLLECTIONSYSTEM_H


#include <EntityManager.h>
#include "System.h"

class InventoryCollectionSystem : public System {
private:
    EntityManager *&entityManager;
public:
    explicit InventoryCollectionSystem(EntityManager *&entityManager);

    void update() override;

    ~InventoryCollectionSystem() override = default;

};


#endif //GAME_INVENTORYCOLLECTIONSYSTEM_H
