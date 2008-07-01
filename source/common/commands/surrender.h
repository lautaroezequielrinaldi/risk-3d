#ifndef __SURRENDER__
#define __SURRENDER__

/**
 * client => server => client
 *
 * Comando para indicar el deseo de abandonar el juego pero permanecer mirando.
 */

#include "command.h"
class Surrender:public Command{

	
	private:
		int numeroJugador;
		
	public:

		Surrender(std::vector<std::string> &parameterList);

		Surrender();
	
		virtual ~Surrender();

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
		 * Metodo cuyo proposito es obtener el numero de jugador que se rinde.
		 */
		 int getSurrenderPlayer();

		/**
		 * Notifica que se ejecuto un comando.
		 */
		virtual void accept(CommandObserver* observer);
};

#endif /* __SURRENDER__*/
