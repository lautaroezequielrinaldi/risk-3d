#ifndef __CONTINENTCOLUMNS_H__
#define __CONTINENTCOLUMNS_H__

#include<string> // Para definiciòn de std::string
#include<gtkmm/treemodelcolumn.h> // Para definiciòn de
// Gtk::TreeModelColumnRecord y Gtk::TreeModelColumn.

/**
 * Clase cuyo propòsito es definir las columnas bàsicas que va a mostrar la
 * lista de continentes del frame ViewContinentsFrame.
 */
class ContinentColumns: public Gtk::TreeModelColumnRecord {
    /**
     * Atributos privados de la clase ContinentColumns.
     */
    public:
        /**
         * Almacena la columna del nombre del continente.
         */
        Gtk::TreeModelColumn<std::string> continentName;
        /**
         * Almacena la columna del bonus del continente.
         */
        Gtk::TreeModelColumn<int> continentBonus;

    /**
     * Mètodos pùblicos de la clase ContinentColumns.
     */
    public:
        /**
         * Constructor de la clase ContinentColumns.
         */
        ContinentColumns();
        /**
         * Destructor de la clase ContinentColumns.
         */
        ~ContinentColumns();
};

#endif /** __CONTINENTCOLUMNS_H__ */

