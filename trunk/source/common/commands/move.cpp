#include <sstream>

#include "move.h"

Move::Move(std::vector<std::string> &parameterList, Mapa &mapa, Player& player): Command ( player, mapa )
{
	this->paisOrigen = parameterList[0];
	this->paisDestino = parameterList[1];
	this->cantidadEjercitos = atoi( parameterList[2].c_str() );
	
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
    nodoMovimiento = xmlNewNode(NULL, BAD_CAST "ataque");
    
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

void* Move::hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName){
	
	
	return NULL;
}
		
bool Move::validate(){
	
	bool movimValido=false;
	ReferenceCountPtr<Pais> paisO = this->mapa.obtenerPais(this->paisOrigen);
	
	/*si pais origen es adyacente al pais destino*/
	if( paisO->esAdyacente(this->paisDestino)){
		/*si la cantidad de ejercitos a mover es menor a la cantidad de ejercitos que tiene el pais origen*/
		if ( this->cantidadEjercitos < paisO->getArmyCount() )
			movimValido = true;
	}
	
	return movimValido;
	
}

