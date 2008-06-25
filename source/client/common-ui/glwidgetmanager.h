#ifndef __GLWIDGETMANAGER_H__
#define __GLWIDGETMANAGER_H__

class GLWidgetManager {
	/**
	 * Atributos privados de la clase GLWidgetManager.
	 */
	private:
		/**
		 * Almacena la instancia singleton de GLWidgetManager.
		 */
		static GLWidgetManager singleton;

	/**
	 * Metodos privados de la clase GLWidgetManager.
	 */
	private:
		/**
		 * Constructor de la clase GLWidgetManager.
		 */
		GLWidgetManager();
		/**
		 * Constructor copia de la clase GLWidgetManager.
		 */
		GLWidgetManager(const GLWidgetManager& otherInstance);
		/**
		 * Operador de asignacion de la clase GLWidgetManager.
		 */
		GLWidgetManager& operator=(const GLWidgetManager& otherInstance);

	/**
	 * Metodos publicos de la clase GLWidgetManager.
	 */
	public:
		/**
		 * Obtiene la instancia singleton de GLWidgetManager.
		 */
		static GLWidgetManager& getInstance();
};

#endif /** __GLWIDGETMANAGER_H__ */

