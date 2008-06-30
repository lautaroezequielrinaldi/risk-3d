#include "battleresult.h"
#include <sstream>

BattleResult::BattleResult( std::string attackerLand, std::string defenderLand, int jugadorAtacante, int jugadorDefensor):
Command(),
paisAtacante(attackerLand),
paisDefensor(defenderLand),
jugadorAtacante(jugadorAtacante),
jugadorDefensor(jugadorDefensor)
{
	//this->jugadorAtacante = jugadorAtacante;
	//this->jugadorDefensor= jugadorDefensor;
	this->resultadoAtacante=0;
	this->resultadoDefensor=0;
	this->conquista=0;
}

BattleResult::BattleResult()
{
	//no realiza ninguna accion
}

BattleResult::~BattleResult()
{
	
	//no realiza ninguna accion
}

std::string BattleResult::getAttackerLand(){
	return this->paisAtacante;
}
		
std::string BattleResult::getDefenderLand(){
	return this->paisDefensor;	
}
				
int BattleResult:: getAttackerResult(){
	return this->resultadoAtacante;
}
		
int BattleResult::getDefenderResult(){
	return this->resultadoDefensor;
}
				
void BattleResult::incrementAttackerLostArmy(){
	this->resultadoAtacante += 1;	
}
			
void BattleResult::incrementDefenderLostArmy(){
	this->resultadoDefensor += 1;	
}

void BattleResult::setConquest ( int armyCount ){
	this->conquista = armyCount;
}



std::string BattleResult::serialize(){

	std::string resultadoBatallaSeralizado;

	//conversion de entero a string para resultadoAtacante resultadoDefensor y conquista
  	std::ostringstream strResulAtacante, strResulDefensor, strConquista;
   	strResulAtacante << this->resultadoAtacante;
	strResulDefensor << this->resultadoDefensor;
	strConquista << this->conquista;

	resultadoBatallaSeralizado = "<?xml version=\"1.0\"?><resultadoBatalla>";
	
	std::string xmlComando = Command::serialize(this->jugadorAtacante, this->jugadorDefensor);

	std::string xmlBattleRes = "<pais-atacante>" + this->paisAtacante + "</pais-atacante><pais-defensor>" + this->paisDefensor 
	+ "</pais-defensor><resultado-atacante>" + strResulAtacante.str() + "</resultado-atacante><resultado-defensor>"+		strResulDefensor.str() + "</resultado-defensor><conquista>" + strConquista.str() + "</conquista></resultadoBatalla>";

	resultadoBatallaSeralizado += xmlComando + xmlBattleRes;


	return resultadoBatallaSeralizado;
	
}

void* BattleResult::hydrate(std::string xml){
	

	xmlDocPtr document= hydrateCommon(xml);

	xmlNodePtr nodoRaiz;
	xmlChar* paisDef;
	xmlChar* paisAt;
	xmlChar* resAt; 
	xmlChar* resDef;
	xmlChar* resCon;

    
    // Defino un contexto de XPath.
    	xmlXPathContextPtr contextoXPath;
    // Defino 2 objetos de XPath.
    	xmlXPathObjectPtr objetoXPath ;
    // Defino el set de nodos devueltos por la expresiòn XPath.(una estructura que tiene un array con los nodos
    //devueltos por la expresion y el numero de nodos.
    	xmlNodeSetPtr setNodos;

	//parseo el xml en memoria y se construye el arbol
   	document = xmlParseMemory(xml.c_str(), xml.size());
	
	// Obtengo el elemento root del documento XML sobre el cual se va a trabajar.
    	nodoRaiz = xmlDocGetRootElement(document);

    // Creo el contexto de XPath.
   	 contextoXPath = xmlXPathNewContext(document);

	 // Evaluo la expresiòn XPath.
    	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//resultadoBatalla/pais-atacante", contextoXPath);

	// Obtengo el set de nodos de paises.
	setNodos = objetoXPath->nodesetval;
	
    	//nodeNr = cantidad de nodos que devolvio la expresion xpath - nodeTab = array de nodos devulto
    	// Obtengo el nodo del pais actual.
	xmlNodePtr nodo = setNodos->nodeTab[0];

	// Obtengo el nombre del pais que defiende y lo seteo en objeto.
	paisAt = xmlNodeGetContent(nodo);

	this->paisAtacante.assign( (char*) paisAt);

	xmlXPathFreeObject(objetoXPath);

	// Evaluo la expresiòn XPath para la cantidad de ejercitos
   	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//resultadoBatalla/pais-defensor",  contextoXPath);

   	 // Obtengo el set de nodos.
  	setNodos = objetoXPath->nodesetval;

    	//nodeNr = cantidad de nodos que devolvio la expresion xpath
    	//nodeTab = array de nodos devulto
	// Obtengo el nodo de la cantidad de ejercitos actual
	nodo = setNodos->nodeTab[0];

	// Obtengo el nombre del pais que defiende y lo seteo en objeto.
	paisDef = xmlNodeGetContent(nodo);

	this->paisDefensor.assign( (char*) paisDef);
	
	xmlXPathFreeObject(objetoXPath);
	
	// Evaluo la expresiòn XPath para la cantidad de ejercitos
   	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//resultadoBatalla/resultado-atacante",  contextoXPath);

   	 // Obtengo el set de nodos.
  	setNodos = objetoXPath->nodesetval;

    	//nodeNr = cantidad de nodos que devolvio la expresion xpath
    	//nodeTab = array de nodos devulto
	// Obtengo el nodo de la cantidad de ejercitos actual
	nodo = setNodos->nodeTab[0];

	// Obtengo el nombre del pais que defiende y lo seteo en objeto.
	resAt = xmlNodeGetContent(nodo);

    	this->resultadoAtacante = atoi((char*) resAt );    

	xmlXPathFreeObject(objetoXPath);	

	// Evaluo la expresiòn XPath para la cantidad de ejercitos
   	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//resultadoBatalla/resultado-defensor",  contextoXPath);

   	 // Obtengo el set de nodos.
  	setNodos = objetoXPath->nodesetval;

    	//nodeNr = cantidad de nodos que devolvio la expresion xpath
    	//nodeTab = array de nodos devulto
	// Obtengo el nodo de la cantidad de ejercitos actual
	nodo = setNodos->nodeTab[0];

	// Obtengo el nombre del pais que defiende y lo seteo en objeto.
	resDef = xmlNodeGetContent(nodo);

    	this->resultadoDefensor = atoi((char*) resDef );    

	xmlXPathFreeObject(objetoXPath);

	// Evaluo la expresiòn XPath para la cantidad de ejercitos
   	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//resultadoBatalla/conquista",  contextoXPath);

   	 // Obtengo el set de nodos.
  	setNodos = objetoXPath->nodesetval;

    	//nodeNr = cantidad de nodos que devolvio la expresion xpath
    	//nodeTab = array de nodos devulto
	// Obtengo el nodo de la cantidad de ejercitos actual
	nodo = setNodos->nodeTab[0];

	// Obtengo el nombre del pais que defiende y lo seteo en objeto.
	resCon = xmlNodeGetContent(nodo);

    	this->conquista = atoi((char*) resCon );    

	xmlXPathFreeObject(objetoXPath);


	/*libero recursos*/
	
	xmlFree(paisDef);
	xmlFree(paisAt);
	xmlFree(resAt );
	xmlFree(resDef );
	xmlFree(resCon);

	
	xmlXPathFreeContext(contextoXPath);
	xmlFreeDoc(document);
    	xmlCleanupParser();

	return NULL;


}

bool BattleResult::validate(ReferenceCountPtr<GameManager>& gameMAnager){
	return true;
}
		
void BattleResult::execute(ReferenceCountPtr<State>& state){

}

std::string BattleResult::getName(){
	return "battleResult";
}


