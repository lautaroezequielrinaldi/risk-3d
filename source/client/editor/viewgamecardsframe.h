#ifndef __VIEWGAMECARDSFRAME_H__
#define __VIEWGAMECARDSFRAME_H__

#include<gtkmm/frame.h> // Para definicion de Gtk::Frame.

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

