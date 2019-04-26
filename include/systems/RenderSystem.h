#ifndef GAME_RENDER_H
#define GAME_RENDER_H


#include <vector>
#include <Entity.h>
#include <EntityManager.h>
#include "System.h"

class RenderSystem : public System {
private:
    EntityManager *&entityManager;
public:
    explicit RenderSystem(EntityManager *&entityManager);

    void update() override;

    ~RenderSystem() override = default;
};


#endif //GAME_RENDERSYSTEM_H
