#ifndef __UIDIDIWIN_H__
#define __UIDIDIWIN_H__

/**
 * client => server 
 */

#include "uicommand.h"
class UIDidIWin: virtual public UICommand {


	//private:
		//int numeroJugador;
	public:

		UIDidIWin(std::vector<std::string> &parameterList);
		UIDidIWin();
	virtual ~UIDidIWin();
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		virtual std::string getName();
};

#endif /* __UIDIDIWIN_H__*/
