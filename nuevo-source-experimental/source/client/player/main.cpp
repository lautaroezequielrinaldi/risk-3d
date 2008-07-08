#include "../../common/model/randomdice.h"
#include<gtkmm/main.h>
#include "pregamewindow.h"
#include "gamewindow.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    Gtk::Main main(argc, argv);
    RandomDice dice;
    ReferenceCountPtr<Mapa> map;
    ReferenceCountPtr<Game> game( new Game(map,dice));
    PreGameWindow window(game);

	cout<<"INICIANDO GTKMM!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

    Gtk::Main::run(window);
    sleep(2000);
  
	
	//Gtk::Main::quit();


/*
    GameWindow gameWindow; 
    return gameWindow.run(argc, argv);
 */
    cout<<"termina loop gtk"<<endl;
}

