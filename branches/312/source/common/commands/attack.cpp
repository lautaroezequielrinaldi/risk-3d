#include<sstream>
#include "attack.h"

Attack::Attack(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->paisAtacante = parameterList[0];
	this->paisAtacado = parameterList[1];
	this->cantidadEjercitos = atoi (parameterList[2].c_str() );
}

Attack::Attack(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

Attack::~Attack()
{
	//no realiza ninguna accion
}

std::string Attack::serialize(){
	
	std::string ataqueSeralizado;
	
	// creo documento
	xmlDocPtr docAtaque;
	// defino nodo raiz
	xmlNodePtr nodoAtaque;
	
	// defino nodos hijos de raiz
    xmlNodePtr nodoPaisAtaca;
    xmlNodePtr nodoPaisAtacado;
    xmlNodePtr nodoCantidadEjercitos;
    
    // creo xmlChar para persistir a una cadena de caracteres el xml
    xmlChar *xmlbuff;
    int buffersize;

    // creo documento
    docAtaque = xmlNewDoc(BAD_CAST "1.0");
    
    //seteo contenido del nodo raiz
    nodoAtaque = xmlNewNode(NULL, BAD_CAST "atacar");
    
    //seteo el nodo raiz del documento
    xmlDocSetRootElement(docAtaque, nodoAtaque);
    
    //seteo hijos de nodoAtaque: nodos pais-atacante y pais-atacado
    nodoPaisAtaca = xmlNewChild(nodoAtaque, NULL, BAD_CAST "pais-atacante",(const xmlChar*) this->paisAtacante.c_str() );
    nodoPaisAtacado = xmlNewChild(nodoAtaque, NULL, BAD_CAST "pais-atacado",(const xmlChar*) this->paisAtacado.c_str() );
   	
   	//conversion de entero a string para la cantidad de ejercitos
  	std::ostringstream strCantEjercitos;
   	strCantEjercitos << this->cantidadEjercitos;
   
   //seteo como hijo de nodoAtaque al nodo cantidad-ejercitos
    nodoCantidadEjercitos = xmlNewChild(nodoAtaque, NULL, BAD_CAST "cantidad-ejercitos",(const xmlChar*)(const xmlChar*)strCantEjercitos.str().c_str() );
    
    // dejo el document en un buffer
    xmlDocDumpFormatMemory(docAtaque, &xmlbuff, &buffersize, 1);
   
   /*seteo el string que se devolvera almacenando al XML*/
    ataqueSeralizado.assign((char*)xmlbuff);
	
	//libero memoria utilizada
    xmlFree(xmlbuff);
    xmlFreeDoc(docAtaque);
    xmlCleanupParser();
    
    return ataqueSeralizado;
  
}

void* Attack::hydrate(std::string xml){
	
	
	xmlDocPtr document;
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
	document = xmlParseMemory(xml.c_str(), xml.size());
	
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
	
	//si el pais atacante es del jugador actual
	if( jugadorActual->landOwner(this->paisAtacante) ){
	//si el pais defensor NO es del jugador actual
		if( !jugadorActual->landOwner(this->paisAtacado) ){	
			/*si pais atacante es adyacente al pais atacado*/
			if( paisAtaca->esAdyacente(this->paisAtacado)){
				/*si pais atacante ataca con 3 o menos ejercitos Y ataca con menos ejercitos de los que tiene*/
				if ( paisAtaca->getArmyCount() <= 3  && this->cantidadEjercitos < paisAtaca->getArmyCount() )
					ataqueValido = true;
			}
		}
	}
	return ataqueValido;
}

void Attack::execute(ReferenceCountPtr<State>& state){
	
	state->attack(*this);
	
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



