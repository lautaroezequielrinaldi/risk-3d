#ifndef __ITEMHANDLER_H__
#define __ITEMHANDLER_H__

class ItemHandler {
	/**
	 * Atributos publicos de la clase ItemHandler.
	 */
	public:
		/**
		 * Define un id invalido.
		 */
		static const int INVALID_ID;
		/**
		 * Define id no seleccionado.
		 */
		static const int ID_NOT_SELECTED;
	/**
	 * Atributos privados de la clase ItemHandler.
	 */
	private:
		/**
		 * Lleva la cuenta de todos los item ids que existen.
		 */
		static int itemIdCount;
	/**
	 * Metodos publicos de la clase ItemHandler.
	 */
	public:
		/**
		 * Obtiene el proximo item Id disponible.
		 */
		static int generateNextItemId();
};

#endif /** __ITEMHANDLER_H__ */

