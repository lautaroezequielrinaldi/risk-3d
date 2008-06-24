#ifndef __GLWIDGET_H__
#define __GLWIDGET_H__

#include<GL/gl.h> // Para funciones de OpenGL
#include<GL/glu.h>// Para funciones de OpenGLU
#include<SDL/SDL.h> // Para funciones de SDL
#include "rectangle.h" // Para definicion de Rectangle

/**
 * Clase abstracta base para todos los widgets GL SDL del cliente 3D.
 */
class GLWidget {
	/**
	 * Atributos privados de la clase GLWidget.
	 */
	protected:
		/**
		 * Almacena el rectangulo en pantalla que representa el widget.
		 */
		Rectangle bounds;
		/**
		 * Almacena el estado visible del widget.
		 */
		bool visible;
		/**
		 * Almacena el estado habilitado del widget.
		 */
		bool enabled;
	/**
	 * Metodos protegidos de la clse GLWidget.
	 */
	protected:
		/**
		 * Se invoca antes de dibujar el componente.
		 */
		virtual void preDrawWidget();
		/**
		 * Se invoca al dibujar el componente.
		 */
		virtual void drawWidget() = 0;
		/**
		 * Se invoca despues de dibujar el componente.
		 */
		virtual void postDrawWidget();
		/**
		 * Vuelve idle al componente.
		 */
		virtual void becomeIdle();
		/**
		 * Dibuja un quadrangle.
		 */
		void drawQuadrangle(int polygonType, int left, int right, int bottom,
			int top);
		/**
		 * Verifica si un punto determinado forma parte del widget.
		 */
		bool contains(const int& x, const int& y);
	/**
	 * Metodos publicos de la clase GLWidget.
	 */
	public:
		/**
		 * Constructor de la clase GLWidget.
		 */
		GLWidget(const int& x = 0, const int& y = 0, const int& width = 0,
			const int& height = 0, const bool& visible = true,
			const bool& enabled = true);
		/**
		 * Obtiene los limites del componente.
		 */
		Rectangle getBounds();
		/**
		 * Establece los limites del componente.
		 */
		void setBounds(const Rectangle& rectangle);
		/**
		 * Dibuja el componente.
		 */
		void draw();
		/**
		 * Procesa un evento de boton de mouse en caso de que sea para el.
		 */
		virtual void processMouseButton(const SDL_MouseButtonEvent& event) = 0;
		/**
		 * Procesa un evento de movimiento de mouse en caso de que sea para el.
		 */
		virtual void  processMouseMotion(
			const SDL_MouseMotionEvent& event) = 0;
		/**
		 * Procesa un evento de teclado en caso de que sea para el.
		 */
		virtual void processKeyboard(const SDL_KeyboardEvent& event) = 0;
		/**
		 * Destructor virtual de la clase GLWidget.
		 */
		virtual ~GLWidget();
};

#endif /** __GLWIDGET_H__ */

