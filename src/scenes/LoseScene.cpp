#include <systems/TerminalSystem.h>
#include <EventLog.h>
#include "scenes/LoseScene.h"
#include <memory>
#include <systems/KeyboardControlSystem.h>

using namespace std;

void LoseScene::start() {
    isRunning = true;
    run();
}

void LoseScene::run() {
    TerminalSystem terminalSystem;
    auto eventLog = make_unique<EventLog>();
    auto keyboard_input_system = make_unique<KeyboardControlSystem>(eventLog.get());
    terminalSystem.clear();
    terminal_printf(35, 3, "You lost.");
    terminal_printf(10, 6, "Switch to menu");
    terminal_printf(15, 7, "{esc}");
    terminal_printf(55, 6, "Start again");
    terminal_printf(58, 7, "{enter}");

    terminalSystem.update();
    while (isRunning) {
        keyboard_input_system->update();
        Event *event = eventLog->Get();
        string message = event->get_Message();
        if (message == "PRESS_ENTER") {
            sceneManager->set_scene("GameScene");
        }
        if (message == "PRESS_CLOSE") {
            sceneManager->set_scene("MenuScene");
        }


    }
}

void LoseScene::stop() {
    isRunning = false;
}
