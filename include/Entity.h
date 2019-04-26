#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "components/IComponent.h"
#include <map>
#include <typeindex>
#include <typeinfo>


#include <string>

class Entity {
    std::string type_;
    bool remove_ = false;
    std::map<std::type_index, IComponent *> components;
public:
    explicit Entity(std::string type);

    template<class T>
    void put_component(T *component) {
        components[typeid(T)] = component;
    };

    template<class T>
    T *get_component() const {
        return (T *) components.at(typeid(T));
    }

    template<typename T>
    bool has_component() {
        auto iterator = components.find(typeid(T));
        return iterator != components.end();
    }

    std::string get_type();

    bool should_remove();

    void remove();

};


#endif //GAME_ENTITY_H
