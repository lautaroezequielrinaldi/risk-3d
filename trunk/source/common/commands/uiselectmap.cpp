#include "uiselectmap.h"


UISelectMap::UISelectMap(std::vector<std::string> &parameterList) : UICommand (){
	//this->numeroJugador = atoi (parameterList[0].c_str() );
	this->mapName = parameterList[1];
}

UISelectMap::UISelectMap(const std::string& xml):UICommand (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}
UISelectMap::UISelectMap() {

}

UISelectMap::~UISelectMap(){
}

std::string UISelectMap::serialize(){
	return "<?xml version=\"1.0\"?><UISelectMap>"+serializeCommon(0,0)+"<map>"+mapName+"</map></UISelectMap>";
  
}

void* UISelectMap::hydrate(const std::string & xml){
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

std::string UISelectMap::getMapName(){
	return mapName;
}

void UISelectMap::setMapName(const std::string & mapname){
	this->mapName = mapName;
}





