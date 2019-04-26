#ifndef GAME_TRAJECTORY_H
#define GAME_TRAJECTORY_H


#include "IComponent.h"
#include "Position.h"

class EnemyBehaviour : public IComponent {
public:

    Position *direction = new Position(0, 0, 0);

    explicit EnemyBehaviour(Position *direction) : direction(direction) {};

    ~EnemyBehaviour() override = default;
};


#endif //GAME_TRAJECTORY_H
