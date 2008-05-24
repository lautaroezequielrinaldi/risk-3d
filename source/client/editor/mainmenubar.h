#ifndef __MAINMENUBAR_H__
#define __MAINMENUBAR_H__

#include<gtkmm/menubar.h> // Para definiciòn de Gtk::MenuBar.
#include<gtkmm/menuitem.h> // Para definiciòn de Gtk::MenuItem.
#include<gtkmm/menu.h> // Para definiciòn de Gtk::Menu.
#include<glibmm/signalproxy.h> // Para definiciòn de Glib::SignalProxy0.

/**
 * Clase que encapsula a la barra de menues de la ventana principal del editor.
 */
class MainMenuBar: public Gtk::MenuBar {
    /**
     * Atributos privados de la clase MainMenuBar.
     */
    private:
        /**
         * Almacena el item de menu archivo.
         */
        Gtk::MenuItem fileMenuItem;
        /**
         * Almacena el item de menu nuevo mapa.
         */
        Gtk::MenuItem newMapMenuItem;
        /**
         * Almacena el item de menu cargar mapa.
         */
        Gtk::MenuItem loadMapMenuItem;
        /**
         * Almacena el item de menu guardar mapa,
         */
        Gtk::MenuItem saveMapMenuItem;
        /**
         * Almacena el item de menu salir.
         */
        Gtk::MenuItem quitMenuItem;
        /**
         * Almacena el menu archivo.
         */
        Gtk::Menu fileMenu;

    /**
     * Mètodos privados de la clase MainMenuBar.
     */
    private:
        /**
         * Constructor copia de la clase MainMenuBar.
         */
        MainMenuBar(const MainMenuBar& otherInstance);
        /**
         * Operador de asignaciòn de la clase MainMenuBar.
         */
        MainMenuBar& operator=(const MainMenuBar& otherInstance);

    /**
     * Mètodos pùblicos de la clase MainMenuBar.
     */
    public:
        /**
         * Constructor de la clase MainMenuBar.
         */
        MainMenuBar();
        /**
         * Obtiene el signal activate del item de menu nuevo mapa.
         */
        Glib::SignalProxy0<void> newMapSignalActivate();
        /**
         * Obtiene el signal activate del item de menu cargar mapa.
         */
        Glib::SignalProxy0<void> loadMapSignalActivate();
        /**
         * Obtiene el signal actiate del item de menu guardar mapa.
         */
        Glib::SignalProxy0<void> saveMapSignalActivate();
        /**
         * Obtiene el signal activate del item de menu salir.
         */
        Glib::SignalProxy0<void> quitSignalActivate();
        /**
         * Destructor virtual de la clase MainMenuBar.
         */
        ~MainMenuBar();
};

#endif /** __MAINMENUBAR_H__ */

