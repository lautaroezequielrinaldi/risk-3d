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

	while (! gamemanager->isOpen() ) {
		playerProxy = new PlayerProxy(socket.accept(), gamemanager);
		gamemanager->add(playerProxy);
		playerProxy->start();

	}

	while (gamemanager->isPlaying()) {
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
