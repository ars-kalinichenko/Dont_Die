#include <systems/TerminalSystem.h>
#include <BearLibTerminal.h>
#include "systems/TerminalSystem.h"
#include <iostream>

TerminalSystem::TerminalSystem() {
    terminal_refresh();
    terminal_composition(TK_ON);
}

void TerminalSystem::update() {
    terminal_refresh();

}

void TerminalSystem::clear() {
    terminal_clear();
}

TerminalSystem::~TerminalSystem() {
    terminal_close();
}


