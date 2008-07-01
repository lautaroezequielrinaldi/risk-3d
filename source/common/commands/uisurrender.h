#ifndef __UISURRENDER__
#define __UISURRENDER__

/**
 * client => server => client
 *
 * Comando para indicar el deseo de abandonar el juego pero permanecer mirando.
 */

#include "uicommand.h"
class UISurrender:public UICommand{

	
	//private:
	//	int numeroJugador;
	public:

		UISurrender(std::vector<std::string> &parameterList);

		UISurrender();
	
		virtual ~UISurrender();

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

#endif /* __UISURRENDER__*/
