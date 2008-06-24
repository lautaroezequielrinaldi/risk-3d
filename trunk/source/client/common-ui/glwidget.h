#ifndef __GLWIDGET_H__
#define __GLWIDGET_H__

#include <SDL.h> // Para definicion de SDL.
#include <list> // Para definicion de std:list.
#include "mousebuttonlistener.h" // Para definicion de MouseButtonListener.

/**
 * Clase abstracta base para todos los widgets GL SDL del cliente 3D.
 */
class GLWidget {
	/**
	 * Atributos privados de la clase GLWidget.
	 */
	private:
		/**
 		 * Almacena la lista de listeners para eventos de Mouse Button SDL.
 		 */
		std::list<MouseButtonListener*> mouseButtonListenerList;
		/**
		 * Almacena la posicion X inicial del widget.
		 */
		int x;
		/**
		 * Almacena la posicion Y inicial del widget.
		 */
		int y;
		/**
		 * Almacena el ancho del widget.
		 */
		int width;
		/**
		 * Almacena el alto del widget.
		 */
		int height;
		/**
		 * Almacena si el widget es visible.
		 */
		bool visible;
		/**
		 * Almacena si el widget esta habilitado.
		 */
		bool enabled;

	/**
	 * Metodos privados de la clase GLWidget.
	 */
	private:
		/**
		 * Constructor copia de la clase GLWidget.
		 */
		GLWidget(const GLWidget& otherInstance);
		/**
		 * Operador de asignacion de la clase GLWidget.
		 */
		GLWidget& operator=(const GLWidget& otherInstance);
		/**
		 * Dispara una notificacion de eventos Mouse Button SDL.
		 */
		void fireMouseButtonNotification(const SDL_MouseButtonEvent& event);

	/**
	 * Metodos protegidos de la clase GLWidget.
	 */
	protected:
		/**
		 * Verifica si una posicion X,Y en pantalla pertenece dentro del widget.
		 */
		virtual bool containsPoint(const int& x, const int& y);

	/**
	 * Metodos publicos de la clase GLWidget.
	 */
	public:
		/**
		 * Constructor de la clase GLWidget.
		 */
		GLWidget(const int& x, const int& y, const int& width,
			const int& height, const bool& visible = true,
			const bool& enabled = true);
		/**
		 * Establece la posicion X del widget.
		 */
		void setX(const int& x);
		/**
		 * Obtiene la posicion X del widget.
		 */
		int getX() const ;
		/**
		 * Establece la posicion Y del widget.
		 */
		void setY(const int& y);
		/**
		 * Obtiene la posicion Y del widget.
		 */
		int getY() const;
		/**
		 * Establece el ancho del widget.
		 */
		void setWidth(const int& width);
		/**
		 * Obtiene el ancho del widget.
		 */
		int getWidth() const;
		/**
		 * Establece el alto del widget.
		 */
		void setHeight(const int& height);
		/**
		 * Obtiene el alto del widget.
		 */
		int getHeight() const;
		/**
		 * Establece el estado visible del widget.
		 */
		void setVisible(const bool& visible);
		/**
		 * Obtiene el estado visible del widget.
		 */
		bool getVisible() const;
		/**
		 * Establece el estado habilitado del widget.
		 */
		void setEnabled(const bool& enabled);
		/**
		 * Obtiene el estado habilitado del widget.
		 */
		bool getEnabled() const;
		/**
		 * Registra un listener de evento Mouse Button SDL.
		 */
		void registerMouseButtonListener(MouseButtonListener* listener);
		/**
		 * Des Registra un listener de evento Mouse Button SDL.
		 */
		void unregisterMouseButtonListener(
			MouseButtonListener* listener);
		/**
		 * Dibuja el widget en pantalla.
		 */
		virtual void draw() = 0;
		/**
		 * Procesa un evento de Mouse Button SDL y notifica a los listeners de
		 * dicho widget si se ha hecho click.
		 */
		virtual void processMouseButtonEvent(const SDL_MouseButtonEvent& event);
		/**
		 * Destructor virtual de la clase GLWidget.
		 */
		virtual ~GLWidget();
};

#endif /** __GLWIDGET_H__ */

