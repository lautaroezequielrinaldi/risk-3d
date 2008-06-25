#ifndef __GLWIDGETMANAGER_H__
#define __GLWIDGETMANAGER_H__

#include<list> // Para definicion de std::list.
#include "gl2dwidget.h"
#include "../../common/smartpointer/referencecountptr.h"

class GLWidgetManager {
	/**
	 * Atributos publicos de la clase GLWidgetManager.
	 */
	public:
		/**
		 * Define el tipo de iterador para widgets 2D.
		 */
		typedef std::list< ReferenceCountPtr<GL2DWidget> >::iterator WidgetIterator2D;

	/**
	 * Atributos privados de la clase GLWidgetManager.
	 */
	private:
		/**
		 * Almacena la lista de widgets 3d reigstrados.
		 * static std::list< ReferenceCountPtr<GL3DWidget> > 3dwidgetList;
		 */
		/**
		 * Almacena la lista de widgets 2d registrados.
		 */
		static std::list< ReferenceCountPtr<GL2DWidget> > widgetList2D;
	
	/**
	 * Metodos publicos de la clase GLWidgetManager.
	 */
	public:
		/**
		 * Registro un widget 2D.
		 */
		static void registerWidget(const ReferenceCountPtr<GL2DWidget>& widget);
		/**
		 * Desregistro un widget 2D.
		 */
		static void unregisterWidget(const ReferenceCountPtr<GL2DWidget>& widget);
		/**
		 * Obtiene un iterador al primer widget 2D.
		 */
		static WidgetIterator2D first2DWidget();
		/**
		 * Obtiene un iterador al ultimo widget 2D.
		 */
		static WidgetIterator2D last2DWidget();

};

#endif /** __GLWIDGETMANAGER_H__ */

