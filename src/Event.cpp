#include <utility>

using namespace std;

#include <Event.h>

int Event::lastID = 0;

Event::Event(string message) {
    Id = ++lastID;
    Message = move(message);
}

int Event::get_Id() {
    return Id;
}

string Event::get_Message() {
    return Message;
}

