#ifndef __UICOMMAND_H__
#define __UICOMMAND_H__

#include "command.h"

class UICommand: public Command {
	/**
	 * Metodos protegidos de la clase UICommand.
	 */
	private:
		/**
		 * Constructor de la clase UICommand.
		 */
		UICommand(std::vector<std::string> &parameterList);

	protected:
		/**
		 * Constructor de la clase UICommand.
		 */
		UICommand(); 
	/**
	 * Metodos publicos de la clase UICommand.
	 */
	public:
		/**
		 * Metodo que notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer);
		/**
		 * Destructor virtual de la clase UICommand.
		 */
		virtual ~UICommand();
};

#endif /** __UICOMMAND_H__ */

