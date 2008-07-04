#ifndef __UINOMORE_H__
#define __UINOMORE_H__
#include "uicommand.h"

/**
 * client => server => client
 *
 * Comando utilizado para señalar el fin de Attacking o Moving
 */

class UINoMore: virtual public UICommand {
	//private:
	//	int numeroJugador;
	public:

		UINoMore(std::vector<std::string> &parameterList);
		UINoMore();
		virtual ~UINoMore();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		virtual std::string getName();

};

#endif /* __UINOMORE_H__*/
