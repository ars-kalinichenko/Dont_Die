#ifndef GAME_MOVEMENTSYSTEM_H
#define GAME_MOVEMENTSYSTEM_H

#include <systems/System.h>
#include <EventLog.h>
#include <Entity.h>
#include <EntityManager.h>

class MovementSystem : public System {
    EntityManager *&entityManager;

public:
    explicit MovementSystem(EntityManager *&);

    void update() override;

    ~MovementSystem() override = default;
};


#endif //GAME_MOVEMENTSYSTEM_H
