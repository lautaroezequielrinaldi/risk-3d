#ifndef POPULATE_H_
#define POPULATE_H_

/**
 * client => server => client
 *
 * Comando para ubicar ejercitos al comienzo del turno
 */

#include <vector>
#include "command.h"
#include "../model/gamemanager.h"

class Populate : public Command
{
	
	private:
	
		std::string paisDestino;
		int cantidadEjercitos;

		int jugadorFrom;
	
	public:
	
		/*
		 * Constructor de la clase
		 */
		Populate(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		Populate(const std::string& xml);
		
		Populate();

		/*
		 * Destructor de la clase
		 */		
		virtual ~Populate();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(const std::string& xml);
		
		/**
		 * Metodo cuyo proposito es validar la accion de poblar un territorio.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameMAnager);

		
		/**
		 * Metodo cuyo proposito es validar la accion de ocupar un territorio vacio.
		 */
		bool validateOccupy(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		void execute(ReferenceCountPtr<State>& state);
		

		virtual std::string getName();

		/**
		 * Metodo cuyo proposito es obtener el nombre del pais destino que se poblara.
		 */
		 std::string getCountryDestination();
		 
		 /**
		  * Metodo cuyo proposito es obtener la cantidad de ejercitos a ubicar.
		  */
		  int getArmyCount();

		/**
		 * Metodo cuyo proposito es obtener el codigo del jugador que realizo el movimiento.
		 */
		int getMoverId();

};

	

#endif /*POPULATE_H_*/
