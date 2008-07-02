#include "gamecardcolumns.h"

GameCardColumns::GameCardColumns():
    Gtk::TreeModelColumnRecord() {
    // Agrega la columna para el nombre del game card.
    this->add(gameCardName);
}

GameCardColumns::~GameCardColumns() {
    // No realiza ninguna acciòn.
}

