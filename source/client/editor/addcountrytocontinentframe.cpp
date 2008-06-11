#include "addcountrytocontinentframe.h"

AddCountryToContinentFrame::AddCountryToContinentFrame(
    const ReferenceCountPtr<Editor>& editor):
    Observer(),
    Gtk::Frame(),
    editor(editor),
    verticalBox(),
    continentColumns(),
    countryColumns(),
    continentTreeModel(),
    countryTreeModel(),
    continentLabel(),
    countryLabel(),
    continentComboBox(),
    countryComboBox(),
    addButton() {
    // Establece el titulo del frame.
    this->set_label("Agregar pais a continente");

    // Se agrega como observer del editor.
    if (this->editor != NULL) {
        this->editor->registerObserver(this);
    }

    // Inicializa el modelo de la lista de continentes. 
    this->initializeContinentTreeModel();
    // Inicializa el modelo de la lista de paises.
    this->initializeCountryTreeModel();
    // Inicializa el combo box de la lista de continentes.
    this->initializeContinentComboBox();
    // Inicializa el tree view de la lista de paises.
    this->initializeCountryComboBox();

    // Establezco label para la lista de continentes.
    this->continentLabel.set_text("Seleccione Continente:");

    // Establezco label para lista de paises.
    this->countryLabel.set_text("Seleccione Pais:");

    // Establece el label del boton addButton.
    this->addButton.set_label("Agregar Pais A Continente");

    // Agrega el label de la lista de continentes.
    this->verticalBox.pack_start(this->continentLabel,
        Gtk::PACK_SHRINK);

    // Agrega el combobox de continentes al verical box.
    this->verticalBox.pack_start(this->continentComboBox,
        Gtk::PACK_SHRINK);

    // Agrega el label de la lista de paises.
    this->verticalBox.pack_start(this->countryLabel,
        Gtk::PACK_SHRINK);

    // Agrega el combo box de paises al vertical box.
    this->verticalBox.pack_start(this->countryComboBox,
        Gtk::PACK_SHRINK);

    // Agrega el boton addButton al vertical box.
    this->verticalBox.pack_start(this->addButton,
        Gtk::PACK_SHRINK);

    // Agrega el vertical box al frame.
    this->add(this->verticalBox);

    // Asocia la señal signal_clicked del boton addButton a su manejador.
    this->addButton.signal_clicked().connect(sigc::mem_fun(*this,
        &AddCountryToContinentFrame::onAddButtonClicked));

    // Popula la lista de continentes y la lista de paises.
    this->populate();
}

void AddCountryToContinentFrame::initializeContinentTreeModel() {
    this->continentTreeModel = Gtk::ListStore::create(continentColumns);
}

void AddCountryToContinentFrame::initializeCountryTreeModel() {
    this->countryTreeModel = Gtk::ListStore::create(countryColumns);
}

void AddCountryToContinentFrame::initializeContinentComboBox() {
    this->continentComboBox.set_model(this->continentTreeModel);
    this->continentComboBox.pack_start(this->continentColumns.continentName);
}

void AddCountryToContinentFrame::initializeCountryComboBox() {
    this->countryComboBox.set_model(this->countryTreeModel);
    this->countryComboBox.pack_start(countryColumns.countryName);
}

void AddCountryToContinentFrame::populate() {
    // Limpio la lista de continentes.
    this->continentTreeModel->clear();
    // Limpio la lista de paises.
    this->countryTreeModel->clear();

    // Si el editor no es null y el mapa no es null.
    if (editor != NULL && editor->getMapa() != NULL) {
        // Obtengo el mapa del modelo.
        ReferenceCountPtr<Mapa> mapa = editor->getMapa();
        // Defino iterador de continentes.
        Mapa::IteradorContinente continentIter;

        // Itero por cada continente.
        for (continentIter = mapa->primerContinente();
            continentIter != mapa->ultimoContinente(); ++continentIter) {
            // Obtengo continente actual.
            ReferenceCountPtr<Continente> continent = *continentIter;
            // Creo fila de lista de continentes.
            Gtk::TreeModel::Row row = *(this->continentTreeModel->append());
            // Agrego nombre de continente a fila de lista de continentes.
            row[continentColumns.continentName] = continent->getNombre();
        }

        // Defino iterador de paises.
        Mapa::IteradorPais countryIter;

        // Itero por cada pais.
        for (countryIter = mapa->primerPais();
            countryIter != mapa->ultimoPais(); ++countryIter) {
            // Obtengo pais actual.
            ReferenceCountPtr<Pais> country = *countryIter;
            // Creo fila de lista de paises.
            Gtk::TreeModel::Row row = *(this->countryTreeModel->append());
            // Agrego nombre de pais a fila de lista de paises.
            row[countryColumns.countryName] = country->getNombre();
        }   
    }
}

void AddCountryToContinentFrame::onAddButtonClicked() {
    // Si el editor no es null y el mapa no es null.
    if (editor != NULL && editor->getMapa() != NULL) {
        // Obtengo el mapa del modelo.
        ReferenceCountPtr<Mapa> mapa = editor->getMapa();
        // Obtengo continente activo del combobox.
        Gtk::TreeModel::iterator activeContinent =
            this->continentComboBox.get_active();
        // Obtengo el pais activo del combobox.
        Gtk::TreeModel::iterator activeCountry =
            this->countryComboBox.get_active();
        // Si hay elemento activo en ambos combobox.
        if (activeContinent && activeCountry) {
            // Obtengo la fila de continente que representa ese elemento.
            Gtk::TreeModel::Row activeContinentRow = *activeContinent;
            // Obtengo la fila de pais que representa a ese elemento.
            Gtk::TreeModel::Row activeCountryRow = *activeCountry;
            
            // Obtengo nombre del continente seleccionado.
            std::string continentName =
                activeContinentRow[continentColumns.continentName];
            // Obtengo nombre del pais seleccionado.
            std::string countryName =
                activeCountryRow[countryColumns.countryName];

            // Obtengo continente seleccionado.
            ReferenceCountPtr<Continente> continent =
                mapa->obtenerContinente(continentName);
            // Obtengo pais seleccionado.
            ReferenceCountPtr<Pais> country = mapa->obtenerPais(countryName);
            // Agrego pais a continente.
            continent->agregarPais(country);
            // Notifico de cambios en el editor y en el mapa del editor.
            this->editor->notify();
        }
    }
}

void AddCountryToContinentFrame::setEditor(
    const ReferenceCountPtr<Editor>& editor) {
    this->editor = editor;

    // Se agrega como observer del editor.
    if (this->editor != NULL) {
        this->editor->registerObserver(this);
    }

    // Popula la lista de continentes y la lista de paises.
    this->populate();
}

ReferenceCountPtr<Editor>& AddCountryToContinentFrame::getEditor() {
    return this->editor;
}

void AddCountryToContinentFrame::update(Subject* subject) {
    // Popula la lista de continentes y la lista de paises.
    this->populate();
}

AddCountryToContinentFrame::~AddCountryToContinentFrame() {
    // No realiza ninguna acciòn.
}

