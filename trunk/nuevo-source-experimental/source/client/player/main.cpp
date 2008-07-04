#include "../../common/model/randomdice.h"
#include<gtkmm/main.h>
#include "pregamewindow.h"
#include "gamewindow.h"

int main(int argc, char** argv) {
    Gtk::Main main(argc, argv);
    RandomDice dice;
    ReferenceCountPtr<Mapa> map;
    ReferenceCountPtr<Game> game( new Game(map,dice));
    PreGameWindow window(game);

    Gtk::Main::run(window);

    GameWindow gameWindow; 

    return gameWindow.run();
}

