#ifndef __MAP_H__
#define __MAP_H__

/**
 * server => client
 * 
 * Comando que se envia una unica vez con toda la informacion del juego
 * Hay que cambiar el nombre a Game algo
 */


#include <string>
#include <vector>
#include "command.h"

class Map : virtual public Command
{
	
	private:
		
		std::string mapa;
	
	public:
		
		/*
		 * Constructor de la clase
		 */
		Map(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		Map(const std::string &xml);
		

		Map();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~Map();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(const std::string &xml);
		
		virtual std::string getName();
		
		/**
		 * Metodo cuyo proposito es obtener el mapa que almacena el comando.
		 */
		std::string getMap();
		/**
		 * Notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer); 		
};

#endif /*__MAP_H__*/
