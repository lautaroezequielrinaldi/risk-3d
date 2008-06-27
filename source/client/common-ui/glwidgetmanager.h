#ifndef __GLWIDGETMANAGER_H__
#define __GLWIDGETMANAGER_H__

#include<list> // Para definicion de std::list.
#include "gl2dwidget.h"
#include "gl3dwidget.h"
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
		 * Define el tiipo de iterador para widgets 3D.
		 */
		typedef std::list< ReferenceCountPtr<GL3DWidget> >::iterator WidgetIterator3D;

	/**
	 * Atributos privados de la clase GLWidgetManager.
	 */
	private:
		/**
		 * Almacena la lista de widgets 3d reigstrados.
		 */
		static std::list< ReferenceCountPtr<GL3DWidget> > widgetList3D;
		 
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
		static void register2DWidget(const ReferenceCountPtr<GL2DWidget>& widget);
		/**
		 * Desregistro un widget 2D.
		 */
		static void unregister2DWidget(const ReferenceCountPtr<GL2DWidget>& widget);
		/**
		 * Registro un widget 3D.
		 */
		static void register3DWidget(const ReferenceCountPtr<GL3DWidget>& widget);
		/**
		 * Desregistro un widget 3D.
		 */
		static void unregister3DWidget(const ReferenceCountPtr<GL3DWidget>& widget);
		/**
		 * Obtiene un iterador al primer widget 2D.
		 */
		static WidgetIterator2D first2DWidget();
		/**
		 * Obtiene un iterador al ultimo widget 2D.
		 */
		static WidgetIterator2D last2DWidget();
		/**
		 * Obtiene un iterador al primer widget 3D.
		 */
		static WidgetIterator3D first3DWidget();
		/**
		 * Obtiene un iterador al ultimo widget 3D.
		 */
		static WidgetIterator3D last3DWidget();

};

#endif /** __GLWIDGETMANAGER_H__ */

