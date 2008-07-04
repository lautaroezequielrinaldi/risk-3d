#ifndef UISELECTMAP_H_
#define UISELECTMAP_H_

/**
 * client => server
 */

#include "uicommand.h"

class UISelectMap : virtual public UICommand
{

	
	private:
	
		std::string mapName;
	
	public:
	
		/*
		 * Constructor de la clase
		 */
		UISelectMap(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		UISelectMap(const std::string &xml);

		UISelectMap();
		
		/*
		 * Destructor de la clase
		 */		
		virtual ~UISelectMap();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		
		virtual std::string getName();

		std::string getMapName();

		void setMapName(const std::string & mapname);
};

#endif /*UISELECTMAP_H_*/
