#ifndef MOVE_H_
#define MOVE_H_

/**
 * client => server => client
 * server => client
 *
 * Comando que indica el movimiento de ejercitos entre paises.
 * Puede ser generado tanto por un cliente como por el servidor tras una batalla.
 */

#include <vector>
#include "command.h"

class Move : public Command
{
	
	private:
	
		std::string paisOrigen;
		std::string paisDestino;
		int cantidadEjercitos;

		int jugadorFrom;
		
	
	public:

		/*
		 * Constructor de la clase
		 */
		Move(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		Move(const std::string &xml);
		
		Move();
		/*
		 * Destructor de la clase
		 */		
		virtual ~Move();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(const std::string & xml);
		
		/** 
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		void execute(ReferenceCountPtr<State>& state);
		
		/**
		 * Metodo cuyo proposito es obtener el nombre del pais destino al cual se mueven ejercitos.
		 */
		 std::string getCountryDestination();
		 
		/**
		 * Metodo cuyo proposito es obtener el nombre del pais origen al cual se mueven ejercitos.
		 */
		std::string getCountryOrigin();

		/**
		 * Metodo cuyo proposito es obtener la cantidad de ejercitos a mover.
		 */
		int getArmyCount();

		virtual std::string getName();

		/**
		 * Metodo cuyo proposito es obtener el codigo del jugador que realizo el movimiento.
		 */
		int getMoverId();

		/**
		 * Notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer);		
};

#endif /*MOVE_H_*/
