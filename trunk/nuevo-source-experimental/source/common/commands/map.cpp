#include<sstream>
#include "map.h"
#include "commandobserver.h"

Map::Map(std::vector<std::string> & parameterList):Command ()
{
		
}

Map::Map(const std::string & xml):Command (){

	// construye el objeto a partir del Xml recibido
	//hydrate(xml);
	this->mapa = xml;
	
}

Map::Map(){
}

Map::~Map()
{
	//no realiza ninguna accion
}

std::string Map::serialize(){
	 
	 return  this->mapa ;
}

void* Map::hydrate(const std::string & xml){
	
	this->mapa = xml;	

	return NULL;
}
		
std::string Map::getName() {
	return "map";
}

std::string Map::getMap(){
	return this->mapa;
}

void Map::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

