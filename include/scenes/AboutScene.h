#ifndef GAME_ABOUTSCENE_H
#define GAME_ABOUTSCENE_H


#include "IScene.h"
#include "SceneManager.h"

class AboutScene : public IScene {
private:
    SceneManager *sceneManager;
    bool isRunning{};

    void run();

public:
    explicit AboutScene(SceneManager *sceneManager) : sceneManager(sceneManager) {};

    void start() override;

    void stop() override;

    ~AboutScene() override = default;
};


#endif //GAME_ABOUTSCENE_H
