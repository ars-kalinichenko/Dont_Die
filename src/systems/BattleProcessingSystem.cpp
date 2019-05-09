#include <components/Collider.h>
#include <components/Vitals.h>
#include <components/Inventory.h>
#include "systems/BattleProcessingSystem.h"
#include <iostream>
#include <components/Position.h>

using namespace std;

BattleProcessingSystem::BattleProcessingSystem(EntityManager *&entityManager) : entityManager(entityManager) {}

void BattleProcessingSystem::update() {
    if (entityManager->get_all().empty()) {
        return;
    }
    for (auto player: entityManager->get_all_by_tag("Player")) {
        auto playerPos = player->get_component<Position>();

        for (auto manager: entityManager->get_all_by_tag("Manager")) {
            auto managerPos = manager->get_component<Position>();
            if (abs(managerPos->x_ - playerPos->x_) < 2 && abs(managerPos->y_ - playerPos->y_) < 2) {
                if (player->get_component<Vitals>()->power == 0) {
                    player->get_component<Vitals>()->hp -= 40;
                } else {
                    player->get_component<Vitals>()->hp -= 20;
                    player->get_component<Vitals>()->power += 300;
                }
                manager->remove();
            }
        }


        for (auto bug: entityManager->get_all_by_tag("Bug")) {
            auto bugPos = bug->get_component<Position>();
            if (abs(bugPos->x_ - playerPos->x_) < 2 && abs(bugPos->y_ - playerPos->y_) < 2) {
                if (player->get_component<Vitals>()->power >= 2) {
                    player->get_component<Vitals>()->power -= 2;
                } else { player->get_component<Vitals>()->power = 0; }
            }
        }


        for (auto deadline: entityManager->get_all_by_tag("Deadline")) {
            auto deadlinePos = deadline->get_component<Position>();
            if (abs(deadlinePos->x_ - playerPos->x_) < 2 && abs(deadlinePos->y_ - playerPos->y_) < 2) {
                player->get_component<Vitals>()->power = 0;
                deadline->remove();
            }
        }


        for (auto tester: entityManager->get_all_by_tag("Tester")) {
            for (auto pl: tester->get_component<Collider>()->collisions) {
                if (pl->get_type() == "Player" &&
                    !pl->get_component<Inventory>()->get_all_by_tag("TestersPotion").empty()) {
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
            auto developerPos = developer->get_component<Position>();
            if (abs(developerPos->x_ - playerPos->x_) < 2 && abs(developerPos->y_ - playerPos->y_) < 2) {
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







