#ifndef UIJOINGAME_H_
#define UIJOINGAME_H_

/**
 * client => server
 *
 * Comando para unirse al juego
 */

#include "command.h"

class UIJoinGame : public Command
{
	
	//private:
	//	int numeroJugador;
	
	public:
	
		/*
		 * Constructor de la clase
		 */
		UIJoinGame(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		UIJoinGame(const std::string &xml);
		
		UIJoinGame();
		/*
		 * Destructor de la clase
		 */		
		virtual ~UIJoinGame();
		
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
};

#endif /*UIJOINGAME_H_*/
