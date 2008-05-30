#include "viewcontinentsframe.h"
ViewContinentsFrame::ViewContinentsFrame():
    Observer(),
    Gtk::Frame(),
    editor(),
    continentColumns(),
    continentTreeModel(),
    continentTreeView() {
    // Inicializa el modelo de la lista de continentes.
    this->initializeContinentTreeModel();
    // Inicializa la lista de continentes.
    this->initializeContinentTreeView();
    // Agrega como widget hijo a la lista de continentes.
    this->add(this->continentTreeView);

    // Popula la lista de continentes.
    this->populate();
}

void ViewContinentsFrame::initializeContinentTreeModel() {
    this->continentTreeModel = Gtk::ListStore::create(continentColumns);
}

void ViewContinentsFrame::initializeContinentTreeView() {
    this->continentTreeView.append_column("Nombre",
        continentColumns.continentName);
    this->continentTreeView.append_column("Bonus",
        continentColumns.continentBonus);
    this->continentTreeView.set_model(this->continentTreeModel);
}

void ViewContinentsFrame::setEditor(const ReferenceCountPtr<Editor>& editor) {
    this->editor = editor;
    // Popula la lista de continentes.
    this->populate();
}

ReferenceCountPtr<Editor>& ViewContinentsFrame::getEditor() {
    return this->editor;
}

void ViewContinentsFrame::populate() {
    // Borro la lista de continentes.
    this->continentTreeModel->clear();

    if (this->editor != NULL && this->editor->getMapa() != NULL) {
        // Obtengo el mapa del editor
        ReferenceCountPtr<Mapa> mapa = this->editor->getMapa();

        // Defino iterador de continentes.
        Mapa::IteradorContinente continenteIter;

        // Itero por cada continente.
        for (continenteIter = mapa->primerContinente();
            continenteIter != mapa->ultimoContinente(); ++continenteIter) {
            // Obtengo continente actual.
            ReferenceCountPtr<Continente> continente = *continenteIter;

            // Creo fila de lista de continentes.
            Gtk::TreeModel::Row row = *(this->continentTreeModel->append());
            // Lleno la fila
            row[continentColumns.continentName] = continente->getNombre();
            row[continentColumns.continentBonus] = continente->getArmyBonus();
        }
    }
}

void ViewContinentsFrame::update(Subject* subject) {
    // Popula la lista de continentes.
    this->populate();
}

ViewContinentsFrame::~ViewContinentsFrame() {
    // No realiza ninguna acciòn.
}

