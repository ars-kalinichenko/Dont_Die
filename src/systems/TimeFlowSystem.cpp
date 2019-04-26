#include "systems/TimeFlowSystem.h"
#include <chrono>

using namespace std;

TimeFlowSystem::TimeFlowSystem() {
    start_time = chrono::high_resolution_clock::now();
}

void TimeFlowSystem::update() {
    auto stop_time = chrono::high_resolution_clock::now();
    auto deltaTime = chrono::duration_cast<chrono::seconds>(stop_time - start_time).count();
    if (deltaTime > 2) {
        start_time = stop_time;
        ++age_;
    }
}

int TimeFlowSystem::get_age() {
    return age_;
}
