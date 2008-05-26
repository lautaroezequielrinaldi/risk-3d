#include "continentcolumns.h"

ContinentColumns::ContinentColumns():
    Gtk::TreeModelColumnRecord() {
    // Agrega la columna para el nombre del continente.
    this->add(continentName);
    // Agrega la columna para el bonus del continente.
    this->add(continentBonus);
}

ContinentColumns::~ContinentColumns() {
    // No realiza ninguna acciòn.
}

