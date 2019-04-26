#ifndef GAME_SETTINGSSCENE_H
#define GAME_SETTINGSSCENE_H


#include "SceneManager.h"

class SettingsScene : public IScene {
private:
    SceneManager *sceneManager;
    bool isRunning{};

    void run();

public:
    explicit SettingsScene(SceneManager *sceneManager) : sceneManager(sceneManager) {};

    void start() override;

    void stop() override;

    ~SettingsScene() override = default;

};


#endif //GAME_SETTINGSSCENE_H
