#include <systems/System.h>
#include <components/Position.h>
#include <components/RigidBody.h>
#include <memory>
#include <components/Collider.h>
#include "systems/RigidBodySystem.h"

RigidBodySystem::RigidBodySystem(EntityManager *&entityManager) : entityManager(entityManager) {}

void RigidBodySystem::update() {
    for (auto tile: entityManager->get_all()) {
        if (!tile->has_component<RigidBody>() || !tile->has_component<Collider>()) {
            continue;
        }

        auto collisions = tile->get_component<Collider>()->collisions;

        for (auto &collision : collisions) {
            if (collision->has_component<RigidBody>() && collision->has_component<Position>()) {
                collision->get_component<Position>()->x_ -= collision->get_component<RigidBody>()->force_x;
                collision->get_component<Position>()->y_ -= collision->get_component<RigidBody>()->force_y;
            }
        }
    }
}



