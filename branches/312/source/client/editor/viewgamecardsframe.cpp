#include "viewgamecardsframe.h"
#include "../../common/model/gamecard.h"

ViewGameCardsFrame::ViewGameCardsFrame(const ReferenceCountPtr<Editor>& editor):	Observer(),
	Gtk::Frame(),
	editor(editor),
	gameCardColumns(),
	gameCardTreeModel(),
	gameCardTreeView() {
    // Establece el titulo del frame.
    this->set_label("Listado de cartas de juego");

	// Se agrega como observador del editor.
	if (this->editor != NULL) {
		this->editor->registerObserver(this);
	}

	// Inicializa el modelo de tree de la lista de cartas de juego.
	this->initializeGameCardTreeModel();
	// Inicializa el tree view de la lista de cartas de juego.
	this->initializeGameCardTreeView();

	// Agrega el tree view de la lista de cartas de juego al vertical box.
	this->verticalBox.pack_start(this->gameCardTreeView,
		Gtk::PACK_SHRINK);

	// Agrega el vertical box al frame.
	this->add(this->verticalBox);

	// Popula la lista de cartas de juego.
	this->populate();
}

void ViewGameCardsFrame::initializeGameCardTreeModel() {
    this->gameCardTreeModel = Gtk::ListStore::create(gameCardColumns);
}

void ViewGameCardsFrame::initializeGameCardTreeView() {
    this->gameCardTreeView.append_column("Nombre",
        gameCardColumns.gameCardName);
    this->gameCardTreeView.set_model(this->gameCardTreeModel);
}

void ViewGameCardsFrame::populate() {
    // Borro la lista de cartas de juego.
    this->gameCardTreeModel->clear();
    
	if (this->editor != NULL && this->editor->getMapa() != NULL) {
		// Obtengo el mapa del editor
		ReferenceCountPtr<Mapa> map = this->editor->getMapa();

		// Defino iterador de cartas de juego.
		Mapa::IteradorGameCard gameCardIter;
		// Itero por cada carta de juego.
		for (gameCardIter = map->primerGameCard();
			gameCardIter != map->ultimoGameCard(); ++gameCardIter) {
			// Obtengo carta de juego actual.
            ReferenceCountPtr<GameCard> gameCard = *gameCardIter;

			// Creo fila de lista de cartas de juego.
            Gtk::TreeModel::Row row = *(this->gameCardTreeModel->append());
            // Lleno la fila
            row[gameCardColumns.gameCardName] =gameCard->getName();
		}
	}
}

void ViewGameCardsFrame::setEditor(const ReferenceCountPtr<Editor>& editor) {
	this->editor = editor;

	// Se agrega como observador del editor.
	if (this->editor != NULL) {
		this->editor->registerObserver(this);
	}

	// Popula la lista de cartas de juego.
	this->populate();
}

ReferenceCountPtr<Editor>& ViewGameCardsFrame::getEditor() {
	return this->editor;
}

void ViewGameCardsFrame::update(Subject* subject) {
	// Popula la lista de cartas de juego.
	this->populate();
}

ViewGameCardsFrame::~ViewGameCardsFrame() {
	// No realiza ninguna accion.
}

