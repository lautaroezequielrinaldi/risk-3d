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
	
	std::string xmlComando = Command::serialize(this->jugadorFrom, this->jugadorFrom);

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

	//parseo el xml en memoria y se construye el arbol
	//document = xmlParseMemory(xml.c_str(), xml.size());
	
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
		
bool Move::validate(ReferenceCountPtr<GameManager>& gameManager){
	
	bool movimValido=false;
	ReferenceCountPtr<Game> game = gameManager->getGame();
	ReferenceCountPtr<Mapa> map = game->getMapa();
	ReferenceCountPtr<Pais> paisO = map->obtenerPais(this->paisOrigen);
	
	ReferenceCountPtr<TurnManager> turnManager = gameManager->getTurnManager();
	ReferenceCountPtr<Player> jugadorActual = game->getPlayer( turnManager->getCurrentPlayer());
	
	std::string pOr =this->paisOrigen;
	std::string pDe =this->paisDestino;
	
	//si el pais origen es del jugador actual
	if( jugadorActual->landOwner(pOr) ){
	//si el pais destino es del jugador actual
		if( jugadorActual->landOwner(pDe) ){	
			//si pais origen es adyacente al pais destino
			if( paisO->esAdyacente(this->paisDestino)){
				//si la cantidad de ejercitos a mover es menor a la cantidad de ejercitos que tiene el pais origen
				if ( this->cantidadEjercitos < paisO->getArmyCount() )
					movimValido = true;
				else
					cerr<<"error, solo se puede mover una cantidad de ejercitos MENOR al total que posee el pais"<<endl;
			}
			else
				cerr<<"solo se permiten movimientos entre paises adyacentes, error."<<endl;
		}
		else
			cerr<<"el pais destino al cual queres mover ejercitos......no es tuyo!!!"<<endl;
	}
	else
		cerr<<"el pais origen desde el cual queres mover ejercitos......no es tuyo!!!"<<endl;
		
	return movimValido;
	
}

void  Move::execute(ReferenceCountPtr<State>& state){
	
	state->move(*this);
	
	
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

