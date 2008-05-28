#include <sstream>
#include "../model/armyBonusCalculator.h"
#include "populate.h"

Populate::Populate(std::vector<std::string> &parameterList, Mapa &mapa, Player& player) : Command (player,  mapa)
{
	this->paisDestino = parameterList[0];
	this->cantidadEjercitos = atoi( parameterList[1].c_str() );
}

Populate::Populate(Mapa &mapa, Player& player, std::string xml):Command ( player, mapa ){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
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

void* Populate::hydrate(std::string xml){
	
	// estructura que almacenara al xml proporcionado
	xmlTextReaderPtr reader;
	xmlChar *name, *value;
    int res;
    bool salir=false;
	std::string nomTag,s;
	int ej=0;
	int dest=0;
	
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
			if ( nomTag == "pais-destino" && dest==0){
				
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
		
bool Populate::validate(){
	
	/*creo un calculador de ejercitos extras correspondientes el jugador para verificar que no use mas de los debidos*/
	ArmyBonusCalculator calculadorBonus(this->jugador, this->mapa);
	
	if (this->cantidadEjercitos <= calculadorBonus.getArmyBonus() )
		return true;
	else
		return false;
	
}

