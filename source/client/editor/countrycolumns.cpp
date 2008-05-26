#include "countrycolumns.h"

CountryColumns::CountryColumns():
    Gtk::TreeModelColumnRecord() {
    // Agrega la columna para el nombre del pais.
    this->add(countryName);
}

CountryColumns::~CountryColumns() {
    // No realiza ninguna acciòn.
}

