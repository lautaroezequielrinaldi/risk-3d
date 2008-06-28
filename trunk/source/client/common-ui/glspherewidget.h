#ifndef __GLSPHEREWIDGET_H__
#define __GLSPHEREWIDGET_H__

#include<string>
#include "gl3dwidget.h"

class GLSphereWidget: public GL3DWidget {
	/**
	 * Atributos privados de la clase GLSphereWidget.
	 */
	private:
		/**
		 * Almacena la textura OpenGL a usar con la esfera.
		 */
		GLuint texture;
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
		 * Load texture.
		 */
		void loadTexture(const std::string& imageFileName);
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
		GLSphereWidget(const std::string& imageFileName, const float& radius = 1.0f);
		/**
		 * Carga la textura a la esfera.
		 */
		void setTexture(const std::string& imageFileName);
		/**
		 * Destructor virtual de la clase GLSphereWidget.
		 */
		virtual ~GLSphereWidget();

};

#endif /** __GLSPHEREWIDGET_H__ */

