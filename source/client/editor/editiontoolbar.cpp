#include "editiontoolbar.h"

EditionToolBar::EditionToolBar():
    Gtk::Toolbar(),
    selectionToolButton(),
    creationToolButton() {
    // Asigna el label al boton de seleccion de paises.
    this->selectionToolButton.set_label("Seleccionar Pais");
    // Asigna el label al boton de creacion de paises.
    this->creationToolButton.set_label("Crear pais");

    // Agrega el boton de seleccion de paises a la barra de herramientas.
    this->append(selectionToolButton);
    // Agrego el boton de creacion de paises a la barra de herramientas.
    this->append(creationToolButton);
}

Glib::SignalProxy0<void> EditionToolBar::selectionSignalClicked() {
    return this->selectionToolButton.signal_clicked();
}

Glib::SignalProxy0<void> EditionToolBar::creationSignalClicked() {
    return this->creationToolButton.signal_clicked();
}

EditionToolBar::~EditionToolBar() {
    // No realiza ninguna acciòn.
}

