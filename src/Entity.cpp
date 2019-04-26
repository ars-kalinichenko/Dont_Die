#include <utility>

#include <Entity.h>
#include "Entity.h"

using namespace std;

Entity::Entity(string type) {
    type_ = move(type);
}

string Entity::get_type() {
    return type_;
}

bool Entity::should_remove() {
    return remove_;
}

void Entity::remove() {
    remove_ = true;
}
