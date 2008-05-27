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
		void* hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName);
		
		/*Metodo cuyo proposito es validar la accion que realice el comando*/
		bool validate();
		
};

#endif /*MOVE_H_*/
