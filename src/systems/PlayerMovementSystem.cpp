#include <EventLog.h>
#include <Entity.h>
#include <BearLibTerminal.h>
#include <systems/PlayerMovementSystem.h>
#include <iostream>
#include <components/Position.h>
#include <components/RigidBody.h>
#include <systems/CollisionSystem.h>
#include <LevelBuilder.h>
#include <FileReader.h>
#include <memory>
#include <systems/RigidBodySystem.h>


using namespace std;

PlayerMovementSystem::PlayerMovementSystem(EntityManager *&entityManager, EventLog *eventLog) : entityManager(
        entityManager), eventLog(eventLog) {}


void PlayerMovementSystem::update() {
    Event *event = eventLog->Get();
    string message = event->get_Message();

    for (auto player : entityManager->get_all_by_tag("Player")) {
        if (!player->has_component<RigidBody>()) {
            continue;
        }

        auto rb = player->get_component<RigidBody>();
        rb->force_x = 0;
        rb->force_y = 0;

        if (last_event_id == event->get_Id()) {
            continue;
        }

        if (message == "PRESS_DOWN") {
            rb->force_y = 1;
        } else if (message == "PRESS_UP") {
            rb->force_y = -1;
        } else if (message == "PRESS_LEFT") {
            rb->force_x = -1;
        } else if (message == "PRESS_RIGHT") {
            rb->force_x = 1;
        }
    }
    last_event_id = event->get_Id();
}


