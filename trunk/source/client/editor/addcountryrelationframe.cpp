#include "addcountryrelationframe.h"

AddCountryRelationFrame::AddCountryRelationFrame(
    const ReferenceCountPtr<Editor>& editor):
    Observer(),
    Gtk::Frame(),
    editor(editor),
    verticalBox(),
    countryColumns(),
    firstCountryTreeModel(),
    secondCountryTreeModel(),
    firstCountryLabel(),
    secondCountryLabel(),
    firstCountryComboBox(),
    secondCountryComboBox(),
    addRelationButton() {
    // Establece el titulo del frame.
    this->set_label("Relacionar paises como adyacentes");

    // Se agrega como observer del editor.
    if (this->editor != NULL) {
        this->editor->registerObserver(this);
    }

    // Inicializa el modelo de tree del primer pais.
    this->initializeFirstCountryTreeModel();
    // Inicializa el modelo de tree del segundo pais.
    this->initializeSecondCountryTreeModel();
    // Inicializa el combo box del primer pais.
    this->initializeFirstCountryComboBox();
    // Inicializa el combo box del segundo pais.
    this->initializeSecondCountryComboBox();

    // Establezco label para primer pais.
    this->firstCountryLabel.set_text("Seleccione primer pais:");

    // Establezco label para segundo pais.
    this->secondCountryLabel.set_text("Seleccione segundo pais:");

    // Agrego el label del boton agregar relacion.
    this->addRelationButton.set_label("Agregar Relacion");

    // Agrego el label del primer pais al vertical box.
    this->verticalBox.pack_start(this->firstCountryLabel,
        Gtk::PACK_SHRINK);

    // Agrego el combo box del primer pais al vertical box.
    this->verticalBox.pack_start(this->firstCountryComboBox,
        Gtk::PACK_SHRINK);

    // Agrego el label del segundo pais al vertical box.
    this->verticalBox.pack_start(this->secondCountryLabel,
        Gtk::PACK_SHRINK);

    // Agrego el combo box del segundo pais al vertical box.
    this->verticalBox.pack_start(this->secondCountryComboBox,
        Gtk::PACK_SHRINK);

    // Agrego el boton de establecer relacion al vertical box.
    this->verticalBox.pack_start(this->addRelationButton,
        Gtk::PACK_SHRINK);

    // Agrega el vertical box al frame.
    this->add(this->verticalBox);

    // Asocio manejador de señal signal_clicked del addRelationButton.
    this->addRelationButton.signal_clicked().connect(sigc::mem_fun(*this,
        &AddCountryRelationFrame::onAddRelationButtonClicked));

    // Popula la lista de paises.
    this->populate();
}

void AddCountryRelationFrame::initializeFirstCountryTreeModel() {
    this->firstCountryTreeModel = Gtk::ListStore::create(countryColumns);
}

void AddCountryRelationFrame::initializeSecondCountryTreeModel() {
    this->secondCountryTreeModel = Gtk::ListStore::create(countryColumns);
}

void AddCountryRelationFrame::initializeFirstCountryComboBox() {
    this->firstCountryComboBox.set_model(this->firstCountryTreeModel);
    this->firstCountryComboBox.pack_start(this->countryColumns.countryName);
}

void AddCountryRelationFrame::initializeSecondCountryComboBox() {
    this->secondCountryComboBox.set_model(this->secondCountryTreeModel);
    this->secondCountryComboBox.pack_start(this->countryColumns.countryName);
}

void AddCountryRelationFrame::populate() {
    // Limpio la lista de paises.
    this->firstCountryTreeModel->clear();
    // Limpio la lista de paises.
    this->secondCountryTreeModel->clear();

    // Si el editor no es null y el mapa no es null.
    if (editor != NULL && editor->getMapa() != NULL) {
        // Obtengo mapa.
        ReferenceCountPtr<Mapa> map = editor->getMapa();

        // Defino iterador de paises.
        Mapa::IteradorPais countryIter;

        // Itero por todos los paises.
        for (countryIter = map->primerPais();
            countryIter != map->ultimoPais(); ++countryIter) {
            // Obtengo pais actual.
            ReferenceCountPtr<Pais> country = *countryIter;
            // Defino fila de lista de paises.
            Gtk::TreeModel::Row row;

            // Creo fila de lista de paises.
            row  = *(this->firstCountryTreeModel->append());
            // Agrego nombre de pais a fila de lista de paises.
            row[countryColumns.countryName] = country->getNombre();
            // Creo fila de lista de paises.
            row = *(this->secondCountryTreeModel->append());
            // Agrego nombre de pais a fila de paises.
            row[countryColumns.countryName] = country->getNombre();
        }
    }
}

void AddCountryRelationFrame::onAddRelationButtonClicked() {
    // Si el editor no es null y el mapa no es null.
    if (this->editor != NULL && this->editor->getMapa() != NULL) {
        // Obtengo mapa del editor.
        ReferenceCountPtr<Mapa> map = this->editor->getMapa();

        // Obtengo primer pais activo del combobox.
        Gtk::TreeModel::iterator activeFirstCountry =
            this->firstCountryComboBox.get_active();
        // Obtengo segundo pais activo del combobox.
        Gtk::TreeModel::iterator activeSecondCountry =
            this->secondCountryComboBox.get_active();

        // Si hay elementos activos.
        if(activeFirstCountry && activeSecondCountry) {
            // Obtengo la fila de continente que representa ese elemento.
            Gtk::TreeModel::Row activeFirstCountryRow = *activeFirstCountry;
            // Obtengo la fila de pais que representa a ese elemento.
            Gtk::TreeModel::Row activeSecondCountryRow = *activeSecondCountry;

            // Obtengo nombre de primer pais.
            std::string firstName = activeFirstCountryRow[countryColumns.countryName];
            // Obtengo nomre de segundo pais.
            std::string secondName = activeSecondCountryRow[countryColumns.countryName];
            // Obtengo primer pais.
            ReferenceCountPtr<Pais> firstCountry = map->obtenerPais(firstName);
            // Obtengo segundo pais.
            ReferenceCountPtr<Pais> secondCountry = map->obtenerPais(secondName);

			// Si los paises son distintos.
			if (firstCountry != secondCountry) {
	            // Relaciono ambos paises.        
		        firstCountry->agregarAdyacente(secondCountry);
			    secondCountry->agregarAdyacente(firstCountry);
				// Notifica de los cambios al resto de la interfaz grafica
				this->editor->notify();
			}
        }
    }
}

void AddCountryRelationFrame::setEditor(
    const ReferenceCountPtr<Editor>& editor) {
    this->editor = editor;

    // Se agrega como observer del editor.
    if (this->editor != NULL) {
        this->editor->registerObserver(this);
    }

    // Popula la lista de paises.
    this->populate();
}

ReferenceCountPtr<Editor>& AddCountryRelationFrame::getEditor() {
    return this->editor;
}

void AddCountryRelationFrame::update(Subject* subject) {
    // Popula la lista de paises.
    this->populate();
}

AddCountryRelationFrame::~AddCountryRelationFrame() {
    // No realiza ninguna acciòn.
}

