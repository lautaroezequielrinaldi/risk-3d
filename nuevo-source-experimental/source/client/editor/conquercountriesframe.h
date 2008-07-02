#ifndef __CONQUERCOUNTRIESFRAME_H__
#define __CONQUERCOUNTRIESFRAME_H__

#include<gtkmm/label.h> // Para definicion de Gtk::Label.
#include<gtkmm/spinbutton.h> // Para definicion de Gtk::SpinButton.

#include "gamecardframe.h" // Para definicion de GameCardFrame.
#include "observer.h" // Para definicion de Observer.
#include "subject.h" // Para definicion de Subject.
#include "editor.h" // Para definicion de Editor.
#include "../../common/model/conquercountriesgamecard.h" // Para definicion de
// ConquerCountriesGameCard.
#include "../../common/smartpointer/referencecountptr.h" // Para definicion de
// RefeerenceCountPtr.

/**
 * Clase cuyo proposito es mostrar un frame para agregar cartas de juego
 * conquiar N paises.
 */
class ConquerCountriesFrame: public Observer, public GameCardFrame {
	/**
	 * Atributos privados de la clase ConquerCountriesFrame.
	 */
	private:
		/**
		 * Almacena el label para la cantidad de paises.
		 */
		Gtk::Label countryCountLabel;
		/**
		 * Almacena el spin button para la cantidad de paises.
		 */
		Gtk::SpinButton countryCountSpinButton;

	/**
	 * Metodos privados de la clase ConquerCountriesFrame.
	 */
	private:
		/**
		 * Constructor copia de la clase ConqierCountriesFrame.
		 */
		ConquerCountriesFrame(const ConquerCountriesFrame& otherInstance);
		/**
		 * Operador de asignacion de la clase ConquerCountriesFrame.
		 */
		ConquerCountriesFrame& operator=(
			const ConquerCountriesFrame& otherInstance);
		/**
		 * Popula el rango de cantidad de paises a elegir.
		 */
		void populate();

	/**
	 * Metodos protegidos de la clase ConquerCountriesFrame.
	 */
	protected:
		/**
		 * Manejador de la senal signal_clicked del boton addGameCardButton.
		 */
		void onAddGameCardButtonClicked();

	/**
	 * Metodos publicos de la clase ConquerCountriesFrame.
	 */
	public:
		/**
		 * Constructor de la clase ConquerCountriesFrame.
		 */
		ConquerCountriesFrame(const ReferenceCountPtr<Editor>& editor = NULL);
		/**
		 * Establece el editor del cual tomar los datos.
		 */
		void setEditor(const ReferenceCountPtr<Editor>& editor);
		/**
		 * Se actualiza con los cambios del editor.
		 */
		void update(Subject* subject);
		/**
		 * Destructor virtual de la clase ConquercountriesFrame.
		 */
		virtual ~ConquerCountriesFrame();
};

#endif /** __CONQUERCOUNTRIESFRAME_H__ */

