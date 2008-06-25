#ifndef __GLDRAWHELPER_H__
#define __GLDRAWHELPER_H__

#include<string>
#include<GL/gl.h> // Para funciones de OpenGL
#include<GL/glu.h>// Para funciones de OpenGLU
#include<GL/glut.h> // Para funciones de FreeGlut.
#include "color.h" // Para definicion de Color.
#include "dimension.h" // Para definicion de Dimension.

class GLDrawHelper {
	/**o
	 * Metodos publicos de la clase GLDrawHelper.
	 */
	public:
        /**
		 * Dibuja un rectangulo lleno con un color determinado.
		 */
        static void drawRectangle(const GLint& left, const GLint& right, const GLint& top, const GLint& bottom,
            Color& color);
		/**
		 * Dibuja un rectangulo lleno con un color determinado.
		 */
		static void drawFilledRectangle(const GLint& left, const GLint& right, const GLint& top, const GLint& bottom,
			Color& color);
		/**
		 * Calcula el ancho de un texto determinado.
		 */
		static int calculateTextWidth(const std::string& text, const int& padding = 0);
		/**
		 * Calcula el alto de un texto determinado.
		 */
		static int calculateTextHeight(const std::string& text, const int& padding = 0);
		/**
		 * Dibuja un texto centrado a partir de una dimension.
		 */
		static void drawCenteredText(const std::string& text, Dimension& dimension, Color& color);
		/**
		 * Dibuja un texto a partir de la posicion x, y.
		 */
		static void drawText(const std::string& text, const GLint& x, const GLint& y, Color& color);
};

#endif /** __GLDRAWHELPER_H__ */

