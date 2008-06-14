#ifndef JOINGAME_H_
#define JOINGAME_H_

#include "command.h"

class JoinGame : public Command
{
	
	private:
	
		std::string name;
	
	public:
	
		/*
		 * Constructor de la clase
		 */
		JoinGame(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		JoinGame(std::string xml);
		
		/*
		 * Destructor de la clase
		 */		
		~JoinGame();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(std::string xml);
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		void execute(ReferenceCountPtr<GameManager>& gameManager);
		
		
};

#endif /*JOINGAME_H_*/
