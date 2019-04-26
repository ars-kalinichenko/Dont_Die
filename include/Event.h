#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include <string>

class Event {
private:
    static int lastID;
    int Id;
    std::string Message;
public:
    explicit Event(std::string);

    int get_Id();

    std::string get_Message();
};

#endif //GAME_EVENT_H
