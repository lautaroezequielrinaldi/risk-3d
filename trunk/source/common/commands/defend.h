#ifndef DEFEND_H_
#define DEFEND_H_

#include <vector>
#include "command.h"

class Defend : public Command
{
	
	private:
	
		std::string paisDefensor;
		int cantidadEjercitos;
	
	public:
		
		/*
		 * Constructor de la clase
		 */
		Defend(std::vector<std::string> &parameterList, Mapa &mapa, Player& player);
		/*
		 * Destructor de la clase
		 */
		~Defend();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar un archivo XML y construir un objeto a partir de el.
		 */
		void* hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName);
		
		/*Metodo cuyo proposito es validar la accion que realice el comando*/
		bool validate();
};

#endif /*DEFEND_H_*/


