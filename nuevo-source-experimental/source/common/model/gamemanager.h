#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

class GameManager;
class CommandHydrator;
class UICommand;

#include "../smartpointer/referencecountptr.h"


#include "game.h"
#include "turnmanager.h"
#include "player.h"
#include "../state/stateobservable.h"
#include "../state/statemachine.h"
#include "../commands/commandobservable.h"
#include "../thread/mutex.h"

//#include "../Servercommands/serverattack.h"
//
class ServerAttack;

#include "../net/playerproxy.h"

class GameManager: public StateObservable, public CommandObservable {
	
	private:
	
		static const unsigned int CAPACIDAD_MAXIMA=3;

		
		ReferenceCountPtr<CommandHydrator> commandHydrator;

		/**
		* Almacena el juego.
		*/
		ReferenceCountPtr<Game> game;
		
		/**
		* Almacena el manejador de turnos.
			* (valido en el contexto del server)
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
		 * (valido en el contexto del server)
		*/
		ServerAttack *attack;
			
		/**
		 * Hay lugar aun para conectarse?
		 * (valido en el contexto del server)
		 */
		bool open;

		/**
		 * Ya comenzo el juego?
		 * (valido en el contexto del server)
		 */
		bool playing;


		bool waitingPlay;

		/**
		 * Quien soy
		 * (valido en el contexto del player)
		 */
		int me;
	
		/**
		 * considerar utilizar un map para poder acceder individualmente
		 *
		 */
		std::list< ReferenceCountPtr<Proxy> > proxyList;
		
		/**
		 * Para poder lockear el thread en ejecucion.
		 */
		 Mutex mutex;

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
		 ServerAttack& getAttack();
		 
		/**
		 * Metodo cuyo proposito es establecer un ataque.
		 */
		void setAttack(ServerAttack & attack);
		
		/**
		 * Metodo cuyo proposito es obtener la capacidad maxima del juego.
		 */
		const unsigned int getGameCapacity();
		
		/**
		 * Metodo cuyo proposito es verificar si el servidor esta en estado de juego.
		 */
		bool isPlaying();

		/**
		 * Metodo cuyo proposito es verificar si el servidor esta abierto a aceptar nuevas conexiones para el juego.
		 */
		bool isOpen();
		
		/**
		 * Metodo cuyo proposito es verificar si el servidor paso la etapa de aceptar conexiones
		 * para el juego y esta esperando que todos los jugadores conectados esten listos para jugar.
		 */
		bool isWaitingPlay();
		
		void setWaitingPlay(bool state);
		
		void setPlaying(bool state);		

		void setMe(int me);

		int getMe();

		void notify(Command * command);

		void execute(const std::string & commandName,const std::string & commandXml);

		ReferenceCountPtr<PlayerProxy> getPlayerProxy(int color);
		/**
		 * Metodo cuyo proposito es obtener la lista de jugadores.
		 */
		std::list< ReferenceCountPtr<Player> >& getPlayerList();
		
		std::list< ReferenceCountPtr<Proxy> >& getPlayerProxyList();
		
		/**
		 * Metodo cuyo proposito es obtener el estado actual del juego.
		 */
		ReferenceCountPtr<State> getCurrentState();
		 
		/**
		 * Metodo cuyo proposito es establecer el estado actual del juego.
		 */
		void setCurrentState( std::string stateName  );  
		
		void remove(int color);
};


#endif /* __GAMEMANAGER_H__ */
