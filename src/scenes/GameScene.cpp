#include <systems/TerminalSystem.h>
#include <memory>
#include <systems/PlayerMovementSystem.h>
#include <systems/KeyboardControlSystem.h>
#include <systems/CollisionSystem.h>
#include <systems/CameraMovementSystem.h>
#include <systems/PotionSystem.h>
#include <systems/RigidBodySystem.h>
#include <systems/StarsCollectionSystem.h>
#include <systems/RenderSystem.h>
#include <systems/LevelLoadingSystem.h>
#include <systems/DeleteSystem.h>
#include <systems/BattleProcessingSystem.h>
#include <components/Vitals.h>
#include <systems/TimeFlowSystem.h>
#include <systems/MovementSystem.h>
#include <systems/CountersSystem.h>
#include <systems/EnemyLogicSystem.h>
#include <systems/CheckStateSystem.h>
#include <systems/InventoryCollectionSystem.h>
#include "scenes/GameScene.h"

using namespace std;

void GameScene::start() {
    isRunning = true;
    run();
}

void GameScene::run() {

    TerminalSystem terminal;
    auto entityManager = new EntityManager();
    auto eventLog = make_unique<EventLog>();
    vector<unique_ptr<System>> systems;
    systems.push_back(make_unique<RenderSystem>(entityManager));
    systems.push_back(make_unique<KeyboardControlSystem>(eventLog.get()));
    systems.push_back(make_unique<PlayerMovementSystem>(entityManager, eventLog.get()));
    systems.push_back(make_unique<EnemyLogicSystem>(entityManager));
    systems.push_back(make_unique<MovementSystem>(entityManager));
    systems.push_back(make_unique<CollisionSystem>(entityManager));
    systems.push_back(make_unique<RigidBodySystem>(entityManager));
    systems.push_back(make_unique<BattleProcessingSystem>(entityManager));
    systems.push_back(make_unique<InventoryCollectionSystem>(entityManager));
    systems.push_back(make_unique<StarsCollectionSystem>(entityManager));
    systems.push_back(make_unique<PotionSystem>(entityManager));
    systems.push_back(make_unique<LevelLoadingSystem>(entityManager, sceneManager));
    systems.push_back(make_unique<CountersSystem>(entityManager));
    systems.push_back(make_unique<CheckStateSystem>(entityManager, eventLog.get(), sceneManager));
    systems.push_back(make_unique<CameraMovementSystem>(entityManager));
    systems.push_back(make_unique<DeleteSystem>(entityManager));


    while (isRunning) {
        terminal.clear();

        for (auto &sys : systems) {
            sys->update();
        }

        terminal.update();
    }
}

void GameScene::stop() {
    isRunning = false;
}

