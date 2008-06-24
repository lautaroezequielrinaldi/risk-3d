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
		 * Almacena color del primer jugador
		 */
		 int primerJugador;
		
		/**
		 * Almacena color del ultimo jugador de la ronda.
		 */
		 int ultimoJugador;
		
		/**
		 * Almacena el numero de color correspondiente al jugador secundario que comparte el turno
		 * con el jugador actual, al estar en estado de defensa.
		 */
		 int jugadorDefensor;
	
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


		void changeTurn(int color);
		
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
		 * Metodo cuyo proposito es verificar si existe un jugador en la lista de turnos.
		 */
		 bool isPlayerActive(int color);
		  
		 /**
		  * Metodo cuyo proposito es obtener el id del primer jugador de la ronda.
		  */
		  int getFirstPlayer(); 
		 
		 /**
		  * Metodo cuyo proposito es obtener id del ultimo jugador de la ronda .
		  */
		  int getLastPlayer();
		  
		  
		/**
		 * Metodo cuyo proposito es obtener el jugador que comparte el turno con el jugador actual ,
		 * jugador que se esta defendiendo.
		 */
		 int getDefenderPlayer();
		 
		/**
		 * Metodo cuyo proposito es establecer que jugador compartira el turno con el jugador actual
		 * para poder defenderse.
		 */
		 void setDefenderPlayer(int color);
		
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
