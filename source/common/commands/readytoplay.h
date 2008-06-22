#ifndef READYTOPLAY_H_
#define READYTOPLAY_H_

#include "command.h"

class ReadyToPlay : public Command
{
	
	private:
	
		std::string name;
	
	public:
	
		/*
		 * Constructor de la clase
		 */
		ReadyToPlay(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		ReadyToPlay(std::string xml);
		

		ReadyToPlay();
		/*
		 * Destructor de la clase
		 */		
		virtual ~ReadyToPlay();
		
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
		bool validate(ReferenceCountPtr<GameManager>& state);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		void execute(ReferenceCountPtr<State>& state);
		
		
};

#endif /*READYTOPLAY_H_*/
