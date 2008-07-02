#include "client3d.h"
#include "../../common/model/randomdice.h"
#include<gtkmm/main.h>
#include "pregamewindow.h"


int main(int argc, char** argv) {
    Gtk::Main main(argc, argv);
    RandomDice dice;
    ReferenceCountPtr<Game> game( new Game(new Map(),dice));
    PreGameWindow window(game);

    Gtk::Main::run(window);

    Client3d client;

    client.run();
    return 0;
}

