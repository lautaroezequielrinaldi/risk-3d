#include <sstream>
#include "../model/armyBonusCalculator.h"
#include "populate.h"

Populate::Populate(std::vector<std::string> &parameterList, Mapa &mapa, Player& player) : Command (player,  mapa)
{
	this->paisDestino = parameterList[0];
	this->cantidadEjercitos = atoi( parameterList[1].c_str() );
}

Populate::~Populate()
{
}

std::string Populate::serialize(){
	
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

void* Populate::hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName){
	
	
	return NULL;
}
		
bool Populate::validate(){
	
	/*creo un calculador de ejercitos extras correspondientes el jugador para verificar que no use mas de los debidos*/
	ArmyBonusCalculator calculadorBonus(this->jugador, this->mapa);
	
	if (this->cantidadEjercitos <= calculadorBonus.getArmyBonus() )
		return true;
	else
		return false;
	
}

