#include <components/Collider.h>
#include <components/Vitals.h>
#include "systems/PotionSystem.h"
#include <iostream>

using namespace std;

PotionSystem::PotionSystem(EntityManager *&entityManager) : entityManager(entityManager) {}

void PotionSystem::update() {
    for (auto player: entityManager->get_all_by_tag("Player")) {
        if (player->has_component<Collider>()) {
            auto collider = player->get_component<Collider>();
            for (auto potion: collider->collisions) {
                if (potion->get_type() == "HealthPotion") {
                    player->get_component<Vitals>()->hp += 5;
                    player->get_component<Vitals>()->power += 100;
                    cerr << "Вы скушали яблочко." << endl;
                    potion->remove();
                }
                if (potion->get_type() == "ManagerDeadPotion") {
                    for (auto manager: entityManager->get_all_by_tag("Manager")) {
                        manager->remove();
                    }
                    cerr << "Неужели теперь нет манагеров?! Свобода!" << endl;
                    potion->remove();
                }
                if (potion->get_type() == "DeadlineDeadPotion") {
                    for (auto deadline: entityManager->get_all_by_tag("Deadline")) {
                        deadline->remove();
                    }
                    cerr << "Петля времени активирована, Стрендж. К чёрту дедлайны!" << endl;
                    potion->remove();
                }
            }
        }
    }
}
