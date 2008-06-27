#ifndef __GL3DWIDGET_H__
#define __GL3DWIDGET_H__ 

#include "glwidget.h"

class GL3DWidget: public GLWidget {
    /**
	 * Metodos protegidos de la clase GL3DWidget.
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
	 * Metodos publicos de la clase GL3DWidget.
	 */
    public:
        /**
		 * Constructor de la clase GL3DWidget.
		 */
        GL3DWidget();
        /**
		 * Destructor virtual de la clase GL3DWidget.
		 */
        virtual ~GL3DWidget();

};

#endif /** __GL3DWIDGET_H__ */

