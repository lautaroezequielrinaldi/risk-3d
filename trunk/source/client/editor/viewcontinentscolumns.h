#ifndef __VIEWCONTINENTSCOLUMNS_H__
#define __VIEWCONTINENTSCOLUMNS_H__

#include<string> // Para definiciòn de std::string
#include<gtkmm/treemodelcolumn.h> // Para definiciòn de
// Gtk::TreeModelColumnRecord y Gtk::TreeModelColumn.

/**
 * Clase cuyo propòsito es definir las columnas bàsicas que va a mostrar la
 * lista de continentes del frame ViewContinentsFrame.
 */
class ViewContinentsColumns: public Gtk::TreeModelColumnRecord {
    /**
     * Atributos privados de la clase ViewContinentsColumns.
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
     * Mètodos pùblicos de la clase ViewContinentsColumns.
     */
    public:
        /**
         * Constructor de la clase ViewContinentsColumns.
         */
        ViewContinentsColumns();
        /**
         * Destructor de la clase ViewContinentsColumns.
         */
        ~ViewContinentsColumns();
};

#endif /** __VIEWCONTINENTSCOLUMNS_H__ */

