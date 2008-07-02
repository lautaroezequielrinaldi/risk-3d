#ifndef __COUNTRYCOLUMNS_H__
#define __COUNTRYCOLUMNS_H__

#include<string> // Para definiciòn de std::string
#include<gtkmm/treemodelcolumn.h> // Para definiciòn de
// Gtk::TreeModelColumnRecord y Gtk::TreeModelColumn.

/**
 * Clase cuyo propòsito es definir las columnas bàsicas que va a mostrar la
 * lista de countryes del frame ViewCountrysFrame.
 */
class CountryColumns: public Gtk::TreeModelColumnRecord {
    /**
     * Atributos privados de la clase CountryColumns.
     */
    public:
        /**
         * Almacena la columna del nombre del countrye.
         */
        Gtk::TreeModelColumn<std::string> countryName;

    /**
     * Mètodos pùblicos de la clase CountryColumns.
     */
    public:
        /**
         * Constructor de la clase CountryColumns.
         */
        CountryColumns();
        /**
         * Destructor de la clase CountryColumns.
         */
        ~CountryColumns();
};

#endif /** __COUNTRYCOLUMNS_H__ */

