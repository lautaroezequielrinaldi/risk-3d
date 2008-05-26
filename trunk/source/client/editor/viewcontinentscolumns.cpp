#include "viewcontinentscolumns.h"

ViewContinentsColumns::ViewContinentsColumns():
    Gtk::TreeModelColumnRecord() {
    // Agrega la columna para el nombre del continente.
    this->add(continentName);
    // Agrega la columna para el bonus del continente.
    this->add(continentBonus);
}

ViewContinentsColumns::~ViewContinentsColumns() {
    // No realiza ninguna acciòn.
}

