
#include <EntityManager.h>

using namespace std;

vector<Entity *> &EntityManager::get_all() {
    return entities;
}

vector<Entity *> EntityManager::get_all_by_tag(const string &tag) {
    vector<Entity *> result;
    for (auto entity : entities) {
        if (entity->get_type() == tag) {
            result.push_back(entity);
        }
    }
    return result;
}

void EntityManager::add_entity(Entity *entity) {
    entities.push_back(entity);
}

void EntityManager::clear() {
    for (size_t i = 0; i < entities.size(); i++) {
        if (entities[i]->should_remove()) {
            entities.erase(entities.begin() + i);
            i--;
        }
    }
}
