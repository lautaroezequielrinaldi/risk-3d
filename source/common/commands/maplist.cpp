#include "maplist.h"
#include "commandobserver.h"

MapList::MapList(std::vector<std::string> &parameterList) : Command ()
{

	this->numeroJugador = atoi (parameterList[0].c_str() );
}


MapList::MapList(){

}
MapList::~MapList(){

}


std::string MapList::serialize(){
	return "<?xml version=\"1.0\"?><maplist>"+Command::serialize(0,numeroJugador)+"<maps><map>mapa 1</map><map>mapa 2</map></maps></maplist>";
}
bool MapList::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}
void* MapList::hydrate(const std::string & xml){
	xmlChar* field;
	xmlXPathObjectPtr objetoXPath;
	xmlNodeSetPtr setNodo;
	xmlNodePtr nodo;
	xmlDocPtr document = hydrateCommon(xml);
	

	xmlXPathContextPtr contextoXPath = xmlXPathNewContext(document);

	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//*/maps/map", contextoXPath);
	setNodo = objetoXPath->nodesetval;

// esto va dentro de un loop
	nodo = setNodo->nodeTab[0];
	field = xmlNodeGetContent(nodo);
	//this->nombreMapa.assign( (char*) field );

	xmlFree(field);
	xmlXPathFreeObject(objetoXPath);
	xmlXPathFreeContext(contextoXPath);
	xmlFreeDoc(document);
	xmlCleanupParser();
	return NULL;
	return NULL;
}

void MapList::execute(ReferenceCountPtr<State>& state){
	
	state->mapList(*this);
	
}

std::string MapList::getName() {
	return "mapList";
}

void MapList::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

