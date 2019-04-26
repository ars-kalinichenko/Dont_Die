#include <systems/KeyboardControlSystem.h>
#include <ConfigReader.h>
#include "systems/KeyboardControlSystem.h"

using namespace std;

KeyboardControlSystem::KeyboardControlSystem(EventLog *eventLog) {
    ConfigReader Split;
    keyboard_configs = Split.read_config("../../res/config/Config_Keyboard");
    this->eventLog = eventLog;
}

void KeyboardControlSystem::update() {

    if (terminal_has_input()) {
        int key = terminal_read();
        if (key == keyboard_configs["UP"]) eventLog->Put(new Event("PRESS_UP"));
        if (key == keyboard_configs["DOWN"]) eventLog->Put(new Event("PRESS_DOWN"));
        if (key == keyboard_configs["LEFT"]) eventLog->Put(new Event("PRESS_LEFT"));
        if (key == keyboard_configs["RIGHT"]) eventLog->Put(new Event("PRESS_RIGHT"));
        if (key == keyboard_configs["ENTER"]) eventLog->Put(new Event("PRESS_ENTER"));
        if (key == keyboard_configs["CLOSE"]) eventLog->Put(new Event("PRESS_CLOSE"));
        if (key == TK_F) eventLog->Put(new Event("PRESS_F"));
        if (key == TK_F1) eventLog->Put(new Event("PRESS_F1"));
        if (key == TK_F2) eventLog->Put(new Event("PRESS_F2"));
        if (key == TK_F3) eventLog->Put(new Event("PRESS_F3"));
        if (key == TK_CLOSE) eventLog->Put(new Event("PRESS_CLOSE"));
    }
}



