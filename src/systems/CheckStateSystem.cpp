#include <systems/CheckStateSystem.h>
#include <EventLog.h>

#include "systems/CheckStateSystem.h"
#include <string>
#include <components/Vitals.h>

using namespace std;

CheckStateSystem::CheckStateSystem(EntityManager *entityManager, EventLog *eventLog, SceneManager *sceneManager)
        : entityManager(entityManager), eventLog(eventLog), sceneManager(sceneManager) {}

void CheckStateSystem::update() {
    Event *event = eventLog->Get();
    string message = event->get_Message();

    if (message == "PRESS_CLOSE") {
        sceneManager->set_scene("MenuScene");
    }

    if (entityManager->get_all_by_tag("Player").at(0)->get_component<Vitals>()->hp <= 0) {
        sceneManager->set_scene("LoseScene");
    }
}
