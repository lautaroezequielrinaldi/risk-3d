#ifndef __COLORCOLUMNS_H__
#define __COLORCOLUMNS_H__

#include<string> // Para definiciòn de std::string
#include<gtkmm/treemodelcolumn.h> // Para definiciòn de
// Gtk::TreeModelColumnRecord y Gtk::TreeModelColumn.

/**
 * Clase cuyo propòsito es definir las columnas bàsicas que va a mostrar la
 * lista de colors del frame ViewColorsFrame.
 */
class ColorColumns: public Gtk::TreeModelColumnRecord {
    /**
     * Atributos privados de la clase ColorColumns.
     */
    public:
        /**
         * Almacena la columna del nombre del color.
         */
        Gtk::TreeModelColumn<std::string> colorName;
        /**
         * Almacena la columna del id del color.
         */
        Gtk::TreeModelColumn<int> colorId;

    /**
     * Mètodos pùblicos de la clase ColorColumns.
     */
    public:
        /**
         * Constructor de la clase ColorColumns.
         */
        ColorColumns();
        /**
         * Destructor de la clase ColorColumns.
         */
        ~ColorColumns();
};

#endif /** __COLORCOLUMNS_H__ */

