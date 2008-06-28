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
	MapList();
	virtual ~MapList();
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
	virtual void execute(ReferenceCountPtr<State>& state);
		
		virtual std::string getName();
};

#endif /* __MAPLIST_H__*/
