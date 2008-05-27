#include<sstream>
#include "defend.h"

Defend::Defend(std::vector<std::string> &parameterList, Mapa &mapa, Player& player) : Command (player, mapa)
{
	this->paisDefensor = parameterList[0];
	this->cantidadEjercitos = atoi ( parameterList[1].c_str() );
	
}

Defend::~Defend()
{
}

std::string Defend::serialize(){
	
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

void* Defend::hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName){
	
	
	return NULL;
}
		
bool Defend::validate(){
	
	bool defensaValida = false;
	ReferenceCountPtr<Pais> paisDefiende = this->mapa.obtenerPais(this->paisDefensor);
	
	/*si pais atacante defiende con 2 o menos ejercitos Y defiende con menos ejercitos de los que tiene*/
	if ( paisDefiende->getArmyCount() <= 2  && this->cantidadEjercitos < paisDefiende->getArmyCount() )
		defensaValida = true;
	
	return defensaValida;
}

