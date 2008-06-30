#ifndef UIREADYTOPLAY_H_
#define UIREADYTOPLAY_H_

/**
 * client => server
 *
 * Indicacion opcional de los clientes para iniciar el juego en caso de que no este completo el cupo
 */

#include "command.h"

class UIReadyToPlay : public Command
{
	
	private:
	
		int numeroJugador;
	
	public:
	
		/*
		 * Constructor de la clase
		 */
		UIReadyToPlay(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		UIReadyToPlay(std::string xml);
		

		UIReadyToPlay();
		/*
		 * Destructor de la clase
		 */		
		virtual ~UIReadyToPlay();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& state);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		void execute(ReferenceCountPtr<State>& state);
		
		virtual std::string getName();
};

#endif /*UIREADYTOPLAY_H_*/
