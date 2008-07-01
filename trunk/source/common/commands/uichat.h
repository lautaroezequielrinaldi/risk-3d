#ifndef __UICHAT_H__
#define __UICHAT_H__

/**
 * client => server => client
 */

#include "uicommand.h"
class UIChat: public UICommand {
	public:

		UIChat(std::vector<std::string> &parameterList);
		UIChat();
		virtual ~UIChat();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		virtual void execute(ReferenceCountPtr<State>& state);
		

		virtual std::string getName();


};

#endif /* __UICHAT_H__*/
