
#ifndef GAME_TIMEFLOWSYSTEM_H
#define GAME_TIMEFLOWSYSTEM_H

#include<chrono>
#include "System.h"

class TimeFlowSystem : public System {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    int age_ = 20;
public:
    TimeFlowSystem();

    void update() override;

    int get_age();

    ~TimeFlowSystem() override = default;

};


#endif //GAME_TIMEFLOWSYSTEM_H
