#include <components/Position.h>
#include <components/RigidBody.h>
#include <systems/CollisionSystem.h>

#include "systems/CollisionSystem.h"
#include "components/Collider.h"

#include <chrono>
#include <iostream>

using namespace std;

CollisionSystem::CollisionSystem(EntityManager *entityManager) : entityManager(entityManager) {}

void CollisionSystem::update() {
    map<Position, vector<Entity *>> collisions;

    for (auto entity : entityManager->get_all()) {
        if (entity->has_component<Collider>() && entity->has_component<Position>()) {
            auto collider = entity->get_component<Collider>();
            auto pos = entity->get_component<Position>();
            collider->collisions.clear();

            collisions[*pos].push_back(entity);

            for (auto collided_entity : collisions[*pos]) {
                if (collided_entity != entity) {
                    collider->collisions.push_back(collided_entity);
                    collided_entity->get_component<Collider>()->collisions.push_back(entity);
                }
            }
        }
    }
}
