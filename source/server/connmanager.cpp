#include "connmanager.h"

/*
 *
 * desactivo charly para compilar
ConnManager::ConnManager(GameManager & gameManager,ProxyPlayerFactory & proxyPlayerFactory):
	gameManager(gameManager),  proxyPlayerFactory(proxyPlayerFactory){

}

*/
/**
 * @todo obtener port y client_wait de otro lado
 *
 */

/**
 *
 * desactivo charly para compilar
 *
void * ConnManager::run() {
	int port = 8000;
	int client_wait = 5;
	Socket socket(port, client_wait);
	while (!isCanceled()){
		socket.listen();
		Socket * newsock = socket.accept();
		ProxyPlayer & pp = ProxyPlayerFactory::getProxyPlayer(newsock);
		gameManager.addPlayer(pp);
	}
}

*/
