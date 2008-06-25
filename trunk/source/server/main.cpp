#include "../common/net/sockets/socket.h"
#include "../common/model/gamemanager.h"
#include "../common/model/game.h"
#include "../common/model/randomdice.h"
#include "../common/model/turnmanager.h"
#include "../common/smartpointer/referencecountptr.h"
#include "../common/playerproxy.h"
#include "../common/state/statemachine.h"

#include <iostream>
//#include <vector>

int main (int argc, char** argv) {
	
	Dice *dado = new RandomDice();
	std::cerr<< "Dice created" << std::endl;

	ReferenceCountPtr<Game>        game       = new Game(*dado);
	std::cerr<< "Game created" << std::endl;

	ReferenceCountPtr<TurnManager> turnmanager= new TurnManager();
	std::cerr<< "TurnManager created" << std::endl;

	ReferenceCountPtr<GameManager> gamemanager= new GameManager(game,turnmanager);
	std::cerr<< "GameManager created" << std::endl;

	ReferenceCountPtr<StateMachine> stateMachine = new StateMachine(gamemanager);
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

	while (gamemanager->isOpen() ) {
		std::cerr<< "Accepting connection" << std::endl;
		playerProxy = new PlayerProxy(socket.accept(), gamemanager);
		std::cerr<< "Connection accepted" << std::endl;

		gamemanager->add(playerProxy);
		std::cerr<< "PlayerProxy added" << std::endl;

		playerProxy->start();
		std::cerr<< "PlayerProxy started" << std::endl;
	}

	while (gamemanager->isPlaying()) {
		// preguntarle a cada jugador si aun esta conectado, 
		// hacer join en los que no
	}

	// Hay que obtener la lista de jugadores para 
        //std::vector<ReferenceCountPtr<PlayerProxy> >::iterator playersProxyIterator;
/*        playersProxyIterator = gamemanager->players.begin();
        while( playersProxyIterator != gamemanager->players.end() ) {
		playerProxy->join();
		++playersProxyIterator;
	}
*/
	delete(dado);
	return 0;
}
