#ifndef __GAMECARDPAGE_H__
#define __GAMECARDPAGE_H__

#include<gtkmm/frame.h> // Para definicion de Gtk::Frame.

#include "conquercontinentframe.h" // Para definicion de ConquerContinentFrame.
#include "conquerplayerframe.h" // Para defincion de ConquerPlayerFrame.
#include "conquercountriesframe.h" // Para definicion de ConquerCuntriesFrame.
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
		 * Almacena el frame para agregar cartas de juego para conquistar
		 * continentes.
		 */
		ConquerContinentFrame conquerContinentFrame;
		/**
		 * Almacena el frame para agregar cartas de juego para conquistar
		 * jugadres.
		 */
		ConquerPlayerFrame conquerPlayerFrame;
		/**
		 * Almacena el frame para agregar cartas de juego para conquistar N
		 * paises.
		 */
		ConquerCountriesFrame conquerCountriesFrame;	
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

#endif /** __GAMECARDPAGE_H__ */

