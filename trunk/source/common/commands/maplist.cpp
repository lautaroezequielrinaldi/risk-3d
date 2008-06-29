#include "maplist.h"


MapList::MapList(std::vector<std::string> &parameterList) : Command ()
{

	this->numeroJugador = atoi (parameterList[0].c_str() );
}


MapList::MapList(){

}
MapList::~MapList(){

}


std::string MapList::serialize(){
	return "<?xml version=\"1.0\"?>maplist>"+Command::serialize(0,numeroJugador)+"<maps><map>mapa 1</map><map>mapa 2</map></maps></maplist>";
}
bool MapList::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}
void* MapList::hydrate(std::string xml){

	return NULL;
}

void MapList::execute(ReferenceCountPtr<State>& state){
	
	state->mapList(*this);
	
}

std::string MapList::getName() {
	return "MapList";
}
