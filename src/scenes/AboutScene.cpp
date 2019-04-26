#include <systems/TerminalSystem.h>
#include <EventLog.h>
#include <memory>
#include <systems/KeyboardControlSystem.h>
#include <scenes/AboutScene.h>

using namespace std;

void AboutScene::start() {
    isRunning = true;
    run();
}

void AboutScene::run() {
    TerminalSystem terminalSystem;
    auto eventLog = make_unique<EventLog>();
    auto keyboard_input_system = make_unique<KeyboardControlSystem>(eventLog.get());

    terminalSystem.clear();
    terminal_color(color_from_name((char *) "black"));
    terminal_printf(4, 3, "Donation {F}");
    terminal_printf(4, 5, "About author {F1}");
    terminal_printf(4, 7, "Switch to menu {esc}");
    terminal_printf(50, 3, "Пока ты это читаешь,");
    terminal_printf(50, 4, "программист страдает,");
    terminal_printf(50, 5, "его рогалик лагает");
    terminal_printf(50, 6, "и он ничего не понимает");
    terminal_printf(56, 8, "2 0 1 9");

    terminalSystem.update();

    while (isRunning) {
        keyboard_input_system->update();
        Event *event = eventLog->Get();
        string message = event->get_Message();

        if (message == "PRESS_F") {
            system("xdg-open https://donatepay.ru/don/281763");
            eventLog->Put(new Event("NULL"));
        }
        if (message == "PRESS_CLOSE") {
            sceneManager->set_scene("MenuScene");
        }
        if (message == "PRESS_F1") {
            system("xdg-open https://ars-kalinichenko.github.io");
            eventLog->Put(new Event("NULL"));
        }


    }
}

void AboutScene::stop() {
    isRunning = false;
}