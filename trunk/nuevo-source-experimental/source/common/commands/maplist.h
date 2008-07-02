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
	MapList(std::vector<std::string> &parameterList);
    MapList(const std::string& xml);
	MapList();
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
