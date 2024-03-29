#ifndef __DIDIWIN_H__
#define __DIDIWIN_H__

/**
 * client => server 
 */

#include "command.h"
class DidIWin: public Command {


	private:
		int numeroJugador;
	public:

		DidIWin(std::vector<std::string> &parameterList);
		DidIWin();
	virtual ~DidIWin();
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

#endif /* __DIDIWIN_H__*/
