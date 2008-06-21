#include "mainwindow.h"

MainWindow::MainWindow():
	Gtk::Window(),
	editor(NULL),
	verticalBox(),
	horizontalBox(),
	mainMenu(),
	notebookTab(),
	continentPage(editor),
	countryPage(editor),
	gameCardPage(editor),
	mapDrawingAreaFrame(editor) {
	// Agrego la pagina de continentes del notebook tab,
	this->notebookTab.append_page(this->continentPage, "CONTINENTES");
	// Agrego la pagina de paises del notebook tab.
	this->notebookTab.append_page(this->countryPage, "PAISES");
	// Agrego la pagina de cartas de juego del notebook tab.
	this->notebookTab.append_page(this->gameCardPage, "CARTAS DE JUEGO");

	// Agrego el area de dibujo de la imagen al horizontal box.
	this->horizontalBox.pack_start(this->mapDrawingAreaFrame, Gtk::PACK_EXPAND_WIDGET);
	// Agrego el notebook tabl al horizontal box.
	this->horizontalBox.pack_start(this->notebookTab, Gtk::PACK_SHRINK);

	// Agrego el menu principal al vertical box.
	this->verticalBox.pack_start(this->mainMenu, Gtk::PACK_SHRINK);
	// Agrego el horizontalBox al verticalBox.
	this->verticalBox.pack_start(this->horizontalBox, Gtk::PACK_EXPAND_WIDGET);

	// Agrego el vertical box a la ventana,
	this->add(this->verticalBox);
	// Muestro a todos los widgets hijos.
	this->show_all_children();

	// Asocio los manejadores de eventos.
	this->mainMenu.newMenuItemSignalActivate().connect(sigc::mem_fun(*this,
		&MainWindow::onNewMenuItemActivated));
	this->mainMenu.openMenuItemSignalActivate().connect(sigc::mem_fun(*this,
        &MainWindow::onOpenMenuItemActivated));
	this->mainMenu.saveMenuItemSignalActivate().connect(sigc::mem_fun(*this,
        &MainWindow::onSaveMenuItemActivated));
	this->mainMenu.quitMenuItemSignalActivate().connect(sigc::mem_fun(*this,
        &MainWindow::onQuitMenuItemActivated));
}

void MainWindow::onNewMenuItemActivated() {
    // Creo un nuevo FileFilter para filtrar por imagenes.
    Gtk::FileFilter imageFileFilter;
    imageFileFilter.set_name("Todas las imagenes");
    imageFileFilter.add_mime_type("image/*");

	// Creo un nuevo cuadro de dialogo de seleccion de archivos.
	Gtk::FileChooserDialog dialog("ABRIR IMAGEN DE MAPA", Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);
	dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
    dialog.add_filter(imageFileFilter);

	// Ejecuto el dialogo.
	int result = dialog.run();

	//Handle the response:
	switch(result) {
		case(Gtk::RESPONSE_OK): {
			std::string imageFileName = dialog.get_filename();
			this->setEditor(new Editor(imageFileName));
		}
	}
}

void MainWindow::onOpenMenuItemActivated() {
    // Creo un nuevo FileFilter para filtrar archivos por extension xml.
    Gtk::FileFilter xmlFileFilter;
    xmlFileFilter.set_name("Todos los archivos xml");
    xmlFileFilter.add_pattern("*.xml");

    // Creo un nuevo cuadro de dialogo de seleccion de archivos.
    Gtk::FileChooserDialog dialog("CARGAR MAPA", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
    dialog.add_filter(xmlFileFilter);
	// Ejecuto el dialogo.
    int result = dialog.run();

	//Handle the response:
    switch(result) {
		case(Gtk::RESPONSE_OK): {
			std::string fileToLoad = dialog.get_filename();
			MapaParser parser;
			ReferenceCountPtr<Mapa> map = parser.loadMap(fileToLoad);
			ReferenceCountPtr<Editor> loadedEditor(new Editor("./image"));
			loadedEditor->setMapa(map);
			this->setEditor(loadedEditor);
		}
	}
}

void MainWindow::onSaveMenuItemActivated() {
	if (this->editor != NULL) {
        // Creo un FileFilter para los archivos xml.
        Gtk::FileFilter xmlFileFilter;
        xmlFileFilter.set_name("Todos los archivos xml");
        xmlFileFilter.add_pattern("*.xml");
		// Creo un nuevo cuadro de dialogo de seleccion de archivos.
		Gtk::FileChooserDialog dialog("GUARDAR MAPA", Gtk::FILE_CHOOSER_ACTION_SAVE);
		dialog.set_transient_for(*this);
		dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
		dialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
        dialog.add_filter(xmlFileFilter);
		// Ejecuto el dialogo.
		int result = dialog.run();

		//Handle the response:
		switch(result) {
			case(Gtk::RESPONSE_OK): {
				std::string fileToSave  = dialog.get_filename();
				MapaParser parser;
				parser.saveMap(fileToSave, this->editor->getImageFileName(),
					this->editor->getMapa());
			}
		}
	}
}

void MainWindow::onQuitMenuItemActivated() {
	Gtk::Main::quit();
}

void MainWindow::setEditor(const ReferenceCountPtr<Editor>& editor) {
	this->editor = editor;
	this->continentPage.setEditor(this->editor);
	this->countryPage.setEditor(this->editor);
	this->gameCardPage.setEditor(this->editor);
	this->mapDrawingAreaFrame.setEditor(this->editor);
	this->mapDrawingAreaFrame.loadImage(this->editor->getImageFileName());
}

MainWindow::~MainWindow() {
	// No realiza ninguna acccion.
}

