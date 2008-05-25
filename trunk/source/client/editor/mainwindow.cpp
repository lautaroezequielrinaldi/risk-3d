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
    // Crea la barra de herramientas de ediciòn de la ventana principal.
    this->createEditionToolBar();
    // Crea la vista del mapa de la ventana principal.
    this->createMapView();
    // Muestro todos los widgets hijos.
    this->show_all_children();
    // Muevo la ventana a un estado maximizado.
    this->maximize();
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

void MainWindow::createEditionToolBar() {
    // Establece el manejador de la señal signal_clicked del boton de seleccion
    // de pais.
    this->editionToolBar.selectionSignalClicked().connect(sigc::mem_fun(*this,
        &MainWindow::onSelectionClicked));
    // Establece el manejador de la señal signal_clicked del boton de creacion
    // de pais.
    this->editionToolBar.creationSignalClicked().connect(sigc::mem_fun(*this,
        &MainWindow::onCreationClicked));

    // Agrega la barra de herramientas de selecciòn al layout vertical
    // de la ventana principal.
    this->verticalLayout.pack_start(this->editionToolBar, Gtk::PACK_SHRINK);
}

void MainWindow::createMapView() {
    this->mapView.modify_bg_pixmap(Gtk::STATE_NORMAL, "mapa.jpg");
    this->verticalLayout.pack_start(this->mapView ,Gtk::PACK_EXPAND_WIDGET);
}

void MainWindow::onNewMapSelected() {

}

void MainWindow::onLoadMapSelected() {
    // Creo un dialogo de seleccion de archivos.
    Gtk::FileChooserDialog dialog(*this, "Abrir Mapa Existente", Gtk::FILE_CHOOSER_ACTION_OPEN);
    // Agrego boton Cancelar al dialogo.
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    // Agrego boton Ok al dialogo.
    dialog.add_button("Select", Gtk::RESPONSE_OK);

    // Muestro el dialogo.
    dialog.show();
    // Ejecuto el dialogo.
    int result = dialog.run();
    
    // Verifico la respuesta del usuario.
    switch (result) {
        case Gtk::RESPONSE_OK:
            std::cout << dialog.get_filename() << std::endl;
            break;
        case Gtk::RESPONSE_CANCEL:
            break;
    }
}

void MainWindow::onSaveMapSelected() {
    // Creo un dialogo de seleccion de archivos.
    Gtk::FileChooserDialog dialog(*this, "Guardar Mapa", Gtk::FILE_CHOOSER_ACTION_SAVE);
    // Agrego boton Cancelar al dialogo.
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    // Agrego boton Ok al dialogo.
    dialog.add_button("Save", Gtk::RESPONSE_OK);

    // Muestro el dialogo.
    dialog.show();
    // Ejecuto el dialogo.
    int result = dialog.run();

    // Verifico la respuesta del usuario.
    switch (result) {
        case Gtk::RESPONSE_OK:
            std::cout << dialog.get_filename() << std::endl;
            break;
        case Gtk::RESPONSE_CANCEL:
            break;
    }
}

void MainWindow::onQuitSelected() {
    Gtk::Main::quit();
}

void MainWindow::onSelectionClicked() {

}

void MainWindow::onCreationClicked() {

}

MainWindow::~MainWindow() {
	// No realiza ninguna acción.
}

