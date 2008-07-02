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
		//int numeroJugador;
		
	public:

		Surrender(std::vector<std::string>& parameterList);
        Surrender(const std::string& xml);
		Surrender();
	
		virtual ~Surrender();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		
		virtual std::string getName();

		/**
		 * Notifica que se ejecuto un comando.
		 */
		virtual void accept(CommandObserver* observer);
};

#endif /* __SURRENDER__*/
