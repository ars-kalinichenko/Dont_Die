#include "components/Inventory.h"

using namespace std;

vector<Entity *> &Inventory::get_all() {
    return bag;
}

vector<Entity *> Inventory::get_all_by_tag(const string &tag) {
    vector<Entity *> result;
    for (auto thing : bag) {
        if (thing->get_type() == tag) {
            result.push_back(thing);
        }
    }
    return result;
}

void Inventory::add_entity(Entity *thing) {
    bag.push_back(thing);
}

void Inventory::clear() {
    for (size_t i = 0; i < bag.size(); i++) {
        if (bag.at(i)->should_remove()) {
            bag.erase(bag.begin() + i);
            i--;
        }
    }
}

