
#include <scenes/MenuScene.h>
#include <memory>
#include <EventLog.h>
#include <systems/KeyboardControlSystem.h>
#include <systems/TerminalSystem.h>
//#include <zconf.h>
#include <unistd.h>
#include "scenes/MenuScene.h"

using namespace std;

void MenuScene::start() {
    isRunning = true;
    run();
}

void MenuScene::run() {
    TerminalSystem terminalSystem;
    terminal_set("window.title='Don`t / Die'; log.file = '../../bearlibterminal.log'; log.level = debug");
    terminal_bkcolor(color_from_name((char *) "white"));
    terminalSystem.clear();
    terminal_color(color_from_name((char *) "black"));

    terminal_printf(5, 5, "Play {enter}");
    terminal_printf(5, 7, "Anime Gameplay {F}");
    terminal_printf(5, 9, "Settings {F1}");
    terminal_printf(5, 11, "About {F2}");
    terminal_printf(5, 13, "Story {F3}");
    terminal_printf(5, 15, "Exit {esc}");

    terminalSystem.update();
    auto eventLog = make_unique<EventLog>();
    auto keyboard_input_system = make_unique<KeyboardControlSystem>(eventLog.get());
    while (isRunning) {
        keyboard_input_system->update();
        Event *event = eventLog->Get();
        string message = event->get_Message();

        if (message == "PRESS_F1") {
            sceneManager->set_scene("SettingsScene");

        }
        if (message == "PRESS_F2") {
            sceneManager->set_scene("AboutScene");
        }
        if (message == "PRESS_F3") {
            sceneManager->set_scene("StoryScene");
        }


        if (message == "PRESS_ENTER") {
            terminalSystem.clear();
            terminal_printf(32, 5, "ДИСКЛЕЙМЕР");
            terminal_printf(10, 7, "Помните, что все события в игре вымышлены");
            terminal_printf(10, 8, "Менеджеры не убивают, дедлайнов не существует");
            terminal_printf(10, 9, "Чистилища тестировщиков с обилием багов тоже не существует");
            terminal_printf(10, 10, "В этом мире нет и выхода, который есть в каждом уровне");
            terminal_printf(10, 11, "Присутсвуют сцены насилия. Просим отойти анимешников от экрана");
            terminal_printf(36, 13, "21+");
            terminalSystem.update();
            usleep(1000000);

            terminalSystem.clear();
            terminal_printf(25, 10, "Твоя главная цель - выжить.");
            terminal_printf(33, 11, "Или умереть?");
            terminalSystem.update();
            usleep(700000);

            sceneManager->set_scene("GameScene");

        }
        if (message == "PRESS_F") {
            system("vlc https://www.youtube.com/watch?v=K6i6-BKxf4Q");
            eventLog->Put(new Event("NULL"));
        }
        if (message == "PRESS_CLOSE") {
            break;
        }
    }
}

void MenuScene::stop() {
    isRunning = false;
}
