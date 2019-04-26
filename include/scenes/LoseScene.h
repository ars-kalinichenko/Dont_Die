#ifndef GAME_LOSESCENE_H
#define GAME_LOSESCENE_H


#include "IScene.h"
#include "SceneManager.h"

class LoseScene : public IScene {
private:
    SceneManager *sceneManager;
    bool isRunning{};

    void run();

public:
    explicit LoseScene(SceneManager *sceneManager) : sceneManager(sceneManager) {};

    void start() override;

    void stop() override;

    ~LoseScene() override = default;

};


#endif //GAME_LOSESCENE_H
