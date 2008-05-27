#include<sstream>
#include "attack.h"

Attack::Attack(std::vector<std::string> & parameterList, Mapa &mapa, Player& player):Command ( player, mapa )
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->paisAtacante = parameterList[0];
	this->paisAtacado = parameterList[1];
	this->cantidadEjercitos = atoi (parameterList[2].c_str() );
}

Attack::~Attack()
{
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

void* Attack::hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName){
	
	
	return NULL;
}
		
bool Attack::validate(){
	
	bool ataqueValido=false;
	ReferenceCountPtr<Pais> paisAtaca = this->mapa.obtenerPais(this->paisAtacante);
	
	/*si pais atacante es adyacente al pais atacado*/
	if( paisAtaca->esAdyacente(this->paisAtacado)){
		/*si pais atacante ataca con 3 o menos ejercitos Y ataca con menos ejercitos de los que tiene*/
		if ( paisAtaca->getArmyCount() <= 3  && this->cantidadEjercitos < paisAtaca->getArmyCount() )
			ataqueValido = true;
	}
	
	return ataqueValido;
}


