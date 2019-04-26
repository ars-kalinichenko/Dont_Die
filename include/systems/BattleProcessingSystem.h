#ifndef GAME_BATTLEPROCESSINGSYSTEM_H
#define GAME_BATTLEPROCESSINGSYSTEM_H


#include <EntityManager.h>
#include "System.h"

class BattleProcessingSystem : public System {
private:
    EntityManager *&entityManager;
public:
    explicit BattleProcessingSystem(EntityManager *&entityManager);

    void update() override;

    ~BattleProcessingSystem() override = default;
};


#endif //GAME_BATTLEPROCESSINGSYSTEM_H
