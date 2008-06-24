#ifndef __UIMANAGER_H__
#define __UIMANAGER_H__

#include<list>
#include "displaymanager.h"
#include "../../common/smartpointer/referencecountptr.h"

/**
 * Forward declaration de la clase GLWidget.
 */
class GLWidget;

/**
 * Clase singleton que se ocupa de mantener la lista de widgets registrados
 * en la UI, el manejador de display, el manejador de eventos y la informacion
 * del teclado.
 */
class UIManager {
	/**
	 * Atributos privados de la clase UIManager.
	 */
	private:
		/**
		 * Almacena la instancia singleton de la clase UIManager.
		 */
		static UIManager singleton;
		/**
		 * Almacena la lista de widgets usado por la clase UIManager.
		 */
		std::list< ReferenceCountPtr<GLWidget> > widgetList;
		/**
		 * Almacena el display manager usado por la clase UIManager.
		 */
		DisplayManager displayManager;

	/**
	 * Metodos privados de la clase UIManager.
	 */
	private:
		/**
		 * Constructor copia de la clase UIManager.
		 */
		UIManager(const UIManager& otherInstance);
		/**
		 * Operador de asignacion de la clase UIManager.
		 */
		UIManager& operator=(const UIManager& otherInstance);
		/**
		 * Constructor de la clase UIManager.
		 */
		UIManager();

	/**
	 * Metodos publicos de la clase UIManager.
	 */
	public:
		/**
		 * Devuelve la unica instancia de la clase UIManager.
		 */
		static UIManager& getInstance();
		/**
		 * Agrega un widget a la lista de widgets de la clase UIManager.
		 */
		void addWidget(const ReferenceCountPtr<GLWidget>& widget);
		/**
		 * Remueve un widget de la lista de widgets de la clase UIManager.
		 */
		void removeWidget(const ReferenceCountPtr<GLWidget>& widget);
		/**
		 * Dibuja todos los widgets registrados y que estan visibles.
		 */
		void drawAllWidgets();
		/**
		 * Obtiene el display manager usado por la clase UIManager.
		 */
		DisplayManager& getDisplayManager();
		/**
		 * Destructor virtual de la clase UIManager.
		 */
		virtual ~UIManager();
};

#endif /** __UIMANAGER_H__ */

