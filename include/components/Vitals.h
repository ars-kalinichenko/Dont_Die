#ifndef GAME_VITALS_H
#define GAME_VITALS_H


#include "IComponent.h"

class Vitals : public IComponent {
public:
    int hp;
    int power;

    Vitals(int hp, int power);

    ~Vitals() override = default;
};


#endif //GAME_VITALS_H
