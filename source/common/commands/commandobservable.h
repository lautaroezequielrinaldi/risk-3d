#ifndef __COMMANDOBSERVABLE_H__
#define __COMMANDOBSERVABLE_H__

#include<list>
#include "command.h"

/**
 * Forward declaration de la clase CommandObserver.
 */
class CommandObserver;

class CommandObservable {
	/**
	 * Atributos privados de la clase CommandObservable.
	 */
	private:
		/**
		 * Almacena la lista de comman observers.
		 */
		std::list<CommandObserver*> commandObserverList;

	/**
	 * Metodos protegidos de la clase CommandObservable.
	 */
	protected:
		/**
		 * Constructor de la clase CommandObservable.
		 */
		CommandObservable();
		/**
		 * Notifica ejecucion de comando.
		 */
		void notifyCommandExecuted(Command* command);
	/**
	 * Mètodos publicos de la clase CommandObservable.
	 */
	public:
		/**
		 * Registra un observer para ser notificado.
		 */
		void registerObserver(CommandObserver* observer);
		/**
		 * Desregistra un observer para ser notificado.
		 */
		void unregisterObserver(CommandObserver* observer);
		/**
		 * Destructor virtual de la clase CommandObservable.
		 */
		virtual ~CommandObservable();
};

#endif /** __COMMANDOBSERVABLE_H__ */

