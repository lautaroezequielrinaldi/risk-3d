#ifndef MOVE_H_
#define MOVE_H_

#include <vector>
#include "command.h"

class Move : public Command
{
	
	private:
	
		std::string paisOrigen;
		std::string paisDestino;
		int cantidadEjercitos;
	
	public:

		/*
		 * Constructor de la clase
		 */
		Move(std::vector<std::string> &parameterList, Mapa &mapa, Player& player);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye sin valores, estos podran ser seteados desde un XML al hidratar el objeto.
		 */
		Move(Mapa &mapa, Player& player, std::string xml);
		
		/*
		 * Destructor de la clase
		 */		
		~Move();

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

#endif /*MOVE_H_*/
