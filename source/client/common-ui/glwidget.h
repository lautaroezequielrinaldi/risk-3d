#ifndef __GLWIDGET_H__
#define __GLWDIGET_H__

#include<map> // Para definicion de std::map
#include<GL/gl.h> // Para funciones de OpenGL
#include<GL/glu.h>// Para funciones de OpenGLU
#include<SDL/SDL.h> // Para funciones de SDL
#include "dimension.h" // Para definicion de Dimension.
#include "color.h" // Para definicion de Color.

/**
 * Forward declaration de la clase GLMainLoop.
 */
class GLMainLoop;

/**
 * Constante que define el tipo de estado del widget.
 */
typedef enum GLWidgetStateType {
	GLWIDGET_ACTIVE,
	GLWIDGET_INACTIVE,
	GLWIDGET_FOCUS
} GLWidgetStateType;

class GLWidget {
	// Defino la clase GLMainLoop como friend.
	friend class GLMainLoop;

	/**
	 * Atributos privados de la clase GLWidget.
	 */
	private:
		/**
		 * Almacena el contador de IDs de widget.
		 */
		static long idCounter;
		/**
		 * Almacena el ID del widget.
		 */
		long id;
		/**
		 * Almacena la dimension del widget.
		 */
		Dimension dimension;
		/**
		 * Almacena el estado visible del widget.
		 */
		bool visible;
		/**
		 * Almacena el estado habilitado del widget.
		 */
		bool enabled;
		/**
		 * Almacena el tipo de estado del widget.
		 */
		GLWidgetStateType state;
		/**
		 * Almacena el mapa de colores background para el widget.
		 */
		std::map<GLWidgetStateType, Color> backgroundColorMap;
		/**
		 * Almacena el mapa de colores foreground para el widget.
		 */
		std::map<GLWidgetStateType, Color> foregroundColorMap;

	/**
	 * Metodos privados de la clase GLWidget.
	 */
	private:
		/**
		 * Incrementa el contador de IDs de widget.
		 */
		static void incrementIdCounter();
		/**
		 * Obtiene el contador de IDs de widget.
		 */
		static long getIdCounter();
		/**
		 * Constructor copia de la clase GLWidget.
		 */
		GLWidget(const GLWidget& otherInstance);
		/**
		 * Operador de asignacion de la clase GLWidget.
		 */
		GLWidget& operator=(const GLWidget& otherInstance);

	/**
	 * Metodos protegidos de la clase GLWidget.
	 */
	protected:
		/**
		 * Obtiene el id del widget.
		 */
		long getId();
		/**
		 * Establece el id del widget.
		 */
		void setId(const long& id);
		/**
		 * Obtiene el estado del widget.
		 */
		GLWidgetStateType getState();
		/**
		 * Establece el estado del widget.
		 */
		void setState(const GLWidgetStateType& type);
		/**
		 * Predibuja el widget en el viewport.
		 */
		virtual void preDrawWidget() = 0;
		/**
		 * Dibuja el widget en el viewport.
		 */
		virtual void drawWidget() = 0;
		/**
		 * Postdibuja el widget en el viewport.
		 */
		virtual void postDrawWidget() = 0;
		/**
		 * Manejador del evento mouse presionado.
		 */
		virtual void handleMouseButtonDownEvent(
			const SDL_MouseButtonEvent& event);
		/**
		 *  Manejador del evento mouse liberado.
		 */
		virtual void handleMouseButtonUpEvent(
			const SDL_MouseButtonEvent& event);
		/**
		 * Manejador del evento movimiento de mouse.
		 */
		virtual void handleMouseMotionEvent(const SDL_MouseMotionEvent& event);
		/**
		 * Manejador del evento tecla presionada.
		 */
		virtual void handleKeyDownEvent(const SDL_KeyboardEvent& event);
		/**
		 * Manejador del evento tecla liberada.
		 */
		virtual void handleKeyUpEvent(const SDL_KeyboardEvent& event);

	/**
	 * Metodos publicos de la clase GLWidget.
	 */
	public:
		/**
		 * Constructor de la clase GLWidget.
		 */
        GLWidget();
		/**
		 * Obtiene la dimension del widget.
		 */
		Dimension& getDimension();
		/**
		 * Establece la dimension del widget.
		 */
		void setDimension(const Dimension& dimension);
		/**
		 * Establece la coordenada x del widget.
		 */
		void setX(const int& x);
		/**
		 * Establece la coordenada Y del widget.
		 */
		void setY(const int& y);
		/**
		 * Establece el ancho del widget.
		 */
		void setWidth(const int& width);
		/**
		 * Establece el alto del widget.
		 */
		void setHeight(const int& height);
		/**
		 * Obtiene en valor visible del widget.
		 */
		bool getVisible();
		/**
		 * Establece el valor visible del widget.
		 */
		void setVisible(const bool& visible);
		/**
		 * Obtiene el valor habilitado del widget.
		 */
		bool getEnabled();
		/**
		 * Establece el valor habilitado del widget.
		 */
		void setEnabled(const bool& enabled);
		/**
		 * Obtiene el color de background para un estado determinado.
		 */
		Color getBackgroundColor(const GLWidgetStateType& type);
		/**
		 * Establece el color de background para un estado determinado.
		 */
		void setBackgroundColor(const GLWidgetStateType& type, const Color& color);
        /**
		 * Obtiene el color de foreground para un estado determinado.
		 */
        Color getForegroundColor(const GLWidgetStateType& type);
        /**
		 * Establece el color de foreground para un estado determinado.
		 */
        void setForegroundColor(const GLWidgetStateType& type, const Color& color);
		/**
		 * Dibuja el widget.
		 */
		void draw();
		/**
		 * Destructor virtual de la clase GLWidget.
		 */
		virtual ~GLWidget(); 
};

#endif /** __GLWIDGET_H__ */

