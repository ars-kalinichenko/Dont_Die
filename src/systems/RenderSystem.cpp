#include <components/Graphics.h>
#include <components/Position.h>
#include <BearLibTerminal.h>
#include <systems/TerminalSystem.h>
#include "systems/RenderSystem.h"

RenderSystem::RenderSystem(EntityManager *&entityManager) : entityManager(entityManager) {
}


void RenderSystem::update() {
    for (auto tile: entityManager->get_all()) {
        if (tile->has_component<Graphics>()) {
            for (auto camera : entityManager->get_all_by_tag("Camera")) {
                if (!camera->has_component<Position>()) {
                    return;
                }
                auto camPosition = camera->get_component<Position>();
                terminal_color(color_from_name(tile->get_component<Graphics>()->color));
                int delta_x = camPosition->x_ - 40;
                int delta_y = camPosition->y_ - 13;
                terminal_put(tile->get_component<Position>()->x_ - delta_x,
                             tile->get_component<Position>()->y_ - delta_y,
                             tile->get_component<Graphics>()->symbol);
            }
        }
    }
}