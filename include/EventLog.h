#ifndef GAME_EVENTLOG_H
#define GAME_EVENTLOG_H

#include <vector>
#include <string>
#include "Event.h"

class EventLog {
private:
    std::vector<Event *> log;
public:
    EventLog();

    void Put(Event *);

    Event *Get();

    ~EventLog() = default;
};

#endif //GAME_EVENTLOG_H
