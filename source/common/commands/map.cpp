#include<sstream>
#include "map.h"

Map::Map(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	
}

Map::Map(std::string xml):Command (){

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
	 return "<?xml version=\"1.0\"?>";
}

void* Map::hydrate(std::string xml){
	
	
	return NULL;
;
	
}
		
bool Map::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void Map::execute(ReferenceCountPtr<State>& state){
	
	state->map(*this);
	
}

std::string Map::getName() {
	return "map";
}


