#ifndef __GLSPHEREWIDGET_H__
#define __GLSPHEREWIDGET_H__

#include "gl3dwidget.h"

class GLSphereWidget: public GL3DWidget {
	/**
	 * Atributos privados de la clase GLSphereWidget.
	 */
	private:
		/**
		 * Almacena el objeto quadrico para representar la esfera.
		 */
		GLUquadricObj* sphere;
		/**
		 * Almacena el radio de la esfera.
		 */
		float radius;

	/**
	 * Metodos protegidos de la clase GLSphereWidget.
	 */
	protected:
		/**
		 * Dibuja el widget.
		 */
		virtual void drawWidget();

	/**
	 * Metodos publicos de la clase GLSphereWidget.
	 */
	public:
		/**
		 * Constructor de la clase GLSphereWidget.
		 */
		GLSphereWidget(const float& radius = 1.0f);
		/**
		 * Destructor virtual de la clase GLSphereWidget.
		 */
		virtual ~GLSphereWidget();

};

#endif /** __GLSPHEREWIDGET_H__ */

