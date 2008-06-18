#include "../common/net/sockets/socket.h"
#include "../common/model/gamemanager.h"
#include "../common/smartpointer/referencecountptr.h"
#include "playerproxy.h"

#include <iostream>
#include <vector>

int main (int argc, char** argv) {
	ReferenceCountPtr<GameManager> gamemanager= new GameManager();
	Socket socket(2000,4);
	ReferenceCountPtr<PlayerProxy>  playerProxy;

	while (! gamemanager->open() ) {
		std::cerr << "Antes de new con i = \n" << std::endl;
		playerProxy = new PlayerProxy(socket.accept(), gamemanager);
		std::cerr << "Despues de new...\n" << std::endl;

		playerProxy->start();
		gamemanager->add(playerProxy);
	}

	while (gamemanager->playing()) {
		//

	}

        std::vector<ReferenceCountPtr<PlayerProxy> >::iterator playersProxyIterator;
/*        playersProxyIterator = gamemanager->players.begin();
        while( playersProxyIterator != gamemanager->players.end() ) {
		playerProxy->join();
		++playersProxyIterator;
	}
*/
	return 0;
}
