#include "mainmenu.h"

MainMenu::MainMenu():
	Gtk::MenuBar() {
	// Establece el label del item de menuu archivo.
	this->fileMenuItem.add_label("Archivo");
	// Establece el label del item de menu nuevo.
	this->newMenuItem.add_label("Nuevo");
	// Establece el label del item de menu abrir.
	this->openMenuItem.add_label("Abrir");
	// Establece el label del itmem de menu guardar.
	this->saveMenuItem.add_label("Guardar");
	// Establece el label del item de menu salir.
	this->quitMenuItem.add_label("Salir");

	// Agrega los items de menu al menu arcihvo.
	this->fileMenu.append(this->newMenuItem);
	this->fileMenu.append(this->openMenuItem);
	this->fileMenu.append(this->saveMenuItem);
	this->fileMenu.append(this->quitMenuItem);

	// Agrega el menu de arcuhivo al item de menu archivo.
	this->fileMenuItem.set_submenu(this->fileMenu);

	// Agrega el item de menu archivo al menu bar.
	this->append(this->fileMenuItem);
}

Glib::SignalProxy0<void> MainMenu::newMenuItemSignalActivate() {
	return this->newMenuItem.signal_activate();
}

Glib::SignalProxy0<void> MainMenu::openMenuItemSignalActivate() {
	return this->openMenuItem.signal_activate();
}

Glib::SignalProxy0<void> MainMenu::saveMenuItemSignalActivate() {
	return this->saveMenuItem.signal_activate();
}

Glib::SignalProxy0<void> MainMenu::quitMenuItemSignalActivate() {
	return this->quitMenuItem.signal_activate();
}

MainMenu::~MainMenu() {
	// No realiza ninguna accion.
}

