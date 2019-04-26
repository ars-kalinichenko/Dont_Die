#include <systems/TerminalSystem.h>
#include "scenes/WinScene.h"
#include <memory>
#include <EventLog.h>
#include <BearLibTerminal.h>
#include <systems/KeyboardControlSystem.h>

using namespace std;

void WinScene::start() {
    isRunning = true;
    run();
}

void WinScene::run() {
    TerminalSystem terminalSystem;
    auto eventLog = make_unique<EventLog>();
    auto keyboard_input_system = make_unique<KeyboardControlSystem>(eventLog.get());
    terminalSystem.clear();
    terminal_printf(30, 3, "Congratulations!");
    terminal_printf(35, 4, "You win.");
    terminal_printf(10, 10, "Switch to menu");
    terminal_printf(15, 11, "{esc}");
    terminal_printf(55, 10, "Watch anime");
    terminal_printf(58, 11, "{F}");

    terminalSystem.update();
    while (isRunning) {
        keyboard_input_system->update();
        Event *event = eventLog->Get();
        string message = event->get_Message();
        if (message == "PRESS_CLOSE") {
            sceneManager->set_scene("MenuScene");
        }
        if (message == "PRESS_F") {
            system("vlc https://www.youtube.com/watch?v=K6i6-BKxf4Q");
            eventLog->Put(new Event("NULL"));
        }


    }
}

void WinScene::stop() {
    isRunning = false;

}
