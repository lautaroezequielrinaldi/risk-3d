#include<sstream>
#include "map.h"
#include "commandobserver.h"

Map::Map(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	
}

Map::Map(const std::string & xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

Map::Map(){

}

Map::~Map()
{
	//no realiza ninguna accion
}

std::string Map::serialize(){
	 return "<?xml version=\"1.0\"?>mapa....";
}

void* Map::hydrate(const std::string & xml){
	
	
	return NULL;
;
	
}
		


std::string Map::getName() {
	return "map";
}

void Map::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

