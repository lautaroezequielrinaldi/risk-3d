#ifndef __GAMECARDFRAME_H__
#define __GAMECARDFRAME_H__

#include<gtkmm/frame.h> // Para definicion de Gtk::Frame.
#include<gtkmm/box.h> // Para definicion de Gtk::VBox.
#include<gtkmm/label.h> // Para definicion de Gtk::Label.
#include<gtkmm/entry.h> // Para definicion de Gtk::Entry.
#include<gtkmm/liststore.h> // Para definicion de Gtk::ListStore.
#include<gtkmm/combobox.h> // Para definicion de Gtk::ComboBox.
#include<gtkmm/button.h> // Para defincion de Gtk::Button.

#include "editor.h" // Para definicion de Editor.
#include "../../common/smartpointer/referencecountptr.h" // Para definicion de
// ReferenceCountPtr.

/**
 * Clase abstracta que define funcionalidad basica a todos los frames para
 * agregar cartas de juego al mapa.
 */
class GameCardFrame: public Gtk::Frame {
	/**
	 * Atributos protegidos de la clase GameCardFrame.
	 */
	protected:
		/**
		 * Almacena el editor del cual va a tomar los datos.
		 */
		ReferenceCountPtr<Editor> editor;
		/**
		 * Almacena el vertical layout del frame.
		 */
		Gtk::VBox verticalBox;
		/**
		 * Almacena el label para el nombre de la carta de juego.
		 */
		Gtk::Label gameCardNameLabel;
		/**
		 * Almacena el entry para el nombre de la carta de juego.
		 */
		Gtk::Entry gameCardNameEntry;
		/**
		 * Almacena el boton para agregar carta de juego.
		 */
		Gtk::Button addGameCardButton;

	/**
	 * Metodos protegidos de la clase GameCardFrame.
	 */
	protected:
		/**
		 * Manejador de la senal signal_clicked del boton addGameCardButton.
		 */
		virtual void onAddGameCardButtonClicked() = 0;
	/**
	 * Metodos publicos de la clase GameCardFrame.
	 */
	public:
		/**
		 * Constructor de la clase GameCardFrame.
		 */
		GameCardFrame(const ReferenceCountPtr<Editor>& editor);
		/**
		 * Establece el editor de donde tomar los datos.
		 */
		void setEditor(const ReferenceCountPtr<Editor>& editor);
		/**
		 * Obtiene el editor de donde tomar los datos.
		 */
		ReferenceCountPtr<Editor>& getEditor();
		/**
		 * Destructor virtual de la clase GameCardFrame.
		 */
		~GameCardFrame();
};

#endif /** __GAMECARDFRAME_H__ */

