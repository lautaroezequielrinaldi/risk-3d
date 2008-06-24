#ifndef __GLWIDGET_H__
#define __GLWIDGET_H__

#include<GL/gl.h> // Para funciones de OpenGL
#include<GL/glu.h>// Para funciones de OpenGLU
#include<SDL/SDL.h> // Para funciones de SDL
#include "rectangle.h" // Para definicion de Rectangle
#include "color.h" // Para definicion de Color
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
		 * Almacena el color de sombra del widget.
		 */
		Color shadowColor;
		/**
		 * Almacena el color de fondo del widget.
		 */
		Color backgroundColor;
		/**
		 * Almacena el color de frente del widget.
		 */
		Color foregroundColor;
		/**
		 * Almacena el color de hoover del widget.
		 */
		Color hooverColor;
		/**
		 * Almacena el estado visible del widget.
		 */
		bool visible;
		/**
		 * Almacena el estado habilitado del widget.
		 */
		bool enabled;
		/**
		 * Almacena el estado hoover del widget.
		 */
		bool hoover;

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
		void drawQuadrangle(GLenum polygonType, GLint left, GLint right,
			GLint bottom, GLint top, Color color);
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
			const bool& enabled = true, const bool& hoover = false);
		/**
		 * Obtiene los limites del componente.
		 */
		Rectangle getBounds();
		/**
		 * Establece los limites del componente.
		 */
		void setBounds(const Rectangle& rectangle);
		/**
		 * Obtiene el color de sombra del componente.
		 */
		Color getShadowColor();
		/**
		 * Establece el color de sombra del componente.
		 */
		void setShadowColor(const Color& shadowColor);
        /**
         * Obtiene el color de fondo del componente.
         */
        Color getBackgroundColor();
        /**
		 * Establece el color de fondo del componente.
		 */
        void setBackgroundColor(const Color& backgroundColor);
        /**
		 * Obtiene el color de frente del componente.
		 */
        Color getForegroundColor();
        /**
		 * Establece el color de fondo del componente.
		 */
        void setForegroundColor(const Color& foregroundColor);
        /**
		 * Obtiene el color de hoover del componente.
		 */
        Color getHooverColor();
        /**
		 * Establece el color de hoover del componente.
		 */
        void setHooverColor(const Color& hooverColor);
		/**
		 * Obtiene el estado visible del componente.
		 */
		bool getVisible();
		/**
		 * Establece el estado visible del componente.
		 */
		void setVisible(const bool& visible);
		/**
		 * Obtiene el estado habilitado del componente.
		 */
		bool getEnabled();
		/**
		 * Establece el estado habilitado del componente.
		 */
		void setEnabled(const bool& enabled);
        /**
		 * Obtiene el estado hoover del componente.
		 */
        bool getHoover();
        /**
		 * Establece el estado hoover del componente.
		 */
        void setHoover(const bool& hoover);
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

