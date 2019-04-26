#ifndef GAME_TERMINALSYSTEM_H
#define GAME_TERMINALSYSTEM_H


#include "System.h"

class TerminalSystem : public System {
public:
    TerminalSystem();

    void update() override;

    static void clear();

    ~TerminalSystem() override;
};


#endif //GAME_TERMINALSYSTEM_H
