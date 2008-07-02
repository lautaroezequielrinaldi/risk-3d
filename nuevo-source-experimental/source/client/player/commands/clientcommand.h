#ifndef __CLIENTCOMMAND_H__
#define __CLIENTCOMMAND_H__

#include<string> // Para definicion de std::string.
#include "../../../common/smartpointer/referencecountptr.h"
#include "../../../common/model/game.h"

class ClientCommand {
    /**
     * Atributos privados de la clase ClientCommand.
     */
    private:
        /**
         * Almacena una referencia al game.
         */
        ReferenceCountPtr<Game> game;

	/**
	 * Metodos protegidos de la clase ClientCommand.
	 */
	protected:
		/**
		 * Constructor de la clase ClientCommand.
		 */
		ClientCommand(ReferenceCountPtr<Game>& game);
        /**
         * Obtiene el game usado por el comando.
         */
        ReferenceCountPtr<Game>& getGame();

	/**
	 * Metodos publicos de la clase ClientCommand.
	 */
	public:
		/**
		 * Ejecuta un comando.
		 */
		virtual void execute() = 0;
		/**
		 * Devuelve el tipo de comando que es.
		 */
		virtual std::string getType() =0;
		/**
		 * Devuelve una nueva instancia de ClientCommand.
		 */
		virtual ClientCommand* clone() = 0;
		/**
		 * Destructor virtual de la clase ClientCommand.
		 */
		virtual ~ClientCommand();
};

#endif /** __CLIENTCOMMAND_H__ */

