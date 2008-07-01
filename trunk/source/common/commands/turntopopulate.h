#ifndef TURNTOPOPULATE_H_
#define TURNTOPOPULATE_H_

#include "command.h"
#include "../model/gamemanager.h"
#include <string>
#include <vector>

class TurnToPopulate : public Command
{
	
	private:
	
		int numeroJugador;

	public:
	
		
		/*
		 * Constructor de la clase.
		 * Recibe lista de parametros para crear el comando.
		 */
		TurnToPopulate(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		TurnToPopulate(const std::string & xml);
		

		TurnToPopulate();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~TurnToPopulate();
		
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

#endif /*TURNTOPOPULATE_H_*/
