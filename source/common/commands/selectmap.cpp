#include "selectmap.h"

SelectMap::SelectMap(std::vector<std::string> &parameterList) : Command ()
{
	this->numeroJugador = atoi (parameterList[0].c_str() );
	this->nombreMapa = parameterList[1];
}

SelectMap::SelectMap(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}
SelectMap::SelectMap() {

}

SelectMap::~SelectMap()
{
}

std::string SelectMap::serialize(){
	return "<?xml version=\"1.0\"?><selectmap>"+Command::serialize(numeroJugador,0)+"<map>"+nombreMapa+"</map></selectmap>";
  
}

void* SelectMap::hydrate(std::string xml){
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
	this->nombreMapa.assign( (char*) field );

	xmlFree(field);
	xmlXPathFreeObject(objetoXPath);
	xmlXPathFreeContext(contextoXPath);
	xmlFreeDoc(document);
	xmlCleanupParser();
	return NULL;
}

bool SelectMap::validate(ReferenceCountPtr<GameManager>& gameManager){
    // evaluar que el mapa exista	
		return false;
	
}

void SelectMap::execute(ReferenceCountPtr<State>& state){
    state->selectMap(*this);

	
}
std::string SelectMap::getName() {
	return "selectMap";
}



