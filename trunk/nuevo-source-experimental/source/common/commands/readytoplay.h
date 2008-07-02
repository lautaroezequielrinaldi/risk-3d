#ifndef READYTOPLAY_H_
#define READYTOPLAY_H_

/**
 * client => server
 *
 * Indicacion opcional de los clientes para iniciar el juego en caso de que no este completo el cupo
 */

#include "command.h"

class ReadyToPlay : public Command
{
	
	private:
	
		int numeroJugador;
	
	public:
	
		/*
		 * Constructor de la clase
		 */
		ReadyToPlay(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		ReadyToPlay(const std::string & xml);
		

		ReadyToPlay();
		/*
		 * Destructor de la clase
		 */		
		virtual ~ReadyToPlay();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		
		virtual std::string getName();

		/**
		 * Notifica que se recibio un comando.
		 */
		virtual void accept(CommandObserver* observer);
};

#endif /*READYTOPLAY_H_*/
