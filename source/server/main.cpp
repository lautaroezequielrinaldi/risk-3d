#include "../common/net/sockets/socket.h"
#include "../common/model/gamemanager.h"
#include "../common/model/game.h"
#include "../common/model/turnmanager.h"
#include "../common/smartpointer/referencecountptr.h"
#include "playerproxy.h"

#include <iostream>
//#include <vector>

int main (int argc, char** argv) {
	// usamos este constructor pues aun no conocemos ni los jugadores ni el mapa
	ReferenceCountPtr<Game>        game       = new Game();

	ReferenceCountPtr<TurnManager> turnmanager= new TurnManager();

	ReferenceCountPtr<GameManager> gamemanager= new GameManager(game,turnmanager);

	gamemanager->prepare(gamemanager);

	Socket socket(2000,4);
	ReferenceCountPtr<PlayerProxy>  playerProxy;

	while (! gamemanager->isOpen() ) {
		playerProxy = new PlayerProxy(socket.accept(), gamemanager);
		gamemanager->add(playerProxy);
		playerProxy->start();
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
	return 0;
}
