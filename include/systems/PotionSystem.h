#ifndef GAME_POTIONSYSTEM_H
#define GAME_POTIONSYSTEM_H


#include <EntityManager.h>
#include "System.h"

class PotionSystem : public System {
private:
    EntityManager *&entityManager;
public:
    explicit PotionSystem(EntityManager *&entityManager);

    void update() override;

    ~PotionSystem() override = default;
};


#endif //GAME_POTIONSYSTEM_H
