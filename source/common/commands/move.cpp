#include <sstream>
#include "move.h"

Move::Move(std::vector<std::string> &parameterList): Command ()
{
	this->paisOrigen = parameterList[0];
	this->paisDestino = parameterList[1];
	this->cantidadEjercitos = atoi( parameterList[2].c_str() );
	
}

Move::Move(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

Move::~Move()
{
}

std::string Move::serialize(){

	std::string movimientoSeralizado;
	
	// creo documento
	xmlDocPtr docMovimiento;
	// defino nodo raiz
	xmlNodePtr nodoMovimiento;
	
	// defino nodos hijos de raiz
    xmlNodePtr nodoPaisOrigen;
    xmlNodePtr nodoPaisDestino;
    xmlNodePtr nodoCantidadEjercitos;
    
    // creo xmlChar para persistir a una cadena de caracteres el xml
    xmlChar *xmlbuff;
    int buffersize;

    // creo documento
    docMovimiento = xmlNewDoc(BAD_CAST "1.0");
    
    //seteo contenido del nodo raiz
    nodoMovimiento = xmlNewNode(NULL, BAD_CAST "mover");
    
    //seteo el nodo raiz del documento
    xmlDocSetRootElement(docMovimiento, nodoMovimiento);
    
    //seteo hijos de nodoMovimiento: nodos pais-origen y pais-destino
    nodoPaisOrigen = xmlNewChild(nodoMovimiento, NULL, BAD_CAST "pais-origen",(const xmlChar*) this->paisOrigen.c_str() );
    nodoPaisDestino = xmlNewChild(nodoMovimiento, NULL, BAD_CAST "pais-destino",(const xmlChar*) this->paisDestino.c_str() );
   	
   	//conversion de entero a string para la cantidad de ejercitos
  	std::ostringstream strCantEjercitos;
   	strCantEjercitos << this->cantidadEjercitos;
   
   //seteo como hijo de nodoMovimiento al nodo cantidad-ejercitos
    nodoCantidadEjercitos = xmlNewChild(nodoMovimiento, NULL, BAD_CAST "cantidad-ejercitos",(const xmlChar*)(const xmlChar*)strCantEjercitos.str().c_str() );
    
    // dejo el document en un buffer
    xmlDocDumpFormatMemory(docMovimiento, &xmlbuff, &buffersize, 1);
   
   /*seteo el string que se devolvera almacenando al XML*/
    movimientoSeralizado.assign((char*)xmlbuff);
	
	//libero memoria utilizada
    xmlFree(xmlbuff);
    xmlFreeDoc(docMovimiento);
    xmlCleanupParser();
    
    return movimientoSeralizado;
	
}

void* Move::hydrate(std::string xml){
	
	
	xmlDocPtr document;
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
	document = xmlParseMemory(xml.c_str(), xml.size());
	
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
		
bool Move::validate(ReferenceCountPtr<GameManager>& gameMAnager){
	
	bool movimValido=false;
	ReferenceCountPtr<Game> game = gameMAnager->getGame();
	ReferenceCountPtr<Mapa> map = game->getMapa();
	ReferenceCountPtr<Pais> paisO = map->obtenerPais(this->paisOrigen);
	
	/*si pais origen es adyacente al pais destino*/
	if( paisO->esAdyacente(this->paisDestino)){
		/*si la cantidad de ejercitos a mover es menor a la cantidad de ejercitos que tiene el pais origen*/
		if ( this->cantidadEjercitos < paisO->getArmyCount() )
			movimValido = true;
	}
	
	return movimValido;
	
}

void  Move::execute(ReferenceCountPtr<GameManager>& gameMAnager){
	
	
}



