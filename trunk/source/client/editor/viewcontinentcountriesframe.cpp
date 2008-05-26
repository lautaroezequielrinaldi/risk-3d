#include "viewcontinentcountriesframe.h"
#include<iostream>
ViewContinentCountriesFrame::ViewContinentCountriesFrame():
    Observer(),
    Gtk::Frame(),
    editor(),
    verticalBox(),
    continentColumns(),
    countryColumns(),
    continentTreeModel(),
    countryTreeModel(),
    continentComboBox(),
    countryTreeView() {
    // Inicializa el modelo de la lista de continentes.
    this->initializeContinentTreeModel();
    // Inicializa el modelo de la lista de paises.
    this->initializeCountryTreeModel();
    // Inicializa el combo box de la lista de continentes.
    this->initializeContinentComboBox();
    // Inicializa el tree view de la lista de paises.
    this->initializeCountryTreeView();

    // Agrega el combobox de continentes al verical box.
    this->verticalBox.add(this->continentComboBox);

    // Agrega el tree view de paises al vertical box.
    this->verticalBox.add(this->countryTreeView);

    // Agrega el vertical box al frame.
    this->add(this->verticalBox);
   
    // Asocia la señal signal_changed de la lista de continentes a su manejador.
    this->continentComboBox.signal_changed().connect(sigc::mem_fun(*this,
        &ViewContinentCountriesFrame::onContinentComboBoxChanged));
 
    // Popula la lista de continentes y la lista de paises.
    this->populate();
}

void ViewContinentCountriesFrame::initializeContinentTreeModel() {
    this->continentTreeModel = Gtk::ListStore::create(continentColumns);
}

void ViewContinentCountriesFrame::initializeCountryTreeModel() {
    this->countryTreeModel = Gtk::ListStore::create(countryColumns);
}

void ViewContinentCountriesFrame::initializeContinentComboBox() {
    this->continentComboBox.set_model(this->continentTreeModel);
    this->continentComboBox.pack_start(continentColumns.continentName);
}

void ViewContinentCountriesFrame::initializeCountryTreeView() {
    this->countryTreeView.append_column("Nombre",
        countryColumns.countryName);
    this->countryTreeView.set_model(this->countryTreeModel);
}

void ViewContinentCountriesFrame::populate() {
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

        // Obtengo elemento activo del combobox.
        Gtk::TreeModel::iterator activeContinent = this->continentComboBox.get_active();

        // Si hay elemento activo en el combobox.
        if (activeContinent) {
            // Obtengo la fila de continente que representa ese elemento.
            Gtk::TreeModel::Row activeRow = *activeContinent;

            // Obtengo nombre del continente seleccionado.
            std::string continentName = activeRow[continentColumns.continentName];

            // Obtengo continente con dicho nombre.
            ReferenceCountPtr<Continente> continent =
                mapa->obtenerContinente(continentName);
            // Defino iterador de paises del continente.
            Continente::Iterador countryIter;

            // Itero por cada pais del continente.
            for (countryIter = continent->primerPais();
                countryIter != continent->ultimoPais(); ++countryIter) {
                // Obtengo pais actual.
                ReferenceCountPtr<Pais> country = *countryIter;

                // Agrego una fila a lista de paises.
                Gtk::TreeModel::Row row = *(this->countryTreeModel->append());

                // Agrego el nombre de pais a la lista de paises.
                row[countryColumns.countryName] = country->getNombre();
            }
        }
    }
}

void ViewContinentCountriesFrame::onContinentComboBoxChanged() {
    // Popula la lista de continentes y la lista de paises.
    this->populate();
}

void ViewContinentCountriesFrame::setEditor(const ReferenceCountPtr<Editor>& editor) {
    this->editor = editor;
    // Popula la lista de continentes y la lista de paises.
    this->populate();
}

ReferenceCountPtr<Editor> ViewContinentCountriesFrame::getEditor() {
    return this->editor;
}

void ViewContinentCountriesFrame::update(Subject* subject) {
    // Popula la lista de continentes y la lista de paises.
    this->populate();
}

ViewContinentCountriesFrame::~ViewContinentCountriesFrame() {
    // No realiza ninguna acciòn.
}

