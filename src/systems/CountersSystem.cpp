#include "systems/CountersSystem.h"
#include <memory>
#include <systems/StarsCollectionSystem.h>
#include <systems/TimeFlowSystem.h>
#include <BearLibTerminal.h>
#include <components/Vitals.h>

using namespace std;

CountersSystem::CountersSystem(EntityManager *entityManager) : entityManager(entityManager) {
    time_flow = make_unique<TimeFlowSystem>();
}

void CountersSystem::update() {

    auto vitals = entityManager->get_all_by_tag("Player")[0]->get_component<Vitals>();


    time_flow->update();
    string age = to_string(time_flow->get_age());
    char const *age_char = age.c_str();
    terminal_printf(20, 0, "Age: ");
    terminal_printf(25, 0, age_char);

    string hp = to_string(vitals->hp);
    char const *hp_char = hp.c_str();
    string power = to_string(vitals->power);
    char const *power_char = power.c_str();
    terminal_printf(50, 0, "Power:");
    terminal_printf(57, 0, power_char);
    terminal_printf(73, 0, "HP:");
    terminal_printf(76, 0, hp_char);
}

