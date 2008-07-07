#include "../common/net/sockets/socket.h"
#include "../common/model/gamemanager.h"
#include "../common/model/game.h"
#include "../common/model/randomdice.h"
#include "../common/model/turnmanager.h"
#include "../common/smartpointer/referencecountptr.h"
#include "../common/net/playerproxy.h"
#include "../common/state/serverstatemachine.h"
#include "../common/commands/noroom.h"

#include <iostream>
//#include <vector>

int main (int argc, char** argv) {

try {	
	RandomDice dado;
	std::cerr<< "Dice created" << std::endl;

	ReferenceCountPtr<Game>        game       = new Game(dado);
	std::cerr<< "Game created" << std::endl;

	ReferenceCountPtr<TurnManager> turnmanager= new TurnManager();
	std::cerr<< "TurnManager created" << std::endl;

	ReferenceCountPtr<GameManager> gamemanager= new GameManager(game,turnmanager);
	std::cerr<< "GameManager created" << std::endl;

	ReferenceCountPtr<StateMachine> stateMachine = new ServerStateMachine(gamemanager);
	std::cerr<< "StateMachine created" << std::endl;

	stateMachine->setState("waitingFirstPlayer");
	std::cerr<< "StateMachine initialized" << std::endl;

	gamemanager->setStateMachine(stateMachine);
	std::cerr<< "StateMachine asigned" << std::endl;

	// deshardcodear 2000
	Socket socket(2000,4);
	std::cerr<< "Socket created" << std::endl;

	ReferenceCountPtr<PlayerProxy>  playerProxy;
	std::cerr<< "PlayerProxy created" << std::endl;

	//mientras no se llegue a la cantidad maxima de jugadores se aceptan nuevas conexiones que perduraran
	while (gamemanager->isOpen() ) {
		
		std::cerr<< "Accepting connection" << std::endl;
		playerProxy = new PlayerProxy(socket.accept(), gamemanager);
		std::cerr<< "Connection accepted" << std::endl;

		gamemanager->add(playerProxy);
		std::cerr<< "PlayerProxy added" << std::endl;

		playerProxy->start();
		std::cerr<< "PlayerProxy started" << std::endl;
	}

	std::cerr<<"Capacidad para jugar completa....."<<std::endl;

	// cuando se haya completado la cantidad maxima de jugadores:
	//mientras no esten listos para jugaro los conectados
	while( gamemanager->isWaitingPlay() ){
		
		std::cerr<< "Accepting connection - pero.. juego completo" << std::endl;
		
		//se acepta una conexion para notificar que el juego esta completo, luego sera eliminada.
		playerProxy = new PlayerProxy(socket.accept(), gamemanager);
		
		NoRoom *noRoom = new NoRoom();
		
		std::string mje = "Lo siento, no hay mas lugar en la sala, intenta luego";
		noRoom->setTo(0);//gamemanager->getGameCapacity() );
		noRoom->setMainMsg(mje);
		
		playerProxy->notify(*noRoom);
		delete(noRoom);
		
		
		std::cerr<< "Esperando que todos los jugadores esten ready to play......" << std::endl;
	}

	while (gamemanager->isPlaying()) {
		
		std::cerr<< "ESTAMOS JUGANDO" << std::endl;
		
		// preguntarle a cada jugador si aun esta conectado, 
		// hacer join en los que no
	}

} catch (SocketConnectionException& exception) {
	std::cerr << exception.what() << std::endl;
} catch (...) {
	std::cerr << "default exception"<< std::endl;
}



	// Hay que obtener la lista de jugadores para 
        //std::vector<ReferenceCountPtr<PlayerProxy> >::iterator playersProxyIterator;
/*        playersProxyIterator = gamemanager->players.begin();
        while( playersProxyIterator != gamemanager->players.end() ) {
		playerProxy->join();
		++playersProxyIterator;
	}
*/
	return 0;
}

