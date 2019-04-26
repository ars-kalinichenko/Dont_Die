#ifndef GAME_TITLE_H
#define GAME_TITLE_H


#include <EventLog.h>
#include "IScene.h"
#include "SceneManager.h"

class MenuScene : public IScene {
private:
    SceneManager *sceneManager;
    bool isRunning{};

    void run();

public:
    explicit MenuScene(SceneManager *sceneManager) : sceneManager(sceneManager) {}

    void start() override;

    void stop() override;

    ~MenuScene() override = default;
};


#endif //GAME_TITLE_H
