#include <components/Collider.h>
#include "systems/InventoryCollectionSystem.h"
#include <algorithm>
#include <iostream>
#include <components/Inventory.h>

using namespace std;

InventoryCollectionSystem::InventoryCollectionSystem(EntityManager *&entityManager) : entityManager(entityManager) {}

void InventoryCollectionSystem::update() {
    if (entityManager->get_all().empty()) {
        return;
    }
    for (auto player : entityManager->get_all_by_tag("Player")) {
        auto collider = player->get_component<Collider>();
        for (auto tile : collider->collisions) {
            if (tile->get_type() == "TestersPotion" || tile->get_type() == "Key") {
                if (tile->get_type() == "TestersPotion") {
                    cerr << "Вы подобрали ключ от подвала. Найдите тестировщика." << endl;
                }
                if (tile->get_type() == "Key") {
                    cerr << "Вы подобрали ключ от двери." << endl;
                }
                player->get_component<Inventory>()->add_entity(tile);
                collider->collisions.erase(remove(collider->collisions.begin(), collider->collisions.end(), tile),
                                           collider->collisions.end());
                tile->remove();
            }
        }
    }
}
