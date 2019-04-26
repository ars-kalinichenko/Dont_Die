#ifndef GAME_POSITION_H
#define GAME_POSITION_H

#include "IComponent.h"

class Position : public IComponent {
public:
    int x_, y_, z_;

    Position(int x, int y, int z);

    void move(int x, int y, int z = 0);

    ~Position() override = default;

    friend bool operator==(const Position &first, const Position &second);

    friend bool operator<(const Position &l, const Position &r) {
        if (l.x_ < r.x_) return true;
        if (l.x_ > r.x_) return false;

        if (l.y_ < r.y_) return true;
        if (l.y_ > r.y_) return false;

        if (l.z_ < r.z_) return true;
        if (l.z_ > r.z_) return false;

        return false;
    }
};


#endif //GAME_POSITION_H
