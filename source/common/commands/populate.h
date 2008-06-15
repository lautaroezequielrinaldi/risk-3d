#ifndef POPULATE_H_
#define POPULATE_H_

#include <vector>
#include "command.h"
#include "../model/gamemanager.h"

class Populate : public Command
{
	
	private:
	
		std::string paisDestino;
		int cantidadEjercitos;
	
	public:
	
		/*
		 * Constructor de la clase
		 */
		Populate(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		Populate(std::string xml);
		
		/*
		 * Destructor de la clase
		 */		
		~Populate();
		
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
		void execute(ReferenceCountPtr<State>& state);
		
		
};

#endif /*POPULATE_H_*/
