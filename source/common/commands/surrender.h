#ifndef __SURRENDER__
#define __SURRENDER__

/**
 * client => server => client
 *
 * Comando para indicar el deseo de abandonar el juego pero permanecer mirando.
 */

#include "command.h"
class Surrender:public Command{
	public:
	Surrender();
	
	virtual ~Surrender();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(std::string xml);
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
	virtual void execute(ReferenceCountPtr<State>& state);
		virtual std::string getName();
};

#endif /* __SURRENDER__*/
