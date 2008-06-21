#ifndef __MAINWINDOoW_H__
#define __MAINWINDOW_H__

#include<gtkmm/main.h> // Para definicion de Gtk::Main.
#include<gtkmm/window.h> // Para definicion de Gtk::Window.
#include<gtkmm/notebook.h> // Para definicion de Gtk:Notebook.
#include<gtkmm/box.h> // Para definicion de Gtk::HBox y Gtk::VBox.
#include<gtkmm/filechooserdialog.h> // Para definicion de
// Gtk::FileChooserDialog.
#include<gtkmm/filefilter.h> // Para definicion de Gtk::FileFilter.
#include<gtkmm/stock.h> // Para definicion de Gtk::Stock.
#include "continentpage.h" // Para definicion de ContinentPage.
#include "countrypage.h" // Para definicion de CountryPage.
#include "gamecardpage.h" // Para definicion de GameCardPage.
#include "mapdrawingareaframe.h" // Para definicino de MapDrawingAreaFrame.
#include "mainmenu.h" // Para definicion de MainMenu.
#include "editor.h" // Para definicionde Editor.
#include "../../common/parser/mapaparser.h" // Para definicion de MapaParseer.
#include "../../common/smartpointer/referencecountptr.h" // Para definicino de
// ReferenceCountPtr.

/**
 * Clase que encapsula la venthana principal del editor de mapas.
 */
class MainWindow: public Gtk::Window {
	/**
	 * Atributos privados de la clase MainWindow.
	 */
	private:
		/**
		 * Almacena el menu del editor.
		 */
		ReferenceCountPtr<Editor> editor;
		/**
		 * Almacena el layout vertical.
		 */
		Gtk::VBox verticalBox;
		/**
		 * Almacena el layout horizontal.
		 */
		Gtk::HBox horizontalBox;
		/**
		 * Almacena el menu principal.
		 */
		MainMenu mainMenu;
		/**
		 * Almacena el notebook tab.
		 */
		Gtk::Notebook notebookTab;
		/**
		 * Almacena la pagina de continentes del notebook tab.
		 */
		ContinentPage continentPage;
		/**
		 * Almacena la pagina de paises del notebook tab.
		 */
		CountryPage countryPage;
		/**
		 * Almacena la pagina de cartas de juego del notebook tab.
		 */
		GameCardPage gameCardPage;
		/**
		 * Almacena el area de dibujo de la imagen del mapa.
		 */
		MapDrawingAreaFrame mapDrawingAreaFrame;

	/**
	 * Metodos privados de la clase MainWindow.
	 */
	private:
		/**
		 * Constructor copia de la clase MainWindow,
		 */
		MainWindow(const MainWindow& otherInstance);
		/**
		 * Operador de asignacion de la clase MainWindow.
		 */
		MainWindow& operator=(const MainWindow& otherInstance);
		/**
		 * Manejador de la senal signal_activate del menu nuevo.
		 */
		void onNewMenuItemActivated();
		/**
		 * Manejador de la senal signal_activate del menu abrir.
		 */
		void onOpenMenuItemActivated();
		/**
		 * Manejador de la senal signal_activate del menu guardar,
		 */
		void onSaveMenuItemActivated();
		/**
		 * Manejador de la senal signal_activate del menu salir.
		 */
		void onQuitMenuItemActivated();
		/**
		 * Establece el editor a usar.
		 */
		void setEditor(const ReferenceCountPtr<Editor>& editor);
	/**
	 * Metodos publicos de la clase MainWindow.
	 */
	public:
		/**
		 * Conmstructor de la clase MainWindow.
		 */
		MainWindow();
		/**
		 * Destructor virtual de la clase MainWindow.
		 */
		virtual ~MainWindow();
};

#endif /** __MAINWINDOW_H__ */

