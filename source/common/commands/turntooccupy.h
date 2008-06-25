#ifndef __TURNTOOCCUPY_H__
#define __TURNTOOCCUPY_H__

/**
 * server => client
 *
 * Indicacion del servidor de pasaje a estado Ocupying
 * hay que ver que pasa con Populating...
 */

#include <string>
#include <vector>
#include "command.h"
#include "../model/gamemanager.h"

class TurnToOccupy : public Command
{
	
	
	public:
		
		/*
		 * Constructor de la clase
		 * la idea es que reciba una lista de parametros y con ellos arme el ataque que se validara, en ppio
		 * sera una lista de strings y en el caso de necesitar convertir un elemento a int usare atoi.
		 */
		TurnToOccupy(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		TurnToOccupy( std::string xml);
		

		TurnToOccupy();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~TurnToOccupy();
		
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

#endif /*__TURNTOOCCUPY_H__*/