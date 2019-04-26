#include <utility>
#include <components/Collider.h>
#include <algorithm>
#include <systems/CollisionSystem.h>
#include <iostream>
#include <BearLibTerminal.h>
#include "systems/StarsCollectionSystem.h"

using namespace std;

StarsCollectionSystem::StarsCollectionSystem(EntityManager *&entityManager) : entityManager(entityManager) {}

void StarsCollectionSystem::update() {

    string count_st = to_string(stars);
    char const *stars_char = count_st.c_str();
    terminal_printf(0, 0, "Stars:");
    terminal_printf(7, 0, stars_char);

    if (entityManager->get_all().empty()) {
        return;
    }
    for (auto player : entityManager->get_all_by_tag("Player")) {
        auto collider = player->get_component<Collider>();
        for (auto tile : collider->collisions) {
            if (tile->get_type() != "Star") {
                return;
            }
            collider->collisions.erase(remove(collider->collisions.begin(), collider->collisions.end(), tile),
                                       collider->collisions.end());
            tile->remove();
            ++stars;
        }
    }
}


