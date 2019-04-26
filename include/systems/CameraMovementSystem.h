#ifndef GAME_CAMERAMOVEMENTSYSTEM_H
#define GAME_CAMERAMOVEMENTSYSTEM_H


#include <EntityManager.h>
#include <EventLog.h>
#include "System.h"

class CameraMovementSystem : public System {
private:
    EntityManager *&entityManager;

public:
    explicit CameraMovementSystem(EntityManager *&entityManager);

    void update() override;

    ~CameraMovementSystem() override = default;
};


#endif //GAME_CAMERAMOVEMENTSYSTEM_H
