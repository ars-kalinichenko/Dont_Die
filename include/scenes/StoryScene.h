#ifndef GAME_STORYSCENE_H
#define GAME_STORYSCENE_H


#include "IScene.h"
#include "SceneManager.h"

class StoryScene : public IScene {
private:
    SceneManager *sceneManager;
    bool isRunning{};

    void run();

public:
    explicit StoryScene(SceneManager *sceneManager) : sceneManager(sceneManager) {};

    void start() override;

    void stop() override;

    ~StoryScene() override = default;

};


#endif //GAME_STORYSCENE_H
