#pragma once

#ifndef GAME_SCENEMANAGER_H
#define GAME_SCENEMANAGER_H

#include <memory>
#include <vector>
#include <string>
#include <map>

#include "IScene.h"

class SceneManager {
    IScene *current_scene = nullptr;
    std::map<std::string, IScene *> named_scenes;
public:
    SceneManager();

    void set_scene(const std::string &name);
};

#endif //GAME_SCENEMANAGER_H
