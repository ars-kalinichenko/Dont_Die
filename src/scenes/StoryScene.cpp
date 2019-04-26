#include "scenes/StoryScene.h"
#include <memory>
#include <EventLog.h>
#include <systems/KeyboardControlSystem.h>
#include <systems/TerminalSystem.h>

using namespace std;

void StoryScene::start() {
    isRunning = true;
    run();
}

void StoryScene::run() {
    TerminalSystem terminalSystem;
    auto eventLog = make_unique<EventLog>();
    auto keyboard_input_system = make_unique<KeyboardControlSystem>(eventLog.get());

    terminalSystem.clear();
    terminal_printf(30, 3, "НЕМНОГО ИСТОРИИ");
    terminal_printf(15, 6, "Юный и неопытный Наруто, только что представивший");
    terminal_printf(15, 7, "рогалик на демо, думает о своём будущем.");
    terminal_printf(15, 8, "Но осознав, что ему нравится всё, начиная");
    terminal_printf(15, 9, "от ML и заканчивая промышленным дизайном котиков,");
    terminal_printf(15, 10, "бьётся в истерике, не понимая ничего.");
    terminal_printf(15, 11, "Спустя пару дней Наруто решил продать свои активы");
    terminal_printf(15, 12, "в белорусских долларах и уйти с биржи.");
    terminal_printf(15, 13, "Но что же он собирается делать в будущем?");
    terminal_printf(15, 14, "Правильно, он намерен пройти все круги ада,");
    terminal_printf(15, 15, "пробуя себя в IT. Я не мог не поделиться ");
    terminal_printf(15, 16, "этой историей с вами, и, поэтому предлагаю");
    terminal_printf(15, 17, "погрузиться в страдания юного Наруто.");
    terminal_printf(1, 23, "Switch to menu {esc}");

    terminalSystem.update();

    while (isRunning) {
        keyboard_input_system->update();
        Event *event = eventLog->Get();
        string message = event->get_Message();

        if (message == "PRESS_CLOSE") {
            sceneManager->set_scene("MenuScene");
        }


    }
}

void StoryScene::stop() {
    isRunning = false;
}
