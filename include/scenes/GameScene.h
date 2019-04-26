#ifndef GAME_LEVELS_H
#define GAME_LEVELS_H

#include<chrono>
#include <EventLog.h>
#include "IScene.h"
#include "SceneManager.h"

class GameScene : public IScene {
private:
    SceneManager *sceneManager;
    bool isRunning{};

    void run();

public:
    explicit GameScene(SceneManager *sceneManager) : sceneManager(sceneManager) {};

    void start() override;

    void stop() override;

    ~GameScene() override = default;
};


#endif //GAME_LEVELS_H
