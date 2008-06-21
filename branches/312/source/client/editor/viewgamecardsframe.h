#ifndef __VIEWGAMECARDSFRAME_H__
#define __VIEWGAMECARDSFRAME_H__

#include<gtkmm/frame.h> // Para definicion de Gtk::Frame.
#include<gtkmm/box.h> // Para definicion de Gtk::VBox.
#include<gtkmm/liststore.h> // Para definicion de Gtk::ListStore.
#include<gtkmm/treeview.h> // Para definicion de Gtk::TreeView.

#include "gamecardcolumns.h" // Para definicion de GameCardColumns.

#include "editor.h" // Para definicion de Editor.
#include "observer.h" // Para definicion de Observer.
#include "subject.h" // Para definicion de Subject.
#include "../../common/smartpointer/referencecountptr.h" // Para definicion de
// ReferenceCountPtr.

/**
 * Clase cuyo proposito es mostrar una lista con todas las cartas de juego
 * agregadas al mapa.
 */
class ViewGameCardsFrame: public Observer, public Gtk::Frame {
	/**
	 * Atributos privados de la clase ViewGameCardsFrame.
	 */
	private:
		/**
		 * Almacena el editor del cual tomar los cambios.
		 */
		ReferenceCountPtr<Editor> editor;
		/**
		 * Almacena el layout vertical del ViewGameCardsFrame.
		 */
		Gtk::VBox verticalBox;
        /**
		 * Almacena el registro de columnas usado para la lista de cartas de
		 * juego.
		 */
        GameCardColumns gameCardColumns;
        /**
		 * Almacena el modelo de tree usado para la lista de cartas de juego.
		 */
        Glib::RefPtr<Gtk::ListStore> gameCardTreeModel;
        /**
		 * Almacena la vista de tree usado para la lista de cartas de juego.
		 */
        Gtk::TreeView gameCardTreeView;

	/**
	 * Metodos privados de la clase ViewGameCardsFrame.
	 */
	private:
		/**
		 * Constructor copia de la clase viewGameCardsFrame.
		 */
		ViewGameCardsFrame(const ViewGameCardsFrame& otherInstance);
		/**
		 * Operador de asignacion de la clase ViewGameCardsFrame.
		 */
		ViewGameCardsFrame& operator=(const ViewGameCardsFrame& otherInstance);
		/**
		 * Inicializa el modelo de tree de las cartas de juego.
		 */
		void initializeGameCardTreeModel();
		/**
		 * Inicializa el tree view de las cartas de juego.
		 */
		void initializeGameCardTreeView();
		/**
		 * Popula la lista de cartas de juego.
		 */
		void populate();

	/**
	 * Metodos publicos de la clase  ViewGameCardsFrame.
	 */
	public:
		/**
		 * Constructor de la clase ViewGameCardsFrame.
		 */
		ViewGameCardsFrame(const ReferenceCountPtr<Editor>& editor);
		/**
		 * Establece el editor del cual tomar los datos.
		 */
		void setEditor(const ReferenceCountPtr<Editor>& editor);
		/**
		 * Obtiene el editor del cual tomar los datos.
		 */
		ReferenceCountPtr<Editor>& getEditor();
		/**
		 * Se actualiza con los cambios del editor.
		 */
		void update(Subject* subject);
		/**
		 * Destructor virtual de la clase ViewGameCardsFrame.
		 */
		virtual ~ViewGameCardsFrame();
};

#endif /** __VIEWGAMECARDSFRAMEH__ */

