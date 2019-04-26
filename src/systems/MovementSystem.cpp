#include <systems/MovementSystem.h>
#include <components/Position.h>
#include <components/RigidBody.h>

#include "systems/MovementSystem.h"

MovementSystem::MovementSystem(EntityManager *&entityManager) : entityManager(entityManager) {}

void MovementSystem::update() {
    for (auto entity: entityManager->get_all()) {
        if (entity->has_component<Position>() && entity->has_component<RigidBody>()) {
            auto rb_entity = entity->get_component<RigidBody>();
            entity->get_component<Position>()->x_ += rb_entity->force_x;
            entity->get_component<Position>()->y_ += rb_entity->force_y;
        }
    }
}