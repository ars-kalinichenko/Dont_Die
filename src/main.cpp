#include <scenes/SceneManager.h>
#include <BearLibTerminal.h>
#include <ConfigReader.h>

using namespace std;

int main() {
    terminal_open();
    terminal_refresh();
    terminal_composition(TK_ON);
    auto scene_m = make_unique<SceneManager>();
    scene_m->set_scene("MenuScene");
    terminal_close();
}
