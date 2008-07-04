#include "maplist.h"
#include "commandobserver.h"

MapList::MapList(std::vector<std::string> &parameterList) : Command ()
{
	//this->numeroJugador = atoi (parameterList[0].c_str() );
	
	//cargo lista de mapas
	for ( unsigned int i=0; i<parameterList.size() ; i++)
		this->listaMapas.push_back( parameterList[i]  );

}


MapList::MapList(){

}

MapList::MapList(const std::string& xml): Command() {
    hydrate(xml);
}

MapList::~MapList(){

}


std::string MapList::serialize(){
	
	std::string xmlMap = "<?xml version=\"1.0\"?><maplist>"+serializeCommon(0,this->getTo())+"<maps>";
	
	for ( int i=0; i< this->listaMapas.size(); i++)
		xmlMap += "<map>"+ listaMapas.at(i) +"</map>";
		
	xmlMap += "</maps></maplist>";
	
	return xmlMap;
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

	for ( int i = 0; i< setNodo->nodeNr  ; i++){
		
		nodo = setNodo->nodeTab[i];
		field = xmlNodeGetContent(nodo);
		this->listaMapas.push_back((char*)field);
		
	}


	xmlFree(field);
	xmlXPathFreeObject(objetoXPath);
	xmlXPathFreeContext(contextoXPath);
	xmlFreeDoc(document);
	xmlCleanupParser();
	return NULL;
	return NULL;
}



std::string MapList::getName() {
	return "mapList";
}

const std::vector<std::string>& MapList::getMapList(){
	return this->listaMapas;

}


void MapList::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
    std::cerr<<"LLEGO A MAPLIST::ACCEPT"<<std::endl;
}

