#ifndef __CONQUERCONTINENTFRAME_H__
#define __CONQUERCONTINENTFRAME_H__

#include<gtkmm/frame.h> // Para definicion de Gtk::Frame.
#include<gtkmm/box.h> // Para definicion de Gtk::VBox.
#include<gtkmm/label.h> // Para definicion de Gtk::Label.
#include<gtkmm/entry.h> // Para definicion de Gtk::Entry.
#include<gtkmm/liststore.h> // Para definicion de Gtk::ListStore.
#include<gtkmm/combobox.h> // Para definicion de Gtk::ComboBox.
#include<gtkmm/button.h> // Para defincion de Gtk::Button.

#include "observer.h" // Para definicion de Observer.
#include "subject.h" // Para definicion de Subject.
#include "continentcolumns.h" // Para definicion de ContinentColumns.
#include "editor.h" // Para definicion de Editor.
#include "../../common/model/conquercontinentgamecard.h" // Para definicion de
// ConquerContinentGameCard.
#include "../../common/smartpointer/referencecountptr.h" // Para definicion de
// ReferenceCountPtr.

/**
 * Clase que representa un frame para agregar cartas de juego
 * ConquerContinentGameCard al mapa.
 */
class ConquerContinentFrame: public Observer, public Gtk::Frame {
	/**
	 * Atributos privados de la clase ConquerContinentFrame.
	 */
	private:
		/**
		 * El editor del cual tomar los datos a mostrar.
		 */
		ReferenceCountPtr<Editor> editor;
		/**
		 * El layout vertical del ConquerContinentFrame.
		 */
		Gtk::VBox verticalBox;
		/**
		 * Almacena el label para el ingreso de nombre de carta.
		 */
		Gtk::Label gameCardNameLabel;
		/**
		 * Almacena el entry para el ingreso de nombre de carta.
		 */
		Gtk::Entry gameCardNameEntry;
		/**
		 * Almacena el label para seleccionar continente.
		 */
		Gtk::Label continentLabel;
		/**
		 * Almacena el registro de columnas para la lista de continentes.
		 */
		ContinentColumns continentColumns;
		/**
		 * Almacena el modelo de tree para la lista de continentes.
		 */
        Glib::RefPtr<Gtk::ListStore> continentTreeModel;
		/**
		 * Almacena el combo box para la lista de continentes.
		 */
		Gtk::ComboBox continentComboBox;
		/**
		 * Almacena el boton para agregar la carta de juego.
		 */
		Gtk::Button addGameCardButton;

	/**
	 * Metodos privados de la clase ConquerContinentFrame.
	 */
	private:
		/**
		 * Constructor copia de la clase ConquerContinentFrame.
		 */
		ConquerContinentFrame(const ConquerContinentFrame& otherInstance);
		/**
		 * Operador de asignacion de la clase ConquerContinentFrame.
		 */
		ConquerContinentFrame& operator=(
			const ConquerContinentFrame& otherInstance);
		/**
		 * Inicializa el modelo de tree para la lista de continentes.
		 */
		void initializeContinentTreeModel();
		/**
		 * Inicializa el combo box para la lista de continentes.
		 */
		void initializeContinentComboBox();
		/**
		 * Popula la lista de continentes.
		 */
		void populate();
		/**
		 * Manejador de la senial signal_clicked del boton addGameCardButton.
		 */
		void onAddGameCardButtonClicked();

	/**
	 * Metodos publicos de la clase ConquerContinentFrame.
	 */
	public:
		/**
		 * Constructor de la clase ConquerContinentFrame.
		 */
		ConquerContinentFrame(const ReferenceCountPtr<Editor>& editor = NULL);
		/**
		 * Establece el editor del cual tomar los datos./
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
		 * Destructor virtual de la clase ConquerContinentFrame.
		 */
		~ConquerContinentFrame();
};

#endif /** __CONQUERCONTINENTFRAME_H__ */

