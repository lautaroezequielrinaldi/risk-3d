#include "mainwindow.h"

MainWindow::MainWindow():
	Gtk::Window() {
	// Establece el titulo de la ventana.
	this->set_title("Editor de Mapas Risk-3D");
    // Agrega el layout vertical
    this->add(this->verticalLayout);
    // Crea la barra de menues.
    this->createMenuBar();
    // Muestro todos los widgets hijos.
    this->show_all_children();
}

void MainWindow::createMenuBar() {
    // Inicializo el item de menu salir.
    this->salirMenuItem.add_label("Salir");
    //this->salirMenuItem.signal_activate.connect(sigc::mem_fun(*this,
    //    &MainWindow::onSalirSelected));

    // Inicializo el item de menu guardar mapa.
    this->guardarMapaMenuItem.add_label("Guardar Mapa");

    // Inicializo el item de menu nuevo mapa.
    this->nuevoMapaMenuItem.add_label("Nuevo Mapa");

    // Inicializo el menu archivo.
    this->archivoMenu.append(this->nuevoMapaMenuItem);
    this->archivoMenu.append(this->guardarMapaMenuItem);
    this->archivoMenu.append(this->salirMenuItem);

    // Inicialzo el item de menu archivo.
    this->archivoMenuItem.add_label("Archivo");
    this->archivoMenuItem.set_submenu(this->archivoMenu);

    // Inicializo la barra de menues.
    this->barraMenu.append(this->archivoMenuItem);

    // Agrego la barra de menues a la ventana.
    this->verticalLayout.pack_start(this->barraMenu, Gtk::PACK_SHRINK);
}

void MainWindow::onSalirSelected() {
    Gtk::Main::quit();
}

MainWindow::~MainWindow() {
	// No realiza ninguna acción.
}

