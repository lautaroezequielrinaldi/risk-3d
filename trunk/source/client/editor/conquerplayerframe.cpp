#include "conquerplayerframe.h"

ConquerPlayerFrame::ConquerPlayerFrame(const ReferenceCountPtr<Editor>& editor):	GameCardFrame(editor),
	colorLabel(),
	colorTreeModel(),
	colorComboBox() {

	// Inicializa el modelo de tree de la lista de colores.
	this->initializeColorTreeModel();
	// Inicializa el combo box de la lista de colores.
	this->initializeColorComboBox();

	// Agrega el label de colores al vertical box.
	this->verticalBox.pack_start(this->colorLabel,
		Gtk::PACK_SHRINK);
	// Agrega el combo box de colores al vertical box.
	this->verticalBox.pack_start(this->colorComboBox,
		Gtk::PACK_SHRINK);
}

void ConquerPlayerFrame::initializeColorTreeModel() {
    this->colorTreeModel = Gtk::ListStore::create(colorColumns);
}

void ConquerPlayerFrame::initializeColorComboBox() {
    this->colorComboBox.set_model(this->colorTreeModel);
    this->colorComboBox.pack_start(colorColumns.colorName);
	// Defino fila de lista de colores.
    Gtk::TreeModel::Row row;
	// Creo fila para color rojo.
	row = *(this->colorTreeModel->append());
	// Agrego color rojo a la fila.
	row[colorColumns.colorId] = 1;
    row[colorColumns.colorName] = "ROJO";
    // Creo fila para color negro.
    row = *(this->colorTreeModel->append());
    // Agrego color negro a la fila.
    row[colorColumns.colorId] = 2;
    row[colorColumns.colorName] = "NEGRO";
    // Creo fila para color verde.
    row = *(this->colorTreeModel->append());
    // Agrego color verde a la fila.
    row[colorColumns.colorId] = 3;
    row[colorColumns.colorName] = "VERDE";
    // Creo fila para color amarillo.
    row = *(this->colorTreeModel->append());
    // Agrego color amarillo a la fila.
    row[colorColumns.colorId] = 4;
    row[colorColumns.colorName] = "AMARILLO";
    // Creo fila para color azul.
    row = *(this->colorTreeModel->append());
	// Agrego color azul a la fila.
    row[colorColumns.colorId] = 5;
    row[colorColumns.colorName] = "AZUL";
    // Creo fila para color blanco.
    row = *(this->colorTreeModel->append());
    // Agrego color blanco a la fila.
    row[colorColumns.colorId] = 6;
    row[colorColumns.colorName] = "BLANCO";
}

void ConquerPlayerFrame::onAddGameCardButtonClicked() {
    // Verifico que editor y map no sea NULL
    if (editor != NULL && editor->getMapa() != NULL) {
        // Obtengo el mapa
        ReferenceCountPtr<Mapa> map = editor->getMapa();
        // Obtengo elmemento activo de combo box de colores.
        Gtk::TreeModel::iterator activeColor =
        this->colorComboBox.get_active();
        // Si hay elemento activo en el combobox.
        if (activeColor) {
            // Obtengo la fila de continente que representa ese elemento.
            Gtk::TreeModel::Row activeRow = *activeColor;

			// Obtengo el id de color.
			int colorId = activeRow[colorColumns.colorId];
            // Obtengo nombre de carta de juego.
            std::string gameCardName = this->gameCardNameEntry.get_text();

            // Verifico si escribio un nombre de carta de juego.
            if (!gameCardName.empty()) {
                // Creo carta de juego para conquistar jugador.
                ReferenceCountPtr<GameCard> gameCard =
					new ConquerPlayerGameCard(gameCardName, colorId);
				// Agrega carta de juego al mapa.
				map->agregarGameCard(gameCard);
				// Notifica de los cambios en el editor.
				this->editor->notify();
			}
		}
	}
}

ConquerPlayerFrame::~ConquerPlayerFrame() {
	// No realiza niguna accion.
}

