#ifndef __GAMECARDCOLUMNS_H__
#define __GAMECARDCOLUMNS_H__

#include<string> // Para definiciòn de std::string
#include<gtkmm/treemodelcolumn.h> // Para definiciòn de
// Gtk::TreeModelColumnRecord y Gtk::TreeModelColumn.

/**
 * Clase cuyo propòsito es definir las columnas bàsicas que va a mostrar la
 * lista de game cards.
 */
class GameCardColumns: public Gtk::TreeModelColumnRecord {
    /**
     * Atributos privados de la clase GameCardColumns.
     */
    public:
        /**
         * Almacena la columna del nombre del game card.
         */
        Gtk::TreeModelColumn<std::string> gameCardName;

    /**
     * Mètodos pùblicos de la clase GameCardColumns.
     */
    public:
        /**
         * Constructor de la clase GameCardColumns.
         */
        CountryColumns();
        /**
         * Destructor de la clase GameCardColumns.
         */
        ~CountryColumns();
};

#endif /** __GAMECARDCOLUMNS_H__ */

