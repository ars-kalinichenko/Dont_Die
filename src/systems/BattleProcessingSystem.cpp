#include <components/Collider.h>
#include <components/Vitals.h>
#include <components/Inventory.h>
#include "systems/BattleProcessingSystem.h"
#include <iostream>

using namespace std;

BattleProcessingSystem::BattleProcessingSystem(EntityManager *&entityManager) : entityManager(entityManager) {}

void BattleProcessingSystem::update() {
    if (!entityManager->get_all().empty()) {
        for (auto manager: entityManager->get_all_by_tag("Manager")) {
            for (auto player: manager->get_component<Collider>()->collisions) {
                if (player->get_type() == "Player") {
                    if (player->get_component<Vitals>()->power == 0) {
                        player->get_component<Vitals>()->hp -= 40;
                    } else {
                        player->get_component<Vitals>()->hp -= 20;
                        player->get_component<Vitals>()->power += 300;
                    }
                    manager->remove();
                }
            }
        }
        for (auto bug: entityManager->get_all_by_tag("Bug")) {
            for (auto player: bug->get_component<Collider>()->collisions) {
                if (player->get_type() == "Player") {
                    if (player->get_component<Vitals>()->power >= 10) {
                        player->get_component<Vitals>()->power -= 10;
                    } else { player->get_component<Vitals>()->power = 0; }
                }
            }
        }
        for (auto deadline: entityManager->get_all_by_tag("Deadline")) {
            for (auto player: deadline->get_component<Collider>()->collisions) {
                if (player->get_type() == "Player") {
                    player->get_component<Vitals>()->power = 0;
                    deadline->remove();
                }
            }
        }

        for (auto tester: entityManager->get_all_by_tag("Tester")) {
            for (auto player: tester->get_component<Collider>()->collisions) {
                if (player->get_type() == "Player" &&
                    !player->get_component<Inventory>()->get_all_by_tag("TestersPotion").empty()) {
                    tester->remove();
                    cerr << "-Спасибо! Иди с миром и не обращай внимания на баги" << endl;
                    for (auto bug: entityManager->get_all_by_tag("Bug")) {
                        bug->remove();
                    }
                } else {
                    cerr << "-Ты не сможешь меня выручить, если у тебя нет ключа." << endl;
                }
            }
        }
        for (auto developer: entityManager->get_all_by_tag("MadDeveloper")) {
            for (auto player: developer->get_component<Collider>()->collisions) {
                if (player->get_type() == "Player") {
                    if (player->get_component<Vitals>()->power == 0) {
                        player->get_component<Vitals>()->hp -= 30;
                    } else { player->get_component<Vitals>()->hp -= 15; }
                    if (player->get_component<Vitals>()->power >= 400) {
                        player->get_component<Vitals>()->power -= 400;
                    } else { player->get_component<Vitals>()->power = 0; }
                    developer->remove();
                }
            }
        }
    }
}
