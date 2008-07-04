#ifndef __QUIT_H__
#define __QUIT_H__

/**
 * client => server => client
 *
 * Comando para indicar el deseo de abandonar el juego y la conexion.
 */

#include "command.h"
class Quit: public virtual Command {
	
	public:

		Quit(std::vector<std::string> &parameterList);
        Quit(const std::string& xml);
		Quit();
		
		virtual ~Quit();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		
		virtual std::string getName();

		/**
		 * Notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer);
};

#endif /* __QUIT_H__*/
