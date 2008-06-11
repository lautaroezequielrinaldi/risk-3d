#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "game.h"
#include "turnmanager.h"
//#include "state.h"
#include "../smartpointer/referencecountptr.h" // Para definiciòn de ReferenceCountPtr.

class GameManager
{
	
	private:
	
		/**
         * Almacena el juego.
         */
        ReferenceCountPtr<Game> game;
        
        /**
         * Almacena el manejador de turnos.
         */
        ReferenceCountPtr<TurnManager> turnManager;
	
		/**
		 * Almacena es estado del juego
		 */
		 //Aca iria la referencia al estado
	
	
	public:
	
		/**
		 * Constructor de la clase
		 */
		GameManager();
		
		/**
		 * Constructor de la clase
		 */
		 GameManager( ReferenceCountPtr<Game>& game,ReferenceCountPtr<TurnManager>& turnManager);
		
		
		/**
		 * Destructor de la clase
		 */
		~GameManager();
		
		/**
		 * Metodo cuyo proposito es obtener la partida que se esta jugando.
		 */
		 ReferenceCountPtr<Game>& getGame();
		
		/**
		 * Metodo cuyo proposito es obtener el manejador de turnos del juego.
		 */
		 ReferenceCountPtr<TurnManager>& getTurnManager();
		
};

#endif /*GAMEMANAGER_H_*/
