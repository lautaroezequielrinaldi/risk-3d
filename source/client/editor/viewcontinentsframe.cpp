#include "viewcontinentsframe.h"
ViewContinentsFrame::ViewContinentsFrame():
    Observer(),
    Gtk::Frame(),
    editor(),
    columns(),
    treeModel(),
    treeView() {
    // Inicializa el modelo de la lista de continentes.
    this->initializeTreeModel();
    // Inicializa la lista de continentes.
    this->initializeTreeView();
    // Agrega como widget hijo a la lista de continentes.
    this->add(this->treeView);
}

void ViewContinentsFrame::initializeTreeModel() {
    this->treeModel = Gtk::ListStore::create(columns);
}

void ViewContinentsFrame::initializeTreeView() {
    this->treeView.append_column("Nombre", columns.continentName);
    this->treeView.append_column("Bonus", columns.continentBonus);
    this->treeView.set_model(this->treeModel);
}

void ViewContinentsFrame::setEditor(const ReferenceCountPtr<Editor>& editor) {
    this->editor = editor;
}

ReferenceCountPtr<Editor> ViewContinentsFrame::getEditor() {
    return this->editor;
}

void ViewContinentsFrame::update(Subject* subject) {
    // Borro la lista de continentes.
    this->treeModel->clear();

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
            Gtk::TreeModel::Row row = *(this->treeModel->append());

            // Lleno la fila
            row[columns.continentName] = continente->getNombre();
            row[columns.continentBonus] = continente->getArmyBonus();
        }
    }
}

ViewContinentsFrame::~ViewContinentsFrame() {
    // No realiza ninguna acciòn.
}

