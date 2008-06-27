#include <sstream>
#include "../model/armybonuscalculator.h"
#include "populate.h"

#include<iostream>
using namespace std;

Populate::Populate(std::vector<std::string> &parameterList) : Command ()
{
	this->paisDestino = parameterList[0];
	this->cantidadEjercitos = atoi( parameterList[1].c_str() );
}

Populate::Populate(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}
Populate::Populate(){

}

Populate::~Populate()
{
}

std::string Populate::serialize(){
	return "<?xml version=\"1.0\"?><populate><from>$player></from><to>0</to><country>$country</country><army>$armies</army></populate>";

	std::string poblarSeralizado;
	
	// creo documento
	xmlDocPtr docPoblar;
	// defino nodo raiz
	xmlNodePtr nodoPoblar;
	
	// defino nodos hijos de raiz
    xmlNodePtr nodoPaisDestino;
    xmlNodePtr nodoCantidadEjercitos;
    
    // creo xmlChar para persistir a una cadena de caracteres el xml
    xmlChar *xmlbuff;
    int buffersize;

    // creo documento
    docPoblar = xmlNewDoc(BAD_CAST "1.0");
    
    //seteo contenido del nodo raiz
    nodoPoblar = xmlNewNode(NULL, BAD_CAST "poblar");
    
    //seteo el nodo raiz del documento
    xmlDocSetRootElement(docPoblar, nodoPoblar);
    
    //seteo hijos de nodoPoblar: nodo pais-destino
    nodoPaisDestino = xmlNewChild(nodoPoblar, NULL, BAD_CAST "pais-destino",(const xmlChar*) this->paisDestino.c_str() );
   
   	//conversion de entero a string para la cantidad de ejercitos
  	std::ostringstream strCantEjercitos;
   	strCantEjercitos << this->cantidadEjercitos;
   
   //seteo como hijo de nodoPoblar al nodo cantidad-ejercitos
    nodoCantidadEjercitos = xmlNewChild(nodoPoblar, NULL, BAD_CAST "cantidad-ejercitos",(const xmlChar*)(const xmlChar*)strCantEjercitos.str().c_str() );
    
    // dejo el document en un buffer
    xmlDocDumpFormatMemory(docPoblar, &xmlbuff, &buffersize, 1);
   
   /*seteo el string que se devolvera almacenando al XML*/
    poblarSeralizado.assign((char*)xmlbuff);
	
	//libero memoria utilizada
    xmlFree(xmlbuff);
    xmlFreeDoc(docPoblar);
    xmlCleanupParser();
    
    return poblarSeralizado;
  
}

void* Populate::hydrate(std::string xml){
	

	xmlDocPtr document;
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
	document = xmlParseMemory(xml.c_str(), xml.size());
	
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

bool Populate::validate(ReferenceCountPtr<GameManager>& gameManager){
	
	bool resul=false;
	ReferenceCountPtr<Game> game = gameManager->getGame();
	ReferenceCountPtr<TurnManager> turnManager = gameManager->getTurnManager();
	ReferenceCountPtr<Player> jugadorActual = game->getPlayer( turnManager->getCurrentPlayer());
	
	//si el pais destino es del jugador actual
	if( jugadorActual->landOwner(this->paisDestino) ){	
		//si la cant de ejercitos a usar es menor o igual que la cantidad disponible del jugador
		if (this->cantidadEjercitos <=  jugadorActual->getArmyCount() )
			resul= true;
		else
			cout<<"no tenes esa cantidad de ejercitos disponibles!!!!!!!!!!!!!!!!!!!!!!"<<endl;
	}
	else
		cout<<"no es tu pais!!!!!!!!!!!!!!!!!"<<endl;
	
	return resul;
	
}

bool Populate::validateOccupy(ReferenceCountPtr<GameManager>& gameManager){

	bool res = false;

	ReferenceCountPtr<Game> game = gameManager->getGame();

	ReferenceCountPtr<Mapa> map = game->getMapa();
	ReferenceCountPtr<Pais> paisD = map->obtenerPais(this->paisDestino);


	// si pais destino esta vacio
	if ( paisD->getArmyCount() == 0 ){
		// si quiere ubicar solo 1 ejercito
		if ( this->cantidadEjercitos == 1 )
			res = true;
		else
			cout<<"NO PUEDE UBICAR MAS DE UN EJERCITO"<<endl;
	}    
	else
		cout<<"PAIS YA OCUPADO"<<endl;


	return res;
}


void Populate::execute(ReferenceCountPtr<State>& state){
	
	state->populate(*this);
	
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




