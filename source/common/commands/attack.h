#ifndef ATTACK_H_
#define ATTACK_H_

#include <string>
#include <vector>
#include "command.h"
//#include "../model/gamemanager.h"

class Attack : public Command
{
	
	private:
	
		std::string paisAtacante;
		std::string paisAtacado;
		int cantidadEjercitos;
	
	public:
		
		/*
		 * Constructor de la clase
		 * la idea es que reciba una lista de parametros y con ellos arme el ataque que se validara, en ppio
		 * sera una lista de strings y en el caso de necesitar convertir un elemento a int usare atoi.
		 */
		Attack(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		Attack( std::string xml);
		
		/*
		 * Destructor de la clase
		 */
		 
		~Attack();
		
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
		void execute(ReferenceCountPtr<GameManager>& gameMAnager);
		
		
		
		std::string getAttackerLand();
		
		std::string getAttackedLand();
		
		int getArmyCount();
		
		
};

#endif /*ATTACK_H_*/
