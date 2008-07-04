#ifndef __UIQUIT_H__
#define __UIQUIT_H__

/**
 * client => server => client
 *
 * Comando para indicar el deseo de abandonar el juego y la conexion.
 */

#include "uicommand.h"
class UIQuit: public UICommand {
	

	public:

		UIQuit(std::vector<std::string> &parameterList);

		UIQuit();
		virtual ~UIQuit();
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		virtual std::string getName();
};

#endif /* __UIQUIT_H__*/
