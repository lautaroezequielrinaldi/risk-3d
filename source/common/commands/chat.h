#ifndef __CHAT_H__
#define __CHAT_H__

/**
 * client => server => client
 */

#include "command.h"
class Chat: public Command {

	public:

	Chat(std::vector<std::string> &parameterList);
	Chat();
	virtual ~Chat();
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

		/**
		 * Notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer);
};

#endif /* __CHAT_H__*/
