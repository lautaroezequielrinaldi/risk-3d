#ifndef __QUIT_H__
#define __QUIT_H__

/**
 * client => server => client
 *
 * Comando para indicar el deseo de abandonar el juego y la conexion.
 */

#include "command.h"
class Quit: public Command {
	
	public:

		Quit(std::vector<std::string> &parameterList);

	Quit();
	virtual ~Quit();
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

#endif /* __QUIT_H__*/
