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
		 * Metodo cuyo proposito es obtener el nombre del comando.
		 */
		virtual std::string getName();

		/**
		 * Notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer);		
};

#endif /*TURNTOPOPULATE_H_*/
