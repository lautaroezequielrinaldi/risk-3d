#include<sstream>
#include "defend.h"

#include<iostream>

using namespace std;

Defend::Defend(std::vector<std::string> &parameterList) : Command ()
{
	this->paisDefensor = parameterList[0];
	this->cantidadEjercitos = atoi ( parameterList[1].c_str() );
	
}

Defend::Defend(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}
Defend::Defend(){

}

Defend::~Defend()
{
}

std::string Defend::serialize(){
	return "<?xml version=\"1.0\"?><defend><from>$player</from><to>$player</to><army>$armies</army></defend>";
	std::string defensaSeralizado;
	
	// creo documento
	xmlDocPtr docDefensa;
	// defino nodo raiz
	xmlNodePtr nodoDefensa;
	
	// defino nodos hijos de raiz
    xmlNodePtr nodoPaisDefensor;
    xmlNodePtr nodoCantidadEjercitos;
    
    // creo xmlChar para persistir a una cadena de caracteres el xml
    xmlChar *xmlbuff;
    int buffersize;

    // creo documento
    docDefensa = xmlNewDoc(BAD_CAST "1.0");
    
    //seteo contenido del nodo raiz
    nodoDefensa = xmlNewNode(NULL, BAD_CAST "defender");
    
    //seteo el nodo raiz del documento
    xmlDocSetRootElement(docDefensa, nodoDefensa);
    
    //seteo hijos de nodoDefensa: nodo pais-defensor
    nodoPaisDefensor = xmlNewChild(nodoDefensa, NULL, BAD_CAST "pais-defensor",(const xmlChar*) this->paisDefensor.c_str() );
   
   	//conversion de entero a string para la cantidad de ejercitos
  	std::ostringstream strCantEjercitos;
   	strCantEjercitos << this->cantidadEjercitos;
   
   //seteo como hijo de nodoDefensa al nodo cantidad-ejercitos
    nodoCantidadEjercitos = xmlNewChild(nodoDefensa, NULL, BAD_CAST "cantidad-ejercitos",(const xmlChar*)(const xmlChar*)strCantEjercitos.str().c_str() );
    
    // dejo el document en un buffer
    xmlDocDumpFormatMemory(docDefensa, &xmlbuff, &buffersize, 1);
   
   /*seteo el string que se devolvera almacenando al XML*/
    defensaSeralizado.assign((char*)xmlbuff);
	
	//libero memoria utilizada
    xmlFree(xmlbuff);
    xmlFreeDoc(docDefensa);
    xmlCleanupParser();
    
    return defensaSeralizado;
  
	
}

void* Defend::hydrate(std::string xml){
		
	xmlDocPtr document;
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

	//parseo el xml en memoria y se construye el arbol
	document = xmlParseMemory(xml.c_str(), xml.size());
	
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
		
bool Defend::validate(ReferenceCountPtr<GameManager>& gameManager){
	
	bool defensaValida = false;
	ReferenceCountPtr<Game> game = gameManager->getGame();
	ReferenceCountPtr<Mapa> map = game->getMapa();
	ReferenceCountPtr<Pais> paisDefiende = map->obtenerPais(this->paisDefensor);
	
	//obtengo jugador defensor ( al que atacaron en el ataque )
	ReferenceCountPtr<Player> playerDef = game->getPlayer( gameManager->getTurnManager()->getDefenderPlayer() );
	
	// si el jugador seteado como defensor, es el dueño del pais con el que se mando la defensa
	if( playerDef->landOwner( this->paisDefensor ) ){
		
		//si el pais que fue atacado es igual al pais con el que se esta defendiendo el defensor
		if( gameManager->getAttack().getAttackedLand() == this->getDefenderdLand()){
			
			// si pais defensor defiende con 2 o menos ejercitos Y 
			// defiende con menos o igual ejercitos de los que tiene y
			// defiende con una cantidad de ejercitos <= que la cant de ejercitos con los que se ataco			
			if ( this->cantidadEjercitos <= 2  && this->cantidadEjercitos <= paisDefiende->getArmyCount()
			     && this->cantidadEjercitos <= gameManager->getAttack().getArmyCount() )
				
				defensaValida = true;
			else
				cout<<"CANTIDAD DE EJERCITOS DEFENSORES INVALIDA"<<endl;
		}
		else
			cout<<"DEFENSOR: TE ESTAS DEFENDIENDO CON UN PAIS TUYO QUE NO ES EL ATACADO"<<endl;
	}
	else
		cout<<"DEFENSOR: POR QUE INTENTAS DEFENDERTE CON UN PAIS QUE NO ES TUYO? ES INVALIDO."<<endl;
	
	
	return defensaValida;
}

void Defend::execute(ReferenceCountPtr<State>& state){
	
	state->defend(*this);
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
		

