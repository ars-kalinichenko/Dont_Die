#include <systems/CameraMovementSystem.h>
#include <EntityManager.h>
#include <memory>
#include <components/RigidBody.h>
#include <components/Position.h>
#include "systems/CameraMovementSystem.h"

CameraMovementSystem::CameraMovementSystem(EntityManager *&entityManager) : entityManager(
        entityManager) {}

void CameraMovementSystem::update() {

    for (auto player: entityManager->get_all_by_tag("Player")) {
        if (player->has_component<Position>()) {
            auto playerPosition = player->get_component<Position>();
            for (auto camera: entityManager->get_all_by_tag("Camera")) {
                auto camPosition = camera->get_component<Position>();
                if (abs(camPosition->x_ - playerPosition->x_) > 10 || abs(camPosition->y_ - playerPosition->y_) > 10) {
                    while (camPosition->x_ != playerPosition->x_ || camPosition->y_ != playerPosition->y_) {

                        if (playerPosition->x_ - camPosition->x_ > 10) {
                            camPosition->x_ += 1;
                        }
                        if (playerPosition->y_ - camPosition->y_ > 10) {
                            camPosition->y_ += 1;
                        }
                        if (playerPosition->x_ - camPosition->x_ < -10) {
                            camPosition->x_ -= 1;
                        }
                        if (playerPosition->y_ - camPosition->y_ < -10) {
                            camPosition->y_ -= 1;
                        }
                        return;
                    }

                }
            }
        }
    }
}
