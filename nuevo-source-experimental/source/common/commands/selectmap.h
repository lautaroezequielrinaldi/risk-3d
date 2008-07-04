#ifndef SELECTMAP_H_
#define SELECTMAP_H_

/**
 * client => server
 */

#include "command.h"

class SelectMap : virtual public Command
{

	
	private:
	
		std::string mapName;
		int numeroJugador;

	
	public:
	
		/*
		 * Constructor de la clase
		 */
		SelectMap(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		SelectMap(const std::string &xml);

		SelectMap();
		
		/*
		 * Destructor de la clase
		 */		
		virtual ~SelectMap();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(const std::string &xml);
		
		
		virtual std::string getName();

		std::string getMapName();

		void setMapName(const std::string & mapName);

		/**
		 * Notiifca que se ejecuto un comando.
		 */
		virtual void accept(CommandObserver* observer);
};

#endif /*SELECTMAP_H_*/
