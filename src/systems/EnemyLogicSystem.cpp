#include <components/Position.h>
#include <components/Graphics.h>
#include <components/RigidBody.h>
#include <systems/EnemyLogicSystem.h>
#include <components/Collider.h>
#include <components/EnemyBehaviour.h>
#include <chrono>
#include <components/Vitals.h>

using namespace std;

#include "systems/EnemyLogicSystem.h"

EnemyLogicSystem::EnemyLogicSystem(EntityManager *&entityManager) : entityManager(entityManager) {
    start = chrono::high_resolution_clock::now();
}

void EnemyLogicSystem::update() {

    auto stop = chrono::high_resolution_clock::now();
    auto deltaTime = chrono::duration_cast<chrono::milliseconds>(stop - start).count();

    for (auto enemy: entityManager->get_all()) {
        if (enemy->get_type() == "Manager" || enemy->get_type() == "Deadline" || enemy->get_type() == "Bug") {
            if (enemy->has_component<Position>()) {
                auto enemyPos = enemy->get_component<Position>();

                auto enemyForce = enemy->get_component<RigidBody>();
                enemyForce->force_x = 0;
                enemyForce->force_y = 0;

                for (auto player: entityManager->get_all_by_tag("Player")) {
                    auto delta = new Position(0, 0, 0);
                    auto playerPos = player->get_component<Position>();
                    delta->x_ = playerPos->x_ - enemyPos->x_;
                    delta->y_ = playerPos->y_ - enemyPos->y_;
                    if (deltaTime > 690) {
                        if (abs(delta->x_) < 5 && abs(delta->y_) < 4) {
                            pursuit_movement(enemy, delta);
                        } else {
                            free_movement(enemy);
                        }
                    }
                }
            }
        }
    }
    if (deltaTime > 705) {
        start = stop;
    }
}

void EnemyLogicSystem::free_movement(Entity *enemy) {

    Position *direction = enemy->get_component<EnemyBehaviour>()->direction;
    auto enemyForce = enemy->get_component<RigidBody>();
    if (enemy->get_component<Collider>()->collisions.empty()) {
        enemyForce->force_x = direction->x_;
        enemyForce->force_y = direction->y_;
    } else {
        direction->x_ = -direction->x_;
        direction->y_ = -direction->y_;
        enemyForce->force_x = direction->x_;
        enemyForce->force_y = direction->y_;
    }
}


void EnemyLogicSystem::pursuit_movement(Entity *enemy, Position *delta) {
    if (!enemy->has_component<Graphics>()) {
        enemy->put_component(new Graphics(222, const_cast<char*> ("#751100")));
    }
    auto enemyForce = enemy->get_component<RigidBody>();
    enemyForce->force_x = 0;
    enemyForce->force_y = 0;
    if (delta->x_ > 1) {
        enemyForce->force_x = 1;
    }
    if (delta->x_ < -1) {
        enemyForce->force_x = -1;
    }
    if (delta->y_ > 1) {
        enemyForce->force_y = 1;
    }
    if (delta->y_ < -1) {
        enemyForce->force_y = -1;
    }
}
