#include <memory>
#include <systems/LevelLoadingSystem.h>
#include <LevelBuilder.h>
#include <FileReader.h>
#include <EntityManager.h>
#include <components/Collider.h>
#include <iostream>
#include <systems/TerminalSystem.h>
#include <EventLog.h>
#include <systems/KeyboardControlSystem.h>
#include <systems/PlayerMovementSystem.h>
#include <systems/StarsCollectionSystem.h>
#include <systems/DeleteSystem.h>
#include <systems/RigidBodySystem.h>
#include <systems/CollisionSystem.h>
#include <systems/RenderSystem.h>
#include <components/Inventory.h>


#include "systems/LevelLoadingSystem.h"

using namespace std;

LevelLoadingSystem::LevelLoadingSystem(EntityManager *&entityManager, SceneManager *sceneManager) : entityManager(
        entityManager), sceneManager(sceneManager) {
    path_to_levels.emplace_back("../../res/game/maps/1");
    path_to_levels.emplace_back("../../res/game/maps/2");
    path_to_levels.emplace_back("../../res/game/maps/3");

}

void LevelLoadingSystem::update() {
    if (current_level < 0) {
        loadNextLevel();
    }
//    char level[20];
//    sprintf(level, "../../res/game/maps/%i", 12);

    for (auto player : entityManager->get_all_by_tag("Player")) {
        if (player->has_component<Collider>()) {
            auto collider = player->get_component<Collider>();
            for (auto tile : collider->collisions) {
                if (tile->get_type() == "Door") {
                    if (!entityManager->get_all_by_tag("Bug").empty()) {
                        cerr
                                << "{Освободите тестировщика из подвала (требуется ключ - ¤)\nи в знак благодарности он пофиксит все баги}"
                                << endl;

                    } else if (!entityManager->get_all_by_tag("Key").empty()) {
                        cerr << "{Чтобы открыть дверь, нужен ключ (¢). Верно?}" << endl;
                    } else {
                        for (auto entity : entityManager->get_all()) {
                            entity->remove();
                        }
                        loadNextLevel();
                        cerr << endl << endl;
                    }
                }
            }
        }
    }
}

void LevelLoadingSystem::loadNextLevel() {

    current_level++;
    if (current_level > (int) path_to_levels.size() - 1) {
        sceneManager->set_scene("WinScene");
    }
    auto p = make_unique<FileReader>(path_to_levels[current_level]);
    auto map_generating = make_unique<LevelBuilder>(p.get());
    for (auto t : map_generating->build()) {
        entityManager->add_entity(t);
    }
}
