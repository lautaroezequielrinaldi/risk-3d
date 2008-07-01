#include<sstream>
#include "attack.h"

#include<iostream>

using namespace std;

Attack::Attack(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->paisAtacante = parameterList[0];
	this->paisAtacado = parameterList[1];
	this->cantidadEjercitos = atoi (parameterList[2].c_str() );
	this->jugadorAtacante = atoi (parameterList[3].c_str() );
	this->jugadorDefensor = atoi (parameterList[4].c_str() );
}

Attack::Attack(const std::string & xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

Attack::Attack(){

}

Attack::~Attack()
{
	//no realiza ninguna accion
}

std::string Attack::serialize(){

	std::string ataqueSeralizado;


	//conversion de entero a string para la cantidad de ejercitos
  	std::ostringstream strCantEjercitos;
   	strCantEjercitos << this->cantidadEjercitos;

	ataqueSeralizado = "<?xml version=\"1.0\"?><atacar>";
	
	std::string xmlComando = Command::serialize(this->jugadorAtacante, this->jugadorDefensor);

	std::string xmlAttack = "<pais-atacante>"+this->paisAtacante+"</pais-atacante><pais-atacado>"+this->paisAtacado
				+"</pais-atacado><cantidad-ejercitos>"+strCantEjercitos.str()+"</cantidad-ejercitos></atacar>";

	ataqueSeralizado += xmlComando + xmlAttack;

    return ataqueSeralizado;
  
}

void* Attack::hydrate(const std::string& xml){
	
	
	xmlDocPtr document = hydrateCommon(xml);
	xmlNodePtr nodoRaiz;
    
    xmlChar* paisAtacan;
	xmlChar* paisAtacad;
	xmlChar* cantE;
    
    // Defino un contexto de XPath.
    xmlXPathContextPtr contextoXPath;
    // Defino 2 objetos de XPath.
    xmlXPathObjectPtr objetoXPathPaisAtacad,objetoXPathPaisAtacan, objetoXPathEjer ;
    // Defino el set de nodos devueltos por la expresiòn XPath.(una estructura que tiene un array con los nodos
    //devueltos por la expresion y el numero de nodos.
    xmlNodeSetPtr setNodoAtacar;

	//parseo el xml en memoria y se construye el arbol
	//document = xmlParseMemory(xml.c_str(), xml.size());
	
	// Obtengo el elemento root del documento XML sobre el cual se va a trabajar.
    nodoRaiz = xmlDocGetRootElement(document);

    // Creo el contexto de XPath.
    contextoXPath = xmlXPathNewContext(document);


	 // Evaluo la expresiòn XPath para pais origen
    objetoXPathPaisAtacan = xmlXPathEvalExpression(BAD_CAST "//atacar/pais-atacante", contextoXPath);

	// Obtengo el set de nodos de paises.
    setNodoAtacar = objetoXPathPaisAtacan->nodesetval;

    //nodeNr = cantidad de nodos que devolvio la expresion xpath - nodeTab = array de nodos devulto
    // Obtengo el nodo del pais actual.
	xmlNodePtr nodoAtacante = setNodoAtacar->nodeTab[0];

	// Obtengo el nombre del pais que defiende y lo seteo en objeto.
	paisAtacan = xmlNodeGetContent(nodoAtacante);
	this->paisAtacante.assign( (char*) paisAtacan );
	

	// Evaluo la expresiòn XPath para pais destino
    objetoXPathPaisAtacad = xmlXPathEvalExpression(BAD_CAST "//atacar/pais-atacado", contextoXPath);

	// Obtengo el set de nodos de paises.
    setNodoAtacar = objetoXPathPaisAtacad->nodesetval;

    //nodeNr = cantidad de nodos que devolvio la expresion xpath - nodeTab = array de nodos devulto
    // Obtengo el nodo del pais actual.
	xmlNodePtr nodoAtacado = setNodoAtacar->nodeTab[0];

	// Obtengo el nombre del pais que defiende y lo seteo en objeto.
	paisAtacad = xmlNodeGetContent(nodoAtacado);
	this->paisAtacado.assign( (char*) paisAtacad );

	
	// Evaluo la expresiòn XPath para la cantidad de ejercitos
    objetoXPathEjer = xmlXPathEvalExpression(BAD_CAST "//atacar/cantidad-ejercitos",  contextoXPath);

    // Obtengo el set de nodos.
    setNodoAtacar = objetoXPathEjer->nodesetval;

    //nodeNr = cantidad de nodos que devolvio la expresion xpath
    //nodeTab = array de nodos devulto
	// Obtengo el nodo de la cantidad de ejercitos actual
	xmlNodePtr nodoCantEj = setNodoAtacar->nodeTab[0];

	// Obtengo cantidad de ejercitos y la seteo en objeto
    cantE = xmlNodeGetContent(nodoCantEj);
    
    this->cantidadEjercitos = atoi((char*) cantE );

	
	/*libero recursos*/

	xmlFree(paisAtacan);
	xmlFree(paisAtacad);
	xmlFree (cantE );
	
	xmlXPathFreeObject(objetoXPathPaisAtacad);
	xmlXPathFreeObject(objetoXPathPaisAtacan);
	xmlXPathFreeObject(objetoXPathEjer);
	
	xmlXPathFreeContext(contextoXPath);

    xmlFreeDoc(document);

    xmlCleanupParser();
	
	return NULL;
;
	
}
		
bool Attack::validate(ReferenceCountPtr<GameManager>& gameManager){
	
	bool ataqueValido=false;
	ReferenceCountPtr<Game> game = gameManager->getGame();
	ReferenceCountPtr<Mapa> map = game->getMapa();
	ReferenceCountPtr<Pais> paisAtaca =	map->obtenerPais(this->paisAtacante);
	ReferenceCountPtr<TurnManager> turnManager = gameManager->getTurnManager();
	ReferenceCountPtr<Player> jugadorActual = game->getPlayer( turnManager->getCurrentPlayer());
	
	std::string paisAt = this->paisAtacante;
	std::string paisAtacad = this->paisAtacado;
	
	//si el pais atacante es del jugador actual
	if( jugadorActual->landOwner(paisAt) ){
	//si el pais defensor NO es del jugador actual
		if( !jugadorActual->landOwner(paisAtacad) ){	
			/*si pais atacante es adyacente al pais atacado*/
			if( paisAtaca->esAdyacente(this->paisAtacado)){
				/*si pais atacante ataca con 3 o menos ejercitos Y ataca con menos ejercitos de los que tiene*/
				if ( this->cantidadEjercitos <= 3  && this->cantidadEjercitos < paisAtaca->getArmyCount() )
					ataqueValido = true;
				else
					cerr<<"CANTIDAD DE EJERCITOS ATACANTES ( "<<this->cantidadEjercitos<<" ) INVALIDA -"<<paisAtaca->getArmyCount()<<endl;
			}
			else
				cerr<<"EL PAIS QUE ATACA NO ES ADYACENTE AL ATACADO"<<endl;
		}
		else
			cerr<<"ESTA INTENTANDO ATACAR UN PAIS SUYO"<<endl;
	}
	else
		cerr<<"EL PAIS CON EL QUE INTENTA ATACAR NO ES DEL JUGADOR ACTUAL"<<endl;
	
	
	
	return ataqueValido;
}

void Attack::execute(ReferenceCountPtr<State>& state){
	
	state->attack(*this);
	
}

std::string Attack::getName() {
	return "attack";
}

std::string Attack::getAttackerLand(){
	return this->paisAtacante;
}
		
std::string Attack::getAttackedLand(){
	return this->paisAtacado;
}

int Attack::getArmyCount(){
	return this->cantidadEjercitos;
}

int Attack::getAttackerId(){
	return this->jugadorAtacante;
}

int Attack::getAttackedId(){
	return this->jugadorDefensor;
}



