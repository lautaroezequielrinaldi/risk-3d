#ifndef UIREADYTOPLAY_H_
#define UIREADYTOPLAY_H_

/**
 * client => server
 *
 * Indicacion opcional de los clientes para iniciar el juego en caso de que no este completo el cupo
 */

#include "uicommand.h"

class UIReadyToPlay : virtual public UICommand
{
	
	//private:
	
		//int numeroJugador;
	
	public:
	
		/*
		 * Constructor de la clase
		 */
		UIReadyToPlay(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		UIReadyToPlay(const std::string & xml);
		

		UIReadyToPlay();
		/*
		 * Destructor de la clase
		 */		
		virtual ~UIReadyToPlay();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		virtual std::string getName();
};

#endif /*UIREADYTOPLAY_H_*/
