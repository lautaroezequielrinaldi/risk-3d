#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

class GameManager;
class CommandHydrator;
#include "../smartpointer/referencecountptr.h"

#include "game.h"
#include "turnmanager.h"
#include "player.h"
#include "../state/statemachine.h"
#include "../commands/attack.h"

#include "../playerproxy.h"
#include "../serverproxy.h"

class GameManager {
	
	private:
	
	ReferenceCountPtr<CommandHydrator> commandHydrator;

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
	* Inicialmente apunta a null, luego se le seteara el ataque.
	* No puede ser un ReferenceCountPtr ya que quien lo setea , lo hace con un *attack.
	* No puede ser una referencia al ataque ya que el ataque no existe al crearse el gameManager. 
	*/
	Attack *attack;
			
		
	bool open;

	bool playing;

	/**
	 * considerar utilizar un map para poder acceder individualmente
	 *
	 */
	std::list< ReferenceCountPtr<Proxy> > proxyList;

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


		void setStateMachine(ReferenceCountPtr<StateMachine>& stateMachine);

		ReferenceCountPtr<StateMachine>& getStateMachine();

		/**
		 *
		 *
		*/

		void add(ReferenceCountPtr<PlayerProxy> & playerproxy);	

		void add(ReferenceCountPtr<ServerProxy> & serverproxy);	

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
		 Attack& getAttack();
		 
		/**
		 * Metodo cuyo proposito es establecer un ataque.
		 */
		void setAttack(Attack & attack);
		
		bool isPlaying();

		bool isOpen();

		void notify(Command * command);

		void execute(std::string commandName, std::string commandXml);

		/**
		 * Metodo cuyo proposito es obtener la lista de jugadores.
		 */
		std::list< ReferenceCountPtr<Player> >& getPlayerList();
		
		/**
		 * Metodo cuyo proposito es obtener el estado actual del juego.
		 */
		ReferenceCountPtr<State> getCurrentState();
		 
		/**
		 * Metodo cuyo proposito es establecer el estado actual del juego.
		 */
		void setCurrentState( std::string stateName  );  
		
		
};


#endif /* __GAMEMANAGER_H__ */
