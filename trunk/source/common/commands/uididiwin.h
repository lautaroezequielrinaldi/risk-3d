#ifndef __uididiwin_h__
#define __uididiwin_h__

/**
 * client => server 
 */

#include "command.h"
class UIDidIWin: public Command {


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

		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
	virtual void execute(ReferenceCountPtr<State>& state);
		
		virtual std::string getName();
};

#endif /* __UIDidIWin_H__*/
