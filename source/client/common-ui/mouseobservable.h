#ifndef __MOUSEOVSERVABLE_H__
#define __MOUSEOBSERVABLE_H__

#include<list> // Para definicion de std::list.
#include<SDL.h> // Para definicion de funciones SDL.

/**
 * Forward declaration de la clase MouseObserver.
 */
class MouseObserver;

/**
 * Clase abstracta que permite registrar observers para eventos de mouse.
 */
class MouseObservable {
	/**
	 * Atributos privados de la clase MouseObservable.
	 */
	private:
		/**
		 * Almacena la lista de observers para eventos de mouse.
		 */
		std::list<MouseObserver*> observerList;

	/**
	 * Metodos protegidos de la clase MouseObservable.
	 */
	protected:
		/**
		 * Constructor de la clase MouseObservable.
		 */
		MouseObservable();
		/**
		 * Notifica a todos los observes de un evento de mouse.
		 */
		void notifyMouseButtonDownEvent(const SDL_MouseButtonEvent& evnet);
		/**
		 * Notifica a todos los observers de un evento de mouse.
		 */
		void notifyMouseButtonUpEvent(const SDL_MouseButtonEvent& event);
		/**
		 * Notifica a todos los observers de un evento de mouse.
		 */
		void notifyMouseMotionEvent(const SDL_MouseMotionEvent& event);

	/**
	 * Metodos publicos de la clase MouseObservable.
	 */
	public:
		/**
		 * Registra un observador de evento de mouse.
		 */
		void addMouseObserver(MouseObserver* observer);
		/**
		 * Desregistra un observador de evento de mouse.
		 */
		void removeMouseObserver(MouseObserver* observer);
		/**
		 * Destructor virtual de la clase MouseObservable.
		 */
		virtual ~MouseObservable();
};

#endif /** __MOUSEOBSERVABLE_H__ */

