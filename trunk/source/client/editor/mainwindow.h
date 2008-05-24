#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include<gtkmm/main.h> // Para definiciòn de Gtk::Main.
#include<gtkmm/window.h> // Para definiciòn de Gtk::Window.
#include<gtkmm/box.h> // Para definicion de Gtk::VBox.
#include<gtkmm/filechooserdialog.h> // Para definiciòn de Gtk::FileChooserDialog.
#include<gtkmm/stock.h> // Para definiciòn de Gtk::Stock::CANCEL y Gtk::Stock::OK.
#include "mainmenubar.h" // Para definiciòn de MainMenuBar.
#include "mapview.h" // Para definiciòn de MapView.

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
        MainMenuBar menuBar;

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
         * Mètodo cuyo propòsito es crear el layout vertial de la ventana
         * principal.
         */
        void createVerticalLayout();
        /**
         * Mètodo cuyo propòsito es crear la barra de menu de la ventana
         * principal.
         */
        void createMenuBar();
        /**
         * Manejador de la señal signal_activate del item de menu nuevo mapa.
         */
        void onNewMapSelected();
        /**
         * Manejador de la señal signal_activate del item de menu salir.
         */
        void onLoadMapSelected();
        /**
         * Manejador de la señal signal_activate del item de menu salir.
        */
        void onSaveMapSelected();
        /**
         * Manejador de la señal signal_activate del item de menu salir.
         */
        void onQuitSelected();
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

