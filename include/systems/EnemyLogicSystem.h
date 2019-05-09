#ifndef GAME_ENEMYLOGICSYSTEM_H
#define GAME_ENEMYLOGICSYSTEM_H


#include <EntityManager.h>
#include <components/Position.h>
#include <chrono>
#include "systems/System.h"

class EnemyLogicSystem : public System {
private:
    EntityManager *&entityManager;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

public:
    explicit EnemyLogicSystem(EntityManager *&entityManager);

    void update() override;

    static void free_movement(Entity *enemy);

    static void pursuit_movement(Entity *enemy, Position *delta);

    ~EnemyLogicSystem() override = default;

};


#endif //GAME_ENEMYLOGICSYSTEM_H
