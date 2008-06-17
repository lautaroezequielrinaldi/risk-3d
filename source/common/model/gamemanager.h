#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

class GameManager;

#include "game.h"
#include "turnmanager.h"
#include "../state/statemachine.h"
#include "../state/state.h"
#include "../smartpointer/referencecountptr.h"
#include "../commands/attack.h"
#include "../../server/playerproxy.h"


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
	* Almacena el estado del juego
	*/
	ReferenceCountPtr<StateMachine> stateMachine;
	
	/**
	* Almacena un ataque.
	*/
	ReferenceCountPtr<Attack> attack;
		
		
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
		 *
		 *
		*/
		void add(ReferenceCountPtr<PlayerProxy> & playerproxy);	

		/**
		 * Metodo cuyo proposito es obtener la partida que se esta jugando.
		 */
		 ReferenceCountPtr<Game>& getGame();
		
		/**
		 * Metodo cuyo proposito es obtener el manejador de turnos del juego.
		 */
		 ReferenceCountPtr<TurnManager>& getTurnManager();
		
		/**
		 * Metodo cuyo proposito es obtener el ataque almacenado.
		 */
		 ReferenceCountPtr<Attack>& getAttack();
		 
		 /**
		  * Metodo cuyo proposito es establecer un ataque.
		  */
		 void setAttack( ReferenceCountPtr<Attack>& attack);
		
};


#endif /* __GAMEMANAGER_H__ */
