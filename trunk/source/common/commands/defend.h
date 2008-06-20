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
		Defend(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		Defend(std::string xml);
		
		/*
		 * Destructor de la clase
		 */
		virtual ~Defend();

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
		
		std::string getDefenderdLand();
		
		int getArmyCount();
		
};

#endif /*DEFEND_H_*/


