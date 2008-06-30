#include "uiselectmap.h"

UISelectMap::UISelectMap(std::vector<std::string> &parameterList) : Command (){
	this->numeroJugador = atoi (parameterList[0].c_str() );
	this->nombreMapa = parameterList[1];
}

UISelectMap::UISelectMap(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}
UISelectMap::UISelectMap() {

}

UISelectMap::~UISelectMap(){
}

std::string UISelectMap::serialize(){
	return "<?xml version=\"1.0\"?><UISelectMap>"+Command::serialize(0,0)+"<map>"+nombreMapa+"</map></UISelectMap>";
  
}

void* UISelectMap::hydrate(std::string xml){
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

bool UISelectMap::validate(ReferenceCountPtr<GameManager>& gameManager){
    // evaluar que el mapa exista	
		return false;
	
}

void UISelectMap::execute(ReferenceCountPtr<State>& state){
    state->uiSelectMap(*this);

	
}
std::string UISelectMap::getName() {
	return "uiSelectMap";
}



