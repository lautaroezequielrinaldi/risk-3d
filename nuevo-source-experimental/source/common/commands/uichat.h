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

		virtual std::string getName();

		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);
};

#endif /* __UICHAT_H__*/
