#ifndef TURNMANAGER_H_
#define TURNMANAGER_H_

#include <vector>

/**
 * Clase cuyo proposito es manejar el orden de los turnos dentro del juego.
 */
class TurnManager
{
	
	private:
	
		/**
		 * Almacena el numero de color correspondiente al jugador que tiene el turno
		 */
		int jugadorActual;
	
		/**
		 * Almacena la cantidad de ejercitos bonus que posee el jugador actual
		 */
		int cantEjercitosBonus;


		/**
		 * Almacena el orden en que se le asignara el turno a cada jugador.
		 */
		std::vector<int> orden;
	
	public:
		
		/**
		 * Constructor de la clase
		 */
		TurnManager();
		
		/**
		 * Metodo cuyo proposito es establecer color que representa al jugador que comenzara la partida.
		 */
		void setTurnOrder(int firstPlayerColor);
		
		/**
		 * Metodo cuyo proposito es obtener el color de jugador que posee el turno.
		 */
		 int getCurrentPlayer();
		
		/**
		 * Metodo cuyo proposito es cambiar el turno actual al proximo jugador, respetando el orden seteado.
		 */
		void changeTurn();
		
		/**
		 * Metodo cuyo proposito es agregar un color que represente a un jugador al manejador de turnos.
		 */
		 void addPlayer(int color);
		 
		/**
		 * Metodo cuyo proposito es eliminar un color que represente a un jugador dentro del manejador de turnos.
		 * Si se desea eliminar al jugador que posee el turno, se lo eliminara luego de pasar el turno al proximo jugador.
		 */
		 void deletePlayer(int color);
		  
		
		/**
		 * Destructor de la clase
		 */
		~TurnManager();
		
	private:
		
		/**
		 * Metodo cuyo proposito es obtener el color de jugador que jugara luego del que posee el turno.
		 */
		int getNextPlayerTurn();	
		

		
};

#endif /*TURNMANAGER_H_*/
