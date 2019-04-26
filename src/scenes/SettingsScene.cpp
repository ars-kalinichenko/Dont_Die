#include <systems/TerminalSystem.h>
#include "scenes/SettingsScene.h"
#include <memory>
#include <systems/KeyboardControlSystem.h>

using namespace std;

void SettingsScene::start() {
    isRunning = true;
    run();
}

void SettingsScene::run() {
    TerminalSystem terminalSystem;
    auto eventLog = make_unique<EventLog>();
    auto keyboard_input_system = make_unique<KeyboardControlSystem>(eventLog.get());

    terminalSystem.clear();
    terminal_color(color_from_name((char *) "black"));
    terminal_printf(5, 3, "Keyboard {F1}");
    terminal_printf(5, 5, "Gameplay {F2}");
    terminal_printf(5, 7, "Read docs {F3}");
    terminal_printf(5, 9, "Exit {esc}");
    terminalSystem.update();

    while (isRunning) {
        keyboard_input_system->update();
        Event *event = eventLog->Get();
        string message = event->get_Message();

        if (message == "PRESS_F1") {
            system("xdg-open ../../res/config/Config_Keyboard");
            eventLog->Put(new Event("NULL"));
        }

        if (message == "PRESS_F3") {
            system("xdg-open ../../res/config/Docs");
            eventLog->Put(new Event("NULL"));
        }

        if (message == "PRESS_CLOSE") {
            sceneManager->set_scene("MenuScene");
        }


    }
}

void SettingsScene::stop() {
    isRunning = false;
}
