#include<sstream>
#include "defend.h"


Defend::Defend(std::vector<std::string> &parameterList, Mapa &mapa, Player& player) : Command (player, mapa)
{
	this->paisDefensor = parameterList[0];
	this->cantidadEjercitos = atoi ( parameterList[1].c_str() );
	
}

Defend::Defend(Mapa &mapa, Player& player, std::string xml):Command ( player, mapa ){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
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

void* Defend::hydrate(std::string xml){
	
	// estructura que almacenara al xml proporcionado
	xmlTextReaderPtr reader;
	xmlChar *name, *value;
    int res;
    bool salir=false;
	std::string nomTag,s;
	int ej=0;
	int def=0;
	
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
			if ( nomTag == "pais-defensor" && def==0){
				
				//acumulo 1 para que no vuelva a entrar al leer el tag de cierre
				def++;
				//avanzo al proximo nodo
				res = xmlTextReaderRead(reader);	
				// obtengo el valor
				value = xmlTextReaderValue(reader);
				
				//seteo el pais defensor
				this->paisDefensor.assign((char*)value);
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
		
bool Defend::validate(){
	
	bool defensaValida = false;
	ReferenceCountPtr<Pais> paisDefiende = this->mapa.obtenerPais(this->paisDefensor);
	
	/*si pais atacante defiende con 2 o menos ejercitos Y defiende con menos ejercitos de los que tiene*/
	if ( paisDefiende->getArmyCount() <= 2  && this->cantidadEjercitos < paisDefiende->getArmyCount() )
		defensaValida = true;
	
	return defensaValida;
}

