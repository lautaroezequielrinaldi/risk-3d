#ifndef ARMYBONUSCALCULATOR_H_
#define ARMYBONUSCALCULATOR_H_

#include "gamemanager.h" // Para definiciòn de gameManager.
#include "turnmanager.h" // Para definicion de TurnManager 
#include "../smartpointer/referencecountptr.h" // Para definiciòn de ReferenceCountPtr

/**
 * Clase cuyo proposito es manejar los ejercitos bonus que son entregados a los jugadores
 */

class ArmyBonusCalculator
{
	private:
	
		/**
		 * Metodo cuyo proposito es obtener la cantidad de ejercitos bonus que se deben entregar a un jugador.
		 * El bonus se basa en la cantidad de paises conquistados por el jugador.
		 */
		int getArmyBonusPerCountry(ReferenceCountPtr<GameManager>& gameMAnager);
		
		/**
		 * Metodo cuyo proposito es obtener la cantidad de ejercitos bonus que se deben entregar a un jugador.
		 * El bonus se basa en la cantidad de continentes completos que posee.
		 */
		int getArmyBonusPerContinent(ReferenceCountPtr<GameManager>& gameMAnager);
	
	public:
	
		/**
		 * Constructor de la clase
		 */
		ArmyBonusCalculator();
	
		/**
		 * Destructor de la clase
		 */
		~ArmyBonusCalculator();
		
		/**
		 * Metodo cuyo proposito es obtener la cantidad de ejercitos bonus que se deben entregar al jugador que posee el turno.
		 * El bonus se basa en la cantidad de paises conquistados por el jugador y en la cantidad de continentes completos que posee.
		 */
		int getArmyBonus(ReferenceCountPtr<GameManager>& gameManager);
		
		
};

#endif /*ARMYBONUSCALCULATOR_H_*/
