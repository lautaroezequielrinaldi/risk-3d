#ifndef __SETOWNER_H__
#define __SETOWNER_H__

/**
 * server => client
 *
 * Comando utilizado al comienzo del juego, tras una batalla o ante un abandono para setear la 
 * pertenencia de un pais
 */

#include <string>
#include <vector>
#include "command.h"
#include "../model/gamemanager.h"

class SetOwner : public Command
{
	
	
	public:
		
		/*
		 * Constructor de la clase
		 * la idea es que reciba una lista de parametros y con ellos arme el ataque que se validara, en ppio
		 * sera una lista de strings y en el caso de necesitar convertir un elemento a int usare atoi.
		 */
		SetOwner(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		SetOwner( std::string xml);
		

		SetOwner();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~SetOwner();
		
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
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);
		
		virtual std::string getName();
		
		
};

#endif /*__SETOWNER_H__*/
