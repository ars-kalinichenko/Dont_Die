#include <components/Position.h>
#include "systems/DeleteSystem.h"

DeleteSystem::DeleteSystem(EntityManager *entityManager) : entityManager(entityManager) {}

void DeleteSystem::update() {
    entityManager->clear();
}


