#ifndef JOINGAME_H_
#define JOINGAME_H_

/**
 * client => server
 *
 * Comando para unirse al juego
 */

#include "command.h"

class JoinGame : public Command
{
	
	private:
		int numeroJugador;
	
	public:
	
		/*
		 * Constructor de la clase
		 */
		JoinGame(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		JoinGame(const std::string & xml);
		
		JoinGame();
		/*
		 * Destructor de la clase
		 */		
		virtual ~JoinGame();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		void execute(ReferenceCountPtr<State>& state);
		
		virtual std::string getName();

		/**
		 * Notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer);
};

#endif /*JOINGAME_H_*/
