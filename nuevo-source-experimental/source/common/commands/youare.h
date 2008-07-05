#ifndef __YOUARE_H__
#define __YOUARE_H__

/**
 * server => client
 * 
 * mensaje que se envia tras un JoinGame informando al cliente cual es su numero
 */


#include <string>
#include <vector>
#include "command.h"

class YouAre : virtual public Command
{
	
	private:
		int numeroJugador;
	
	public:
		
		/*
		 * Constructor de la clase
		 */
		YouAre(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		YouAre(const  std::string & xml);
		

		YouAre();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~YouAre();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		
		virtual std::string getName();
		
		int getJugador();
		
		/**
		 * Metodo cuyo proposito es establecer la cantidad de jugadores activos que hay.
		 */
		//void setActivePlayerCount( int playerCount );
		/**
		 * Notifica que se ejecuto un comando.
		 */
		virtual void accept(CommandObserver* observer);
};

#endif /*__YOUARE_H__*/
