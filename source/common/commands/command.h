#ifndef COMMAND_H_
#define COMMAND_H_

#include "../parser/serializable.h"
#include "../model/mapa.h"
#include "../model/player.h"

/**
 * Clase abstracta cuyo proposito es brindar la interfaz de un comando serializable.
 */ 
class Command : public Serializable
{
	
	protected:
		
		/**
		 * Referencia al jugador que posee el turno
		 */
		Player& jugador;
		
		/**
		 * Referencia al mapa del juego
		 */
		Mapa &mapa;
		

		
	public:
		
		/*
		 * Constructor de la clase
		 */
		Command(Player& player, Mapa &map);
		/*
		 * Destructor de la clase
		 */
		virtual ~Command();
		
		/*Metodo cuyo proposito es validar la accion que realice el comando*/
		virtual bool validate()=0;
		
};

#endif /*COMMAND_H_*/
