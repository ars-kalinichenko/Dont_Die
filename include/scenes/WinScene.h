#ifndef GAME_WINSCENE_H
#define GAME_WINSCENE_H

#include "IScene.h"
#include "SceneManager.h"

class WinScene : public IScene {
private:
    SceneManager *sceneManager;
    bool isRunning{};

    void run();

public:
    explicit WinScene(SceneManager *sceneManager) : sceneManager(sceneManager) {};

    void start() override;

    void stop() override;

    ~WinScene() override = default;

};


#endif //GAME_WINSCENE_H
