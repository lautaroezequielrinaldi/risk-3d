#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include<gtkmm/main.h> // Para definiciòn de Gtk::Main.
#include<gtkmm/window.h> // Para definiciòn de Gtk::Window.
#include<gtkmm/box.h> // Para definicion de VBox.
#include<gtkmm/menubar.h> // Para definicion de Gtk::MenuBar.
#include<gtkmm/menu.h> // Para definiciòn de Gtk::Menu.
#include<gtkmm/menuitem.h> // Para definiciòn de Gtk::MenuItem.

/**
 * Definiciòn de la clase MainWindow que encapsula la ventana principal de la
 * aplicaciòn.
 */
class MainWindow : public Gtk::Window {
	/**
 	 * Atributos privados de la clase MainWindow.
 	 */
	private:
        /**
         * Almacena el layout vertical.
         */
        Gtk::VBox verticalLayout;
		/**
         * Almacena la barra de menues.
         */
        Gtk::MenuBar barraMenu;
        /**
         * Almacena el item de menu archivo.
         */
        Gtk::MenuItem archivoMenuItem;
        /**
         * Almacena el menu archivo.
         */
        Gtk::Menu archivoMenu;
        /**
         * Almacena el item de menu nuevo mapa.
         */
        Gtk::MenuItem nuevoMapaMenuItem;
        /**
         * Almacena el item de menu abrir mapa.
         */
        Gtk::MenuItem abrirMapaMenuItem;
        /**
         * Almacena el item de menu guardar mapa.
         */
        Gtk::MenuItem guardarMapaMenuItem;
        /**
         * Almacena el item de menu salir.
         */
        Gtk::MenuItem salirMenuItem;

	/**
 	 * Mètodos privados de la clase MainWindow.
 	 */
	private:
		/**
 		 * Constructor copia de la clase MainWindow.
 		 */
		MainWindow(const MainWindow& otherInstance);
		/**
 		 * Operador de asignaciòn de la clase MainWindow.
 		 */
		MainWindow& operator=(const MainWindow& otherInstance);
        /**
         * Mètodo cuyo propòsito es crear la barra de menues.
         */
        void createMenuBar();
        /**
         * Manejador del evento on_select del item de menu nuevo mapa.
         */
        void onNuevoMapaSelected();
        /**
         * Manejador del evento on_select del item de menu cargar mapa.
         */
        void onCargarMapaSelected();
        /**
         * Manejador del evento on_select del item de menu guardar mapa.
         */
        void onGuardarMapaSelected();
        /**
         * Manejador del evento on_select del item de menu salir.
         */
        void onSalirSelected();

	/**
 	 * Mètodos pùblicos de la clase MainWindow.
 	 */
	public:
		/**
 		 * Constructor de la clase MainWindow.
 		 */
		MainWindow();
		/**
 		 * Destructor virtual de la clase MainWindow.
 		 */
		virtual ~MainWindow();
};

#endif /** __MAINWINDOW_H__ */

