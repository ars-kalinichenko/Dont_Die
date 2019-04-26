#ifndef GAME_COUNTERSSYSTEM_H
#define GAME_COUNTERSSYSTEM_H

#include <memory>
#include "System.h"
#include "TimeFlowSystem.h"
#include "StarsCollectionSystem.h"

class CountersSystem : public System {
private:
    EntityManager *entityManager;
    std::unique_ptr<TimeFlowSystem> time_flow;
public:
    explicit CountersSystem(EntityManager *);

    void update() override;

    ~CountersSystem() override = default;
};


#endif //GAME_COUNTERSSYSTEM_H
