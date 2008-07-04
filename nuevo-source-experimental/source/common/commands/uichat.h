#ifndef __UICHAT_H__
#define __UICHAT_H__

/**
 * client => server => client
 */

#include "uicommand.h"
class UIChat: virtual public UICommand {
	public:

		UIChat(std::vector<std::string> &parameterList);
		UIChat();
		virtual ~UIChat();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		virtual std::string getName();
};

#endif /* __UICHAT_H__*/
