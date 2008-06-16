#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_


#include "game.h"
#include "turnmanager.h"
#include "../state/statemachine.h"
#include "../state/state.h"
#include "../smartpointer/referencecountptr.h" // Para definiciòn de ReferenceCountPtr.


class ProxyPlayer;
class Attack;
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
		void add(ReferenceCountPtr<ProxyPlayer> proxyplayer);		

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

#include "../commands/attack.h"
#include "../../server/proxyplayer.h"

#endif /*GAMEMANAGER_H_*/
