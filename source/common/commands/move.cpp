#include <sstream>
#include "move.h"

Move::Move(std::vector<std::string> &parameterList, Mapa &mapa, Player& player): Command ( player, mapa )
{
	this->paisOrigen = parameterList[0];
	this->paisDestino = parameterList[1];
	this->cantidadEjercitos = atoi( parameterList[2].c_str() );
	
}

Move::Move(Mapa &mapa, Player& player, std::string xml):Command ( player, mapa ){

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
	
		// estructura que almacenara al xml proporcionado
	xmlTextReaderPtr reader;
	xmlChar *name, *value;
    int res;
    bool salir=false;
	std::string nomTag,s;
	int ej=0;
	int orig=0;
	int dest =0;
	
	//lee de memoria el xml que llega por parametro y lo almacena en reader
    reader = xmlReaderForMemory(xml.c_str(),xml.size(), NULL,NULL, 0);
    
    if (reader != NULL) {
    	
    	// mueve el cursor dentro del stream reader parandose en el sig nodo- 
    	// devuelve 1 si hay nodo,0 si no hay mas nodods .
        res = xmlTextReaderRead(reader);
        
		//mientras haya nodos por leer y no haya seteado el objeto completo
       	while (res == 1 && !salir) {
        	
			//obtengo nombre del tag
		    name = xmlTextReaderName(reader);
		  
			nomTag.assign((char*)name);
			
			//si es el tag de pais-defensor
			if ( nomTag == "pais-origen" && orig==0){
				
				//acumulo 1 para que no vuelva a entrar al leer el tag de cierre
				orig++;
				//avanzo al proximo nodo
				res = xmlTextReaderRead(reader);	
				// obtengo el valor
				value = xmlTextReaderValue(reader);
				
				//seteo el pais defensor
				this->paisOrigen.assign((char*)value);
			}
			else if ( nomTag == "pais-destino" && dest==0){
				
				//acumulo 1 para que no vuelva a entrar al leer el tag de cierre
				dest++;
				//avanzo al proximo nodo
				res = xmlTextReaderRead(reader);	
				// obtengo el valor
				value = xmlTextReaderValue(reader);
				
				//seteo el pais defensor
				this->paisDestino.assign((char*)value);
			}
			else if ( nomTag == "cantidad-ejercitos" && ej==0 ){
				
				//acumulo 1 para que no vuelva a entrar al leer el tag de cierre
				ej++;
				//avanzo de  nodo
				res = xmlTextReaderRead(reader);	
				// obtengo el valor
				value = xmlTextReaderValue(reader);
				
				//seteo el valor en el objeto
			    this->cantidadEjercitos = atoi((char*)value);
			 	
			 	//para terminar el bucle y no seguir leyendo   
			    salir=true;
			}
						
		    res = xmlTextReaderRead(reader);
        }
        
    }
	
	xmlFree(name);
	xmlFree(value);
    xmlFreeTextReader(reader);
    xmlCleanupParser();

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

