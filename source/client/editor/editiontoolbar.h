#ifndef __EDITIONTOOLBAR_H__
#define __EDITIONTOOLBAR_H__

#include<gtkmm/toolbar.h> // Para definiciòn de Gtk::Toolbar.
#include<gtkmm/toolbutton.h> // Para definiciòn de Gtk::ToolButton.
#include<glibmm/signalproxy.h> // Para definiciòn de Glib::SignalProxy0.

/**
 * Clase que encapsula a la barra de herramientas principal de la ventana
 * principal.
 */
class EditionToolBar: public Gtk::Toolbar {
    /**
     * Atributos privados de la clase EditionToolBar.
     */
    private:
        /**
         * Almacena el boton de seleccion de paises.
         */
        Gtk::ToolButton selectionToolButton;
        /**
         * Almacena el boton de creacion de paises.
         */
        Gtk::ToolButton creationToolButton;

    /**
     * Mètodos privados de la clase EditionToolBar.
     */
    private:
        /**
         * Constructor copia de la clase EditionToolBar.
         */
        EditionToolBar(const EditionToolBar& otherInstance);
        /**
         * Operador de asignaciòn de la clase EditionToolBar.
         */
        EditionToolBar& operator=(const EditionToolBar& otherInstance);

    /**
     * Mètodos pùblicos de la clase EditionToolBar.
     */
    public:
        /**
         * Constructor de la clase EditionToolBar.
         */
        EditionToolBar();
        /**
         * Obtiene el signal clicked del boton de seleccion de paises.
         */
        Glib::SignalProxy0<void> selectionSignalClicked();
        /**
         * Obtiene el signal clicked del boton de creacion de paises.
         */
        Glib::SignalProxy0<void> creationSignalClicked();
        /**
         * Constructor virtual de la clse EditionToolBar.
         */
        virtual ~EditionToolBar();
};

#endif /** __EDITIONTOOLBAR_H__ */

