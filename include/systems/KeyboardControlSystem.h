#ifndef GAME_KEYBOARDCONTROL_H
#define GAME_KEYBOARDCONTROL_H

#include "System.h"
#include "Event.h"
#include "EventLog.h"
#include <BearLibTerminal.h>
#include <iostream>
#include <vector>
#include <map>


class KeyboardControlSystem : public System {
private:
    EventLog *eventLog;
    std::map<std::string, int> keyboard_configs;
public:
    explicit KeyboardControlSystem(EventLog *);

    void update() override;

    ~KeyboardControlSystem() override = default;

};


#endif //GAME_KEYBOARDCONTROL_H
