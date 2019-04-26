#ifndef GAME_PLAYERMOVEMENTSYSTEM_H
#define GAME_PLAYERMOVEMENTSYSTEM_H

#include <systems/System.h>
#include <EventLog.h>
#include <vector>
#include <EntityManager.h>
#include "Entity.h"

class PlayerMovementSystem : public System {
    EntityManager *&entityManager;
    EventLog *eventLog;
    int last_event_id = -1;
public:
    explicit PlayerMovementSystem(EntityManager *&entityManager, EventLog *eventLog);

    void update() override;

    ~PlayerMovementSystem() override = default;
};

#endif  // GAME_PLAYERMOVEMENTSYSTEM_H
