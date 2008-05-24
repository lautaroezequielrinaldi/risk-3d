#include "mainwindow.h"
#include<iostream>
MainWindow::MainWindow():
	Gtk::Window() {
	// Establece el titulo de la ventana.
	this->set_title("Editor de Mapas Risk-3D");
    // Cra el layout vertical de la ventana principal.
    this->createVerticalLayout();
    // Crea la barra de menu de la ventana principal.
    this->createMenuBar();
    // Muestro todos los widgets hijos.
    this->show_all_children();
}

void MainWindow::createVerticalLayout() {
    // Agrega el layout vertical de la ventana principal a la ventana principal.
    this->add(this->verticalLayout);
}

void MainWindow::createMenuBar() {
    // Establece el manejador de la señal signal_activate del item de menu
    // nuevo mapa.
    this->menuBar.newMapSignalActivate().connect(sigc::mem_fun(*this,
        &MainWindow::onNewMapSelected));
    // Establece el manejador de la señal signal_activate del item de menu
    // cargar mapa.
    this->menuBar.loadMapSignalActivate().connect(sigc::mem_fun(*this,
        &MainWindow::onLoadMapSelected));
     // Establece el manejador de la señal signal_activate del item de menu
     // guardar mapa.
     this->menuBar.saveMapSignalActivate().connect(sigc::mem_fun(*this,
        &MainWindow::onSaveMapSelected));
    // Establece el manejador de la señal signal_activate del item de menu
    // salir.
    this->menuBar.quitSignalActivate().connect(sigc::mem_fun(*this,
        &MainWindow::onQuitSelected));

    // Agrega la barra de menu al layout vertical de la ventana principal.
    this->verticalLayout.pack_start(this->menuBar, Gtk::PACK_SHRINK);
}

void MainWindow::onNewMapSelected() {
std::cout << "Apreto nuevo mapa" << std::endl;
}

void MainWindow::onLoadMapSelected() {
std::cout << "Apreto cargar mapa" << std::endl;
}

void MainWindow::onSaveMapSelected() {
std::cout << "Apreto guardar mapa" << std::endl;
}

void MainWindow::onQuitSelected() {
    Gtk::Main::quit();
}

MainWindow::~MainWindow() {
	// No realiza ninguna acción.
}

