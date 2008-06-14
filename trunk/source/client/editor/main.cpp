#include<gtkmm/main.h>
#include "mainwindow.h" // Para definicion de MainWindow.

int main(int argc, char** argv) {
    Gtk::Main main(argc, argv);

	MainWindow mainWindow;
	mainWindow.maximize();    
	Gtk::Main::run(mainWindow);

    return 0;
}

