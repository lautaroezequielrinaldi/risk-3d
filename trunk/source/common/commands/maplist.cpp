#include "maplist.h"

MapList::MapList(){

}
MapList::~MapList(){

}


std::string MapList::serialize(){
	return "<?xml version=\"1.0\"?>maplist><from>0</from><to>$player</to><map>mapa 1</map><map>mapa 2</map></maplist>";
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
