#ifndef ARMYBONUSCALCULATOR_H_
#define ARMYBONUSCALCULATOR_H_

#include "player.h"
#include "mapa.h"

/**
 * Clase cuyo proposito es manejar los ejercitos bonus que son entregados a los jugadores
 */

class ArmyBonusCalculator
{
	private:
	
		/*Referencia al jugador*/
		Player& jugador;
		
		/*Referencia al mapa sobre el que se desarrolla el juego*/
		Mapa& mapa;
		
		
		/**
		 * Metodo cuyo proposito es obtener la cantidad de ejercitos bonus que se deben entregar a un jugador.
		 * El bonus se basa en la cantidad de paises conquistados por el jugador.
		 */
		int getArmyBonusPerCountry();
		
		/**
		 * Metodo cuyo proposito es obtener la cantidad de ejercitos bonus que se deben entregar a un jugador.
		 * El bonus se basa en la cantidad de continentes completos que posee.
		 */
		int getArmyBonusPerContinent();
	
	public:
	
		/**
		 * Constructor de la clase
		 */
		ArmyBonusCalculator(Player& player, Mapa& map);
	
		/**
		 * Destructor de la clase
		 */
		~ArmyBonusCalculator();
		
		/**
		 * Metodo cuyo proposito es obtener la cantidad de ejercitos bonus que se deben entregar a un jugador.
		 * El bonus se basa en la cantidad de paises conquistados por el jugador y por la cantidad de continentes completos que posee.
		 */
		int getArmyBonus();
		
		
};

#endif /*ARMYBONUSCALCULATOR_H_*/
