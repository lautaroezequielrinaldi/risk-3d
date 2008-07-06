#include "selectmap.h"
#include "commandobserver.h"

SelectMap::SelectMap(std::vector<std::string> &parameterList) : Command ()
{
	this->numeroJugador = atoi (parameterList[0].c_str() );
	this->mapName = parameterList[1];
}

SelectMap::SelectMap(const std::string &xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}
SelectMap::SelectMap() {

}

SelectMap::~SelectMap()
{
}

std::string SelectMap::serialize(){
	return "<?xml version=\"1.0\"?><selectmap>"+serializeCommon(getFrom(),getTo())+"<map>"+this->mapName+"</map></selectmap>";
  
}

void* SelectMap::hydrate(const std::string & xml){
	xmlChar* field;
	xmlXPathObjectPtr objetoXPath;
	xmlNodeSetPtr setNodo;
	xmlNodePtr nodo;
	xmlDocPtr document = hydrateCommon(xml);
	

	xmlXPathContextPtr contextoXPath = xmlXPathNewContext(document);

	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//*/map", contextoXPath);
	setNodo = objetoXPath->nodesetval;
	nodo = setNodo->nodeTab[0];
	field = xmlNodeGetContent(nodo);
	this->mapName.assign( (char*) field );

	xmlFree(field);
	xmlXPathFreeObject(objetoXPath);
	xmlXPathFreeContext(contextoXPath);
	xmlFreeDoc(document);
	xmlCleanupParser();
	return NULL;
}


std::string SelectMap::getName() {
	return "selectMap";
}

void SelectMap::setMapName(const std::string & mapName) {
	this->mapName = mapName;
}

std::string SelectMap::getMapName(){
	return mapName;
}


void SelectMap::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

