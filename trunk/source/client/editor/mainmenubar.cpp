#include "mainmenubar.h"

MainMenuBar::MainMenuBar():
    Gtk::MenuBar(),
    fileMenuItem(),
    newMapMenuItem(),
    loadMapMenuItem(),
    saveMapMenuItem(),
    quitMenuItem(),
    fileMenu() {
    // Asigna el label al item de menu archivo.
    fileMenuItem.add_label("Archivo");
    // Asigna el label al item de menu nuevo mapa.
    newMapMenuItem.add_label("Nuevo Mapa...");
    // Asigna el label al item de menu cargar mapa.
    loadMapMenuItem.add_label("Cargar Mapa...");
    // Asigna el label al item de menu guardar mapa.
    saveMapMenuItem.add_label("Salvar Mapa...");
    // Asigna el label al item de menu salir.
    quitMenuItem.add_label("Salir");

    // Agrega el item de menu nuevo mapa al menu archivo.
    fileMenu.append(newMapMenuItem);
    // Agrega el item de menu cargar mapa al menu archivo.
    fileMenu.append(loadMapMenuItem);
    // Agrega el item de guardar nuevo mapa al menu archivo.
    fileMenu.append(saveMapMenuItem);
    // Agrega el item de menu salir al menu archivo.
    fileMenu.append(quitMenuItem);

    // Agrega el menu archivo al item de menu archivo.
    fileMenuItem.set_submenu(fileMenu);

    // Agrego el item de menu archivo a la barra de menu.
    this->append(fileMenuItem);
}

Glib::SignalProxy0<void> MainMenuBar::newMapSignalActivate() {
    return this->newMapMenuItem.signal_activate();
}

Glib::SignalProxy0<void> MainMenuBar::loadMapSignalActivate() {
    return this->loadMapMenuItem.signal_activate();
}

Glib::SignalProxy0<void> MainMenuBar::saveMapSignalActivate() {
    return this->saveMapMenuItem.signal_activate();
}

Glib::SignalProxy0<void> MainMenuBar::quitSignalActivate() {
    return this->quitMenuItem.signal_activate();
}

MainMenuBar::~MainMenuBar() {
    // No realiza ninguna acciòn.
}

