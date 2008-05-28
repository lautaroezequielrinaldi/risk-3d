#include<sstream>
#include "attack.h"

Attack::Attack(std::vector<std::string> & parameterList, Mapa &mapa, Player& player):Command ( player, mapa )
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->paisAtacante = parameterList[0];
	this->paisAtacado = parameterList[1];
	this->cantidadEjercitos = atoi (parameterList[2].c_str() );
}

Attack::Attack(Mapa &mapa, Player& player, std::string xml):Command ( player, mapa ){

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
	
	
	// estructura que almacenara al xml proporcionado
	xmlTextReaderPtr reader;
	xmlChar *name, *value;
    int res;
    bool salir=false;
	std::string nomTag,s;
	int ej=0;
	int at=0;
	int at2 =0;
	
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
			if ( nomTag == "pais-atacante" && at==0){
				
				//acumulo 1 para que no vuelva a entrar al leer el tag de cierre
				at++;
				//avanzo al proximo nodo
				res = xmlTextReaderRead(reader);	
				// obtengo el valor
				value = xmlTextReaderValue(reader);
				
				//seteo el pais defensor
				this->paisAtacante.assign((char*)value);
			}
			else if ( nomTag == "pais-atacado" && at2==0){
				
				//acumulo 1 para que no vuelva a entrar al leer el tag de cierre
				at2++;
				//avanzo al proximo nodo
				res = xmlTextReaderRead(reader);	
				// obtengo el valor
				value = xmlTextReaderValue(reader);
				
				//seteo el pais defensor
				this->paisAtacado.assign((char*)value);
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


