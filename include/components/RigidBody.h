#ifndef GAME_RigidBody_H
#define GAME_RigidBody_H

#include "IComponent.h"

class RigidBody : public IComponent {
public:
    int mass;
    int density;

    int force_x = 0;
    int force_y = 0;

    RigidBody(int mass, int density);

    ~RigidBody() override = default;
};


#endif //GAME_RigidBody_H
