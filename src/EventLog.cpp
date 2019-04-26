#include "EventLog.h"
#include <vector>
#include <EventLog.h>

EventLog::EventLog() {
    log.push_back(new Event("Init"));
}

void EventLog::Put(Event *event) {
    log.push_back(event);
}

Event *EventLog::Get() {
    return log.back();
}


