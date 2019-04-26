#ifndef GAME_CHECKSTATESYSTEM_H
#define GAME_CHECKSTATESYSTEM_H


#include <EntityManager.h>
#include <EventLog.h>
#include <scenes/SceneManager.h>
#include "System.h"

class CheckStateSystem : public System {
private:
    EntityManager *entityManager;
    EventLog *eventLog;
    SceneManager *sceneManager;
public:
    CheckStateSystem(EntityManager *, EventLog *, SceneManager *);

    void update() override;

    ~CheckStateSystem() override = default;
};


#endif //GAME_CHECKSTATESYSTEM_H
