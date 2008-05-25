#ifndef POPULATE_H_
#define POPULATE_H_

#include <vector>
#include "command.h"

class Populate : public Command
{
	
	public:
	
		/*
		 * Constructor de la clase
		 */
		Populate(std::vector<std::string> &parameterList, Mapa &mapa);
		/*
		 * Destructor de la clase
		 */		
		~Populate();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string& serialize();
		/**
		 * Metodo cuyo proposito es hidratar un archivo XML y construir un objeto a partir de el.
		 */
		void* hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName);
		
		/*Metodo cuyo proposito es validar la accion que realice el comando*/
		bool validate();
		
		
};

#endif /*POPULATE_H_*/
