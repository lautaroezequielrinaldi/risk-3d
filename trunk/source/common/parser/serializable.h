#ifndef SERIALIZABLE_H_
#define SERIALIZABLE_H_

#include<string>
#include<libxml/parser.h> 
#include<libxml/tree.h> 
#include<libxml/xpath.h> 
#include<libxml/xpathInternals.h> 
#include<libxml/xmlreader.h> 

#include "../smartpointer/referencecountptr.h"
#include "../model/mapa.h"


/**
 * Clase abstracta cuyo proposito es brindar una interfaz para la  serializacion e hidratacion de objetos.
 */
class Serializable
{
	
	public:
		
		/*
		 * Constructor de la clase
		 */
		Serializable();
		
		/*
		 * Destructor de la clase
		 */
		virtual ~Serializable();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		virtual std::string serialize() = 0;
		/**
		 * Metodo cuyo proposito es hidratar un archivo XML y construir un objeto a partir de el.
		 */
		virtual void* hydrate(std::string xml) = 0 ;
		
};

#endif /*SERIALIZABLE_H_*/
