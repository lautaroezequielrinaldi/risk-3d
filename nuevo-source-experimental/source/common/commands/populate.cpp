#include <sstream>
#include "../model/armybonuscalculator.h"
#include "populate.h"
#include "commandobserver.h"
#include<iostream>

using namespace std;

Populate::Populate(std::vector<std::string> &parameterList) : Command ()
{

	this->paisDestino = parameterList[0];
	this->cantidadEjercitos = atoi( parameterList[1].c_str() );
	this->jugadorFrom = atoi( parameterList[2].c_str() );
}

Populate::Populate(const std::string & xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}
Populate::Populate(){

}

Populate::~Populate()
{
}

std::string Populate::serialize(){
	

	std::string poblarSeralizado;
	

	//conversion de entero a string para la cantidad de ejercitos
  	std::ostringstream strCantEjercitos;
   	strCantEjercitos << this->cantidadEjercitos;

	poblarSeralizado = "<?xml version=\"1.0\"?><poblar>";
	
	std::string xmlComando = serializeCommon(this->jugadorFrom, this->jugadorFrom);

	std::string xmlPoblar = "<pais-destino>"+this->paisDestino
				+"</pais-destino><cantidad-ejercitos>"+strCantEjercitos.str()+"</cantidad-ejercitos></poblar>";

	poblarSeralizado += xmlComando + xmlPoblar;

    return poblarSeralizado;
  
}

void* Populate::hydrate(const std::string &xml){
	

	xmlDocPtr document= hydrateCommon(xml);
	xmlNodePtr nodoRaiz;
    
    xmlChar* paisDes;
	xmlChar* cantE;    
    
    // Defino un contexto de XPath.
    xmlXPathContextPtr contextoXPath;
    // Defino 2 objetos de XPath.
    xmlXPathObjectPtr objetoXPathPais, objetoXPathEjer ;
    // Defino el set de nodos devueltos por la expresiòn XPath.(una estructura que tiene un array con los nodos
    //devueltos por la expresion y el numero de nodos.
    xmlNodeSetPtr setNodoPopulate;

	//parseo el xml en memoria y se construye el arbol
	//document = xmlParseMemory(xml.c_str(), xml.size());
	
	// Obtengo el elemento root del documento XML sobre el cual se va a trabajar.
    nodoRaiz = xmlDocGetRootElement(document);

    // Creo el contexto de XPath.
    contextoXPath = xmlXPathNewContext(document);

	 // Evaluo la expresiòn XPath.
    objetoXPathPais = xmlXPathEvalExpression(BAD_CAST "//poblar/pais-destino", contextoXPath);

	// Obtengo el set de nodos de paises.
    setNodoPopulate = objetoXPathPais->nodesetval;

    //nodeNr = cantidad de nodos que devolvio la expresion xpath - nodeTab = array de nodos devulto
    // Obtengo el nodo del pais actual.
	xmlNodePtr nodoPaisDestino = setNodoPopulate->nodeTab[0];

	// Obtengo el nombre del pais que defiende y lo seteo en objeto.
	paisDes = xmlNodeGetContent(nodoPaisDestino);
	this->paisDestino.assign( (char*) paisDes);

	
	// Evaluo la expresiòn XPath para la cantidad de ejercitos
    objetoXPathEjer = xmlXPathEvalExpression(BAD_CAST "//poblar/cantidad-ejercitos",  contextoXPath);

    // Obtengo el set de nodos.
    setNodoPopulate = objetoXPathEjer->nodesetval;

    //nodeNr = cantidad de nodos que devolvio la expresion xpath
    //nodeTab = array de nodos devulto
	// Obtengo el nodo de la cantidad de ejercitos actual
	xmlNodePtr nodoCantEj = setNodoPopulate->nodeTab[0];

	// Obtengo cantidad de ejercitos y la seteo en objeto
    cantE = xmlNodeGetContent(nodoCantEj);
    this->cantidadEjercitos = atoi((char*) cantE);

	this->jugadorFrom =  this->from;
	
	/*libero recursos*/

	xmlFree(paisDes);
	xmlFree (cantE );
	
	xmlXPathFreeObject(objetoXPathPais);
	xmlXPathFreeObject(objetoXPathEjer);
	xmlXPathFreeContext(contextoXPath);
    xmlFreeDoc(document);
    xmlCleanupParser();
	
	return NULL;
	
}


std::string Populate::getCountryDestination(){
	return this->paisDestino;
}
		 
int Populate::getArmyCount(){
	return this->cantidadEjercitos;
}

std::string Populate::getName() {
	return "populate";
}

int Populate::getMoverId(){
	return this->jugadorFrom;
}

void Populate::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

