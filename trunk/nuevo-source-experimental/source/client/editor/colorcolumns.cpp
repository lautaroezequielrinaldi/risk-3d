#include "colorcolumns.h"

ColorColumns::ColorColumns():
    Gtk::TreeModelColumnRecord() {
    // Agrega la columna para el nombre del color.
    this->add(colorName);
    // Agrega la columna para el bonus del color.
    this->add(colorId);
}

ColorColumns::~ColorColumns() {
    // No realiza ninguna acciòn.
}

