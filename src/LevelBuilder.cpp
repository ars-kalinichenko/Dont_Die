#include <LevelBuilder.h>
#include <Entity.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <components/Graphics.h>
#include <components/Position.h>
#include <components/RigidBody.h>
#include <components/Collider.h>
#include <EntityManager.h>
#include <components/Vitals.h>
#include <components/EnemyBehaviour.h>
#include <components/Inventory.h>

using namespace std;

LevelBuilder::LevelBuilder(IReader *reader) {

    this->reader = reader;
}

vector<Entity *> LevelBuilder::build() {
    int x = 1;
    int y = 0;

    vector<Entity *> map;
    EntityManager entityManager;
    auto *direction = new Position(1, 1, 0);

    while (reader->has_next()) {
        int c = reader->read();
        if (c == '@') {
            player_tile->put_component(new Collider());
            player_tile->put_component(new Inventory());
            player_tile->put_component(new Position(x, y, 0));
            player_tile->put_component(new Graphics('@', (char *) "black"));
            player_tile->put_component(new RigidBody(1, 100));
            player_tile->put_component(new Vitals(200, 2000));
            entityManager.add_entity(player_tile);
            map.push_back(player_tile);

            auto camera = new Entity("Camera");
            camera->put_component(new Position(x, y, 0));
            entityManager.add_entity(camera);
            map.push_back(camera);
        } else if (c == '#') {
            auto wall = new Entity("Wall");
            wall->put_component(new Collider());
            wall->put_component(new Position(x, y, 0));
            wall->put_component(new Graphics(L'█', (char *) "black"));
            wall->put_component(new RigidBody(1000, 10000));
            map.push_back(wall);
        } else if (c == '|') {
            auto door = new Entity("Door");
            door->put_component(new Collider());
            door->put_component(new RigidBody(1, 1));
            door->put_component(new Position(x, y, 0));
            door->put_component(new Graphics(L'║', (char *) "black"));
            map.push_back(door);
        } else if (c == '*') {
            auto star = new Entity("Star");
            star->put_component(new Collider());
            star->put_component(new Position(x, y, 0));
            star->put_component(new Graphics(L'•', (char *) "black"));
            map.push_back(star);
        } else if (c == '%') {
            auto manager_potion = new Entity("ManagerDeadPotion");
            manager_potion->put_component(new Collider());
            manager_potion->put_component(new Position(x, y, 0));
            manager_potion->put_component(new Graphics(L'†', (char *) "black"));
            map.push_back(manager_potion);
        } else if (c == '&') {
            auto deadline_potion = new Entity("DeadlineDeadPotion");
            deadline_potion->put_component(new Collider());
            deadline_potion->put_component(new Position(x, y, 0));
            deadline_potion->put_component(new Graphics(L'‡', (char *) "black"));
            map.push_back(deadline_potion);
        } else if (c == '^') {
            auto health_potion = new Entity("HealthPotion");
            health_potion->put_component(new Collider());
            health_potion->put_component(new Position(x, y, 0));
            health_potion->put_component(new Graphics(L'ø', (char *) "black"));
            map.push_back(health_potion);
        } else if (c == '$') {
            auto testers_potion = new Entity("TestersPotion");
            testers_potion->put_component(new Collider());
            testers_potion->put_component(new Position(x, y, 0));
            testers_potion->put_component(new Graphics(L'¤', (char *) "black"));
            map.push_back(testers_potion);
        } else if (c == '-') {
            auto key = new Entity("Key");
            key->put_component(new Collider());
            key->put_component(new Position(x, y, 0));
            key->put_component(new Graphics(L'¢', (char *) "black"));
            map.push_back(key);
        } else if (c == '1') {
            auto enemy = new Entity("Manager");
            enemy->put_component(new Collider());
            enemy->put_component(new RigidBody(10000, 100000));
            enemy->put_component(new Position(x, y, 0));
            enemy->put_component(new EnemyBehaviour(direction));
            enemy->put_component(new Graphics('M', (char *) "black"));
            enemy->put_component(new Vitals(15, 15));
            map.push_back(enemy);
        } else if (c == '2') {
            auto enemy = new Entity("Deadline");
            enemy->put_component(new Collider());
            enemy->put_component(new RigidBody(10000, 100000));
            enemy->put_component(new EnemyBehaviour(direction));
            enemy->put_component(new Position(x, y, 0));
            enemy->put_component(new Vitals(0, 150000));
            map.push_back(enemy);
        } else if (c == '3') {
            auto tester = new Entity("Tester");
            tester->put_component(new Collider());
            tester->put_component(new Position(x, y, 0));
            tester->put_component(new RigidBody(10000, 100000));
            tester->put_component(new Graphics('T', (char *) "black"));
            map.push_back(tester);
        } else if (c == '4') {
            auto bug = new Entity("Bug");
            bug->put_component(new Collider());
            bug->put_component(new Position(x, y, 0));
            bug->put_component(new RigidBody(10000, 100000));
            bug->put_component(new EnemyBehaviour(new Position(1, 0, 0)));
            bug->put_component(new Graphics('b', (char *) "black"));
            map.push_back(bug);

        } else if (c == '5') {
            auto bug = new Entity("MadDeveloper");
            bug->put_component(new Collider());
            bug->put_component(new Position(x, y, 0));
            bug->put_component(new RigidBody(10000, 100000));
            bug->put_component(new EnemyBehaviour(new Position(1, 1, 0)));
            bug->put_component(new Graphics('d', (char *) "black"));
            map.push_back(bug);
        } else {
            if (c != 10 && c != 32) {
                auto tile = new Entity("Tile");
                tile->put_component(new Collider());
                tile->put_component(new Position(x, y, 0));
                tile->put_component(new RigidBody(10, 10));
                tile->put_component(new Graphics(c, (char *) "black"));
                map.push_back(tile);
            }
        }
        if (c == 10) {
            y += 1;
            x = 0;
        }
        x += 1;
    }
    return map;
}

