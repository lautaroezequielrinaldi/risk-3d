#ifndef ATTACK_H_
#define ATTACK_H_

#include <string>
#include <vector>
#include "command.h"

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
		Attack(std::vector<std::string> &parameterList, Mapa &mapa);
		/*
		 * Destructor de la clase
		 */
		 
		~Attack();
		
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

#endif /*ATTACK_H_*/