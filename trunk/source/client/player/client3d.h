#ifndef __CLIENT3D_H__
#define __CLIENT3D_H__

#include <SDL.h>
#include "../common-ui/glwidget.h"
#include "../common-ui/buttonwidget.h"
#include "../../common/smartpointer/referencecountptr.h"

class Client3D {
	/**
	 * Atributos privados de la clase Client3D.
	 */
	private:
		/**
		 * Almacena un boton.
		 */
		ReferenceCountPtr<ButtonWidget> button;

	public:
		Client3D();
		int run();
		~Client3D();
};	

#endif /** __CLIENT3D_H__ */

