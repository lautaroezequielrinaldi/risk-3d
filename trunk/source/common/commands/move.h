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
		Move(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		Move(std::string xml);
		
		/*
		 * Destructor de la clase
		 */		
		~Move();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(std::string xml);
		
		/** 
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameMAnager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		void excute(ReferenceCountPtr<GameManager>& gameMAnager);
		
};

#endif /*MOVE_H_*/
