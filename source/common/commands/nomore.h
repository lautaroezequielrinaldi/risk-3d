#ifndef __NOMORE_H__
#define __NOMORE_H__
#include "command.h"

/**
 * client => server => client
 *
 * Comando utilizado para señalar el fin de Attacking o Moving
 */

class NoMore: public Command {
	private:
		int numeroJugador;
	public:

		NoMore(std::vector<std::string> &parameterList);
		NoMore();
		virtual ~NoMore();

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

#endif /* __NOMORE_H__*/
