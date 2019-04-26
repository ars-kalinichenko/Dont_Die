#ifndef GAME_LEVELLOADINGSYSTEM_H
#define GAME_LEVELLOADINGSYSTEM_H

#include <string>
#include <vector>
#include <Entity.h>
#include <EntityManager.h>
#include <scenes/SceneManager.h>
#include "System.h"

class LevelLoadingSystem : public System {
private:
    EntityManager *&entityManager;
    std::vector<std::string> path_to_levels;
    int current_level = -1;
    SceneManager *sceneManager;

    void loadNextLevel();

public:
    explicit LevelLoadingSystem(EntityManager *&entityManager, SceneManager *);

    void update() override;

    ~LevelLoadingSystem() override = default;

};


#endif //GAME_LEVELLOADINGSYSTEM_H
