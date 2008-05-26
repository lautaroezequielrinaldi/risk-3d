#ifndef SERIALIZABLE_H_
#define SERIALIZABLE_H_

#include<string>
#include<libxml/parser.h> // Para definiciòn de la libreria libxml parser.
#include<libxml/tree.h> // Para definiciòn de la libreria libxml tree.
#include<libxml/xpath.h> // Para definiciòn de la libreria libxml xpath.
#include<libxml/xpathInternals.h> // Para definiciòn de la libreria libxml

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
		virtual void* hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName) = 0 ;
		
};

#endif /*SERIALIZABLE_H_*/
