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
	
	private:
		int numeroJugador;
	
	public:
		
		/*
		 * Constructor de la clase
		 * Recibe lista de parametros para crear el comando.
		 */
		TurnToOccupy(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		TurnToOccupy(const std::string& xml);
		

		TurnToOccupy();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~TurnToOccupy();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un string.
		 */
		std::string serialize();

		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);
		
		/**
		 * Metodo cuyo proposito es obtener el nombre del comando.
		 */
		virtual std::string getName();
		
		
};

#endif /*__TURNTOOCCUPY_H__*/
