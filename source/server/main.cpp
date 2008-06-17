#include "../common/net/sockets/socket.h"
#include "../common/model/gamemanager.h"
#include "../common/smartpointer/referencecountptr.h"
#include "playerproxy.h"

#include <iostream>
#include <vector>

int main (int argc, char** argv) {
	ReferenceCountPtr<GameManager> gamemanager= new GameManager();
	Socket socket(2000,4);
	ReferenceCountPtr<PlayerProxyr>  playerProxy;
	// mientras 
	// juego no iniciado
	// juego no lleno 
	// aceptar nuevos jugadores
	for (int i=0; i<4; i++) {
		std::cerr << "Antes de new con i = " << i << "\n" << std::endl;
		playerProxy = new PlayerProxy(socket.accept(), gamemanager);
		std::cerr << "Despues de new...\n" << std::endl;

		playerProxy->start();
		gamemanager->add(playerProxy);
	}
/*
	while (siga el juego) {
		//

	}
*/
/*
        std::vector<ReferenceCountPtr<PlayerProxy> >::iterator players_iterator;
        players_iterator = players.begin();
        while( players_iterator != players.end() ) {
		playerProxy->join();
		++players_iterator;
	}
*/

	return 0;
}
