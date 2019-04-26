#include "scenes/SceneManager.h"
#include <iostream>
#include <memory>
#include <scenes/MenuScene.h>
#include <scenes/GameScene.h>
#include <scenes/LoseScene.h>
#include <scenes/AboutScene.h>
#include <scenes/SettingsScene.h>
#include <scenes/StoryScene.h>
#include <scenes/WinScene.h>

using namespace std;

SceneManager::SceneManager() {
    named_scenes["GameScene"] = new GameScene(this);
    named_scenes["MenuScene"] = new MenuScene(this);
    named_scenes["LoseScene"] = new LoseScene(this);
    named_scenes["AboutScene"] = new AboutScene(this);
    named_scenes["SettingsScene"] = new SettingsScene(this);
    named_scenes["StoryScene"] = new StoryScene(this);
    named_scenes["WinScene"] = new WinScene(this);


}

void SceneManager::set_scene(const string &name) {
    if (current_scene != nullptr) {
        current_scene->stop();
    }
    if (named_scenes.count(name) > 0) {
        current_scene = named_scenes.at(name);
        current_scene->start();
    }
}
