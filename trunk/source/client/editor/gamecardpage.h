#ifndef __CARDGAMEPAGE_H__
#define __CARDGAMEPAGE_H__

#include<gtkmm/frame.h> // Para definicion de Gtk::Frame.

#include "viewgamecardsframe.h" // Para definicion de ViewGameCardsFrame.
#include "editor.h" // Para definicion de Editor.
#include "../../common/smartpointer/referencecountptr.h" // Para defincion de
// ReferenceCountPtr.

/**
 * Clase que representa una pagina dentro de un notebook widget mostrando los
 * frames para interactuar con las cartas de juego.
 */
class GameCardPage: public Gtk::Frame {
	/**
	 * Atributos privados de la clase CardGamePage.
	 */
	private:
		/**
		 * Almacena el layout vertical del CardGamePage.
		 */
		Gtk::VBox verticalBox;
		/**
		 * Almacena el frame para listar las cartas de juego.
		 */
		ViewGameCardsFrame viewGameCardsFrame;

	/**
	 * Metodos privados de la clase CardGamePage.
	 */
	private:
		/**
		 * Constructor copia de la clase GameCardPage.
		 */
		GameCardPage(const GameCardPage& otherInstance);
		/**
		 * Operador de asginacion de la clase GameCardPage.
		 */
		GameCardPage& operator=(const GameCardPage& otherInstance);

	/**
	 * Metodos publicos de la clase GameCardPage.
	 */
	public:
		/**
		 * Constructor de la clase GameCardPage.
		 */
		GameCardPage(const ReferenceCountPtr<Editor>& editor = NULL);
		/**
		 * Establece el editor del cual tomar los datos.
		 */
		void setEditor(const ReferenceCountPtr<Editor>& editor);
		/**
		 * Destructor virtual de la clase GameCardPage.
		 */
		virtual ~GameCardPage();
};

#endif /** __CARDGAMEPAGE_H__ */

