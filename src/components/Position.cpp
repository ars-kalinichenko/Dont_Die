
#include <components/Position.h>

Position::Position(int x, int y, int z) : x_(x), y_(y), z_(z) {}

void Position::move(int x, int y, int z) {
    x_ += x;
    y_ += y;
    z_ += z;
}

bool operator==(const Position &first, const Position &second) {
    return first.x_ == second.x_ && first.y_ == second.y_ && first.z_ == second.z_;
}
