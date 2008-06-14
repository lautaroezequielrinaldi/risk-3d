#ifndef __MAINMENU_H__
#define __MAINMENU_H__

#include<gtkmm/menubar.h> // Para definicion de Gtk::MenuBar.
#include<gtkmm/menuitem.h> // Para definicion de Gtk::MenuItem.
#include<gtkmm/menu.h> // Para definicion de Gtk::Menu.
#include<glibmm/signalproxy.h> // Para definicion de Glib::SignalProxy0.

/**
 * Clase que encapsula el menu principal de la ventana del editor.
 */
class MainMenu: public Gtk::MenuBar {
	/**
     * Atributos privados de la clase ManiMenu.
     */
	private:
		/**
		 * Almacena el item de menu archivo.
		 */
		Gtk::MenuItem fileMenuItem;
		/**
		 * Almacena el menu archivo.
		 */
		Gtk::Menu fileMenu;
		/**
		 * Almacena el item de menu nuevo,
		 */
		Gtk::MenuItem newMenuItem;
		/**
		 * Almacena el item de menu	abrir.
		 */
		Gtk::MenuItem openMenuItem;
		/**
		 * Almacena el item de menu guardar.
		 */
		Gtk::MenuItem saveMenuItem;
		/**
		 * Almacena el item de menu salir.
		 */
		Gtk::MenuItem quitMenuItem;

	/**
	 * Metodos privados de la clase MainMenu.
	 */
	private:
		/**
		 * Constructor copia de la clase MainMenu.
		 */
		MainMenu(const MainMenu& otherInstance);
		/**
		 * Operador de asignacion de la clase MainMenu.
		 */
		MainMenu& operator=(const MainMenu& oterInstance);

	/**
	 * Metodos publicos de la clase MainMenu.
	 */
	public:
		/**
		 * Constructor de la clase MainMenu.
		 */
		MainMenu();
		/**
		 * Obtiene la senal de signal_activate del menu nuevo.
		 */
		Glib::SignalProxy0<void> newMenuItemSignalActivate();
		/**
		 * Obtiene la senal de signal_activate del menu abrir.
		 */
		Glib::SignalProxy0<void> openMenuItemSignalActivate();
		/**
		 * Obtiene la senal de signal_activate del menu guardar.
		 */
		Glib::SignalProxy0<void> saveMenuItemSignalActivate();
		/**
		 * Obtiene la senal de signal_activate del menu salir.
		 */
		Glib::SignalProxy0<void> quitMenuItemSignalActivate();
		/**
		 * Destructor virtual de la clase MainMenu.
		 */
		virtual ~MainMenu();
};

#endif /** __MAINMENU_H__ */
