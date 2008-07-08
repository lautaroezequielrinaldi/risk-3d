#include <sstream>
#include "move.h"
#include "commandobserver.h"

#include<iostream>
using namespace std;

Move::Move(std::vector<std::string> &parameterList): Command ()
{
	this->paisOrigen = parameterList[0];
	this->paisDestino = parameterList[1];
	this->cantidadEjercitos = atoi( parameterList[2].c_str() );
	this->jugadorFrom = atoi ( parameterList[3].c_str() );
}

Move::Move(const std::string &xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

Move::Move(){

}

Move::~Move()
{
}

std::string Move::serialize(){
	
	std::string movimientoSeralizado;

	//conversion de entero a string para la cantidad de ejercitos
  	std::ostringstream strCantEjercitos;
   	strCantEjercitos << this->cantidadEjercitos;

	movimientoSeralizado = "<?xml version=\"1.0\"?><mover>";
	
	std::string xmlComando = serializeCommon(this->jugadorFrom, this->jugadorFrom);

	std::string xmlMove = "<pais-origen>"+this->paisOrigen+"</pais-origen><pais-destino>"+
			      this->paisDestino+"</pais-destino><cantidad-ejercitos>"+strCantEjercitos.str()
			      +"</cantidad-ejercitos></mover>";

	movimientoSeralizado += xmlComando + xmlMove;


    return movimientoSeralizado;
	
}

void* Move::hydrate(const std::string &xml){
	
	
	xmlDocPtr document = hydrateCommon(xml);
	xmlNodePtr nodoRaiz;
    
    xmlChar* paisOri;
	xmlChar* paisDest;
	xmlChar* cantE;
    
    // Defino un contexto de XPath.
    xmlXPathContextPtr contextoXPath;
    // Defino 2 objetos de XPath.
    xmlXPathObjectPtr objetoXPathPaisO,objetoXPathPaisD, objetoXPathEjer ;
    // Defino el set de nodos devueltos por la expresiòn XPath.(una estructura que tiene un array con los nodos
    //devueltos por la expresion y el numero de nodos.
    xmlNodeSetPtr setNodoMove;


	// Obtengo el elemento root del documento XML sobre el cual se va a trabajar.
    nodoRaiz = xmlDocGetRootElement(document);

    // Creo el contexto de XPath.
    contextoXPath = xmlXPathNewContext(document);


	 // Evaluo la expresiòn XPath para pais origen
    objetoXPathPaisO = xmlXPathEvalExpression(BAD_CAST "//mover/pais-origen", contextoXPath);

	// Obtengo el set de nodos de paises.
    setNodoMove = objetoXPathPaisO->nodesetval;

    //nodeNr = cantidad de nodos que devolvio la expresion xpath - nodeTab = array de nodos devulto
    // Obtengo el nodo del pais actual.
	xmlNodePtr nodoPaisO = setNodoMove->nodeTab[0];

	// Obtengo el nombre del pais que defiende y lo seteo en objeto.
	paisOri = xmlNodeGetContent(nodoPaisO);

	this->paisOrigen.assign( (char*) paisOri );
	

	// Evaluo la expresiòn XPath para pais destino
    objetoXPathPaisO = xmlXPathEvalExpression(BAD_CAST "//mover/pais-destino", contextoXPath);

	// Obtengo el set de nodos de paises.
    setNodoMove = objetoXPathPaisO->nodesetval;

    //nodeNr = cantidad de nodos que devolvio la expresion xpath - nodeTab = array de nodos devulto
    // Obtengo el nodo del pais actual.
	xmlNodePtr nodoPaisD = setNodoMove->nodeTab[0];

	// Obtengo el nombre del pais que defiende y lo seteo en objeto.
	paisDest = xmlNodeGetContent(nodoPaisD);
	
	this->paisDestino.assign( (char*) paisDest );

	
	// Evaluo la expresiòn XPath para la cantidad de ejercitos
    objetoXPathEjer = xmlXPathEvalExpression(BAD_CAST "//poblar/cantidad-ejercitos",  contextoXPath);

    // Obtengo el set de nodos.
    setNodoMove = objetoXPathEjer->nodesetval;

    //nodeNr = cantidad de nodos que devolvio la expresion xpath
    //nodeTab = array de nodos devulto
	// Obtengo el nodo de la cantidad de ejercitos actual
	xmlNodePtr nodoCantEj = setNodoMove->nodeTab[0];

	// Obtengo cantidad de ejercitos y la seteo en objeto
    cantE = xmlNodeGetContent(nodoCantEj);
    
    this->cantidadEjercitos = atoi((char*) cantE );

	this->jugadorFrom  = this->from;
	
	/*libero recursos*/

	xmlFree(paisOri);
	xmlFree(paisDest);
	xmlFree (cantE );
	
	xmlXPathFreeObject(objetoXPathPaisO);
	xmlXPathFreeObject(objetoXPathPaisD);
	xmlXPathFreeObject(objetoXPathEjer);
	
	xmlXPathFreeContext(contextoXPath);
    xmlFreeDoc(document);
    xmlCleanupParser();
	
	return NULL;
	
}
		

std::string Move::getName() {
	return "move";
}

std::string  Move::getCountryDestination(){
	return this->paisDestino;
}		 

std::string  Move::getCountryOrigin(){
	return this->paisOrigen;
}

int  Move::getArmyCount(){
	return this->cantidadEjercitos;
}

int Move::getMoverId(){
	return this->jugadorFrom;
}






void Move::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

