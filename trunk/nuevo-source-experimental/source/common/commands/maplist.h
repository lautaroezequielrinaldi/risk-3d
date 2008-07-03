#ifndef __MAPLIST_H__
#define __MAPLIST_H__

/**
 * server => client
 */

#include "command.h"
class MapList: public Command {

	private:
	
		int numeroJugador;
	
	public:
	
		/**
		 * Constructor de la clase.
		 * Recibe un vector de strings donde cada elemento del mismo inicializara un atributo del comando.
		 */
		MapList(std::vector<std::string> &parameterList);
    
    	/**
    	 * Constructor de la clase a partir de un xml.
    	 */
    	MapList(const std::string& xml);
	
		/**
		 * constructor de la clase.
		 */
		MapList();
		
		/**
		 * Destructor de la clase.
		 */
		virtual ~MapList();
	
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(const std::string & xml);
		
		
		virtual std::string getName();

		/**
		 * Notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer);
		
};

#endif /* __MAPLIST_H__*/
