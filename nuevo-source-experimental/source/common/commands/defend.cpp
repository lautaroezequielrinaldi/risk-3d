#include<sstream>
#include "defend.h"
#include "commandobserver.h"

#include<iostream>

using namespace std;

Defend::Defend(std::vector<std::string> &parameterList) : Command ()
{
	this->paisDefensor = parameterList[0];
	this->cantidadEjercitos = atoi ( parameterList[1].c_str() );
	this->jugadorAtacante = atoi (parameterList[2].c_str() );
	this->jugadorDefensor = atoi (parameterList[3].c_str() );
	
}

Defend::Defend(const std::string & xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}
Defend::Defend(){

}

Defend::~Defend()
{
}

std::string Defend::serialize(){
	

	std::string defensaSeralizado;

	//conversion de entero a string para la cantidad de ejercitos
  	std::ostringstream strCantEjercitos;
   	strCantEjercitos << this->cantidadEjercitos;

	defensaSeralizado = "<?xml version=\"1.0\"?><defender>";
	
	std::string xmlComando = serializeCommon(this->jugadorDefensor,this->jugadorAtacante);

	std::string xmlDefend = "<pais-defensor>"+this->paisDefensor
				+"</pais-defensor><cantidad-ejercitos>"+strCantEjercitos.str()+"</cantidad-ejercitos></defender>";

	defensaSeralizado += xmlComando + xmlDefend;

    return defensaSeralizado;
  
	
}

void* Defend::hydrate(const std::string & xml){
		
	xmlDocPtr document= hydrateCommon(xml);
	xmlNodePtr nodoRaiz;
    
    xmlChar* paisDef;
	xmlChar* cantE;    
    
    // Defino un contexto de XPath.
    xmlXPathContextPtr contextoXPath;
    // Defino 2 objetos de XPath.
    xmlXPathObjectPtr objetoXPathPais, objetoXPathEjer ;
    // Defino el set de nodos devueltos por la expresiòn XPath.(una estructura que tiene un array con los nodos
    //devueltos por la expresion y el numero de nodos.
    xmlNodeSetPtr setNodoDefensa;


	// Obtengo el elemento root del documento XML sobre el cual se va a trabajar.
    nodoRaiz = xmlDocGetRootElement(document);

    // Creo el contexto de XPath.
    contextoXPath = xmlXPathNewContext(document);

	 // Evaluo la expresiòn XPath.
    objetoXPathPais = xmlXPathEvalExpression(BAD_CAST "//defender/pais-defensor", contextoXPath);

	// Obtengo el set de nodos de paises.
    setNodoDefensa = objetoXPathPais->nodesetval;

    //nodeNr = cantidad de nodos que devolvio la expresion xpath - nodeTab = array de nodos devulto
    // Obtengo el nodo del pais actual.
	xmlNodePtr nodoPaisDefiende = setNodoDefensa->nodeTab[0];

	// Obtengo el nombre del pais que defiende y lo seteo en objeto.
	paisDef = xmlNodeGetContent(nodoPaisDefiende);

	this->paisDefensor.assign( (char*) paisDef);

	
	// Evaluo la expresiòn XPath para la cantidad de ejercitos
    objetoXPathEjer = xmlXPathEvalExpression(BAD_CAST "//defender/cantidad-ejercitos",  contextoXPath);

    // Obtengo el set de nodos.
    setNodoDefensa = objetoXPathEjer->nodesetval;

    //nodeNr = cantidad de nodos que devolvio la expresion xpath
    //nodeTab = array de nodos devulto
	// Obtengo el nodo de la cantidad de ejercitos actual
	xmlNodePtr nodoCantEj = setNodoDefensa->nodeTab[0];

	// Obtengo cantidad de ejercitos y la seteo en objeto
    cantE = xmlNodeGetContent(nodoCantEj);
    this->cantidadEjercitos = atoi((char*) cantE );    

	
	/*libero recursos*/
	
	xmlFree(paisDef);
	xmlFree (cantE );
	
	xmlXPathFreeObject(objetoXPathPais);
	xmlXPathFreeObject(objetoXPathEjer);
	
	xmlXPathFreeContext(contextoXPath);

    xmlFreeDoc(document);

    xmlCleanupParser();
	

	return NULL;
}
		
std::string Defend::getName() {
	return "defend";
}

std::string Defend::getDefenderdLand(){
	return this->paisDefensor;
}
		
int Defend::getArmyCount(){
	return this->cantidadEjercitos;
}
		
int Defend::getAttackerId(){
	return this->jugadorAtacante;
}

int Defend::getAttackedId(){
	return this->jugadorDefensor;
}

void Defend::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}


