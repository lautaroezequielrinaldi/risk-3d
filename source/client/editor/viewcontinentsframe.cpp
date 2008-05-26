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

ViewContinentsFrame::ViewContinentsFrame(
    const ReferenceCountPtr<Editor>& editor):
    Observer(),
    Gtk::Frame(),
    editor(editor),
    columns(),
    treeModel(),
    treeView() {
    // No realiza ninguna opciòn.
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
    // Borra todas las filas del tree view.
    this->treeModel->clear();
}

ViewContinentsFrame::~ViewContinentsFrame() {
    // No realiza ninguna acciòn.
}

