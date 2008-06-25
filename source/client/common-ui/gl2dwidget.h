#ifndef __GL2DWIDGET_H__
#define __GL2DWIDGET_H__

#include "glwidget.h"

class GL2DWidget: public GLWidget {
	/**
	 * Metodos protegidos de la clase GL2DWidget.
	 */
	protected:
		/**
		 * Predibuja el widget.
		 */
		virtual void preDrawWidget();
		/**
		 * Postdibuja el widget.
		 */
		virtual void postDrawWidget();

	/**
	 * Metodos publicos de la clase GL2DWidget.
	 */
	public:
        /**
		 * Constructor de la clase GL2DWidget.
		 */
        GL2DWidget();
        /**
		 * Constructor de la clase GLWidget.
		 */
        GL2DWidget(const Dimension& dimension, const bool& visible = true, const bool& enabled = true);
		/**
		 * Destructor virtual de la clase GL2DWidget.
		 */
		virtual ~GL2DWidget();
};

#endif /** __GL2DWIDGET_H__ */

