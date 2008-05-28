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
		
		/**
		 * Constructor de la clase.
		 * La misma se construye sin valores, estos podran ser seteados desde un XML al hidratar el objeto.
		 */
		Defend(Mapa &mapa, Player& player, std::string xml);
		
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
		void* hydrate(std::string xml);
		
		/*Metodo cuyo proposito es validar la accion que realice el comando*/
		bool validate();
};

#endif /*DEFEND_H_*/


