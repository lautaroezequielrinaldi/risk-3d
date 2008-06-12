#include "conquercontinentframe.h"

ConquerContinentFrame::ConquerContinentFrame(
	const ReferenceCountPtr<Editor>& editor):
	Observer(),
	GameCardFrame(editor),
	continentLabel(),
	continentTreeModel(),
	continentComboBox(),
	addGameCardButton() {
	// Establece el titulo del frame.
	this->set_label("Carta para comquistar continente");
	// Se agrega como observador del editor.
	if (this->editor != NULL) {
		this->editor->registerObserver(this);
	}

	// Inicializa el modelo de tree para la lista de continentes.
	this->initializeContinentTreeModel();
	// Inicializa el combo box para la lista de continentes.
	this->initializeContinentComboBox();

	// Establece el texto del label para continente.
	this->continentLabel.set_text("Seleccione continente:");

	// Agrega el label para el continente al vertical box.
	this->verticalBox.pack_start(this->continentLabel,
		Gtk::PACK_SHRINK);
	// Agrega el combo box para la lista de continentes al vertical box.
	this->verticalBox.pack_start(this->continentComboBox,
		Gtk::PACK_SHRINK);
	// Popula la lista de continentes.
	this->populate();
}

void ConquerContinentFrame::initializeContinentTreeModel() {
    this->continentTreeModel = Gtk::ListStore::create(continentColumns);
}

void ConquerContinentFrame::initializeContinentComboBox() {
    this->continentComboBox.set_model(this->continentTreeModel);
    this->continentComboBox.pack_start(continentColumns.continentName);
}

void ConquerContinentFrame::populate() {
    // Limpio la lista de continentes.
    this->continentTreeModel->clear();

	// Si el editor no es null y el mapa no es null.
    if (this->editor != NULL && this->editor->getMapa() != NULL) {
		// Obtengo el map del modelo.
        ReferenceCountPtr<Mapa> map = this->editor->getMapa();
		// Defino iterador de continentes.
        Mapa::IteradorContinente continentIter;
		// Itero por cada continente.
        for (continentIter = map->primerContinente();
		    continentIter != map->ultimoContinente(); ++continentIter) {
			// Obtengo continente actual.
            ReferenceCountPtr<Continente> continent = *continentIter;
            // Creo fila de lista de continentes.
            Gtk::TreeModel::Row row = *(this->continentTreeModel->append());
            // Agrego nombre de continente a fila de lista de continentes.
            row[continentColumns.continentName] = continent->getNombre();
		}
    }
}

void ConquerContinentFrame::onAddGameCardButtonClicked() {
    // Verifico que editor y map no sea NULL
    if (editor != NULL && editor->getMapa() != NULL) {
        // Obtengo el mapa
        ReferenceCountPtr<Mapa> map = editor->getMapa();

        // Obtengo elmemento activo de combo box de continentes.
        Gtk::TreeModel::iterator activeContinent =
            this->continentComboBox.get_active();
        // Si hay elemento activo en el combobox.
        if (activeContinent) {
            // Obtengo la fila de continente que representa ese elemento.
            Gtk::TreeModel::Row activeRow = *activeContinent;

            // Obtengo nombre del continente seleccionado.
            std::string continentName =
                activeRow[continentColumns.continentName];
            // Obtengo nombre de carta de juego.
            std::string gameCardName = this->gameCardNameEntry.get_text();

            // Verifico si escribio un nombre de carta de juego.
            if (!gameCardName.empty()) {
                // Creo carta de juego para conquistar continente.
                ReferenceCountPtr<GameCard> gameCard =
                    new ConquerContinentGameCard(gameCardName, continentName);
                // Agrego carta de juego al editor.
                map->agregarGameCard(gameCard);
                // Notifico de cambios en el editor.
                this->editor->notify();
            }
        }
    }
}
                
void ConquerContinentFrame::setEditor(const ReferenceCountPtr<Editor>& editor) {
	GameCardFrame::setEditor(editor);	

    // Se agrega como observador del editor.
    if (this->editor != NULL) {
		this->editor->registerObserver(this);
    }

	// Popula la lista de continentes.
	this->populate();
}

ReferenceCountPtr<Editor>& ConquerContinentFrame::getEditor() {
	return GameCardFrame::getEditor();
}

void ConquerContinentFrame::update(Subject* subject) {
	// Popula la lista de continentes.
	this->populate();
}

ConquerContinentFrame::~ConquerContinentFrame() {
	// No realiza ninguna accion.
}

