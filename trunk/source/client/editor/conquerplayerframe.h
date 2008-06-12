#ifndef __CONQUERPLAYERFRAME_H__
#define __CONQUERPLAYERFRAME_H__

#include<gtkmm/label.h> // Para definicion de Gtk::Label.
#include<gtkmm/liststore.h> // Para definicion de Gtk::ListStore.
#include<gtkmm/combobox.h> // Para definicion de Gtk::ComboBox.

#include "gamecardframe.h" // Para definicion de GameCardFrame.
#include "colorcolumns.h" // Para definicion de ColorColumns.
#include "editor.h" // Para definicion de Editor.
#include "../../common/model/conquerplayergamecard.h" // Para definicion de
// ConquerPlayerGameCard.
#include "../../common/smartpointer/referencecountptr.h" // Para definicion de
// RefeerenceCountPtr.

/**
 * Clase cuyo proposito es mostrar un frame donde el usuario puede agregar
 * cartas de juego para conquistar jugador.
 */
class ConquerPlayerFrame: public GameCardFrame {
	/**
	 * Atributos de la clase ConquerPlayerFrame.
	 */ 
	private:
		/**
		 * Almacena el registro de columnas para el color del jugador.
		 */
		ColorColumns colorColumns;
		/**
		 * Almacena el label para el color del jugador.
		 */
		Gtk::Label colorLabel;
		/**
		 * Almacena el modelo de tree para el color del jugador.
		 */
		Glib::RefPtr<Gtk::ListStore> colorTreeModel;
		/**
		 * Almacena el combo box para el color del jugador.
		 */
		Gtk::ComboBox colorComboBox;

	/**
	 * Metodos privados de la clase ConquerPlayerFrame.h
	 */
	private:
		/**
		 * Constructor copia de la clase ConquerPlayerFrame.
		 */
		ConquerPlayerFrame(const ConquerPlayerFrame& otherInstance);
		/**
		 * Operador de asignacion de la clase ConquerPlayerFrame.
		 */
		ConquerPlayerFrame& operator=(const ConquerPlayerFrame& otherInstance);
		/**
		 * Inicializa el modelo de tree para la lista de colores.
		 */
		void initializeColorTreeModel();
		/**
		 * Inicializa el combo box para la lista de colores.
		 */
		void initializeColorComboBox();
	
	/**
	 * Metodos protegidos de la clase ConquerPlayerFrame.
	 */
	protected:
        /**
         * Manejador de la senial signal_clicked del boton addGameCardButton.
         */
        virtual void onAddGameCardButtonClicked();
 
	/**
	 * Metodos publicos de la clase ConquerPlayerFrame.
	 */
	public:
		/**
		 * Constructor de la clase ConquerPlayerFrame.
		 */
		ConquerPlayerFrame(const ReferenceCountPtr<Editor>& editor = NULL);
		/**
		 * Destructor virtual de la clase ConquerPlayerFrame.
		 */
		virtual ~ConquerPlayerFrame();
};
		
#endif /** __CONQUERPLAYERFRAME_H__ */

