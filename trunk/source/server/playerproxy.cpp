
#include "playerproxy.h"

#include <iostream>
void * PlayerProxy::run() {
	std::string msg("bienvenido\n");

	socket->write(msg);

	while (true) {

		// deshardcodear este 30
		msg=socket->full_read(30);
		std::cerr << msg << std::endl;
		unsigned int msgLen = 0; //leer cuanto mide el resto del mensaje
		std::string commandName = "JoinGame"; //leer que comando es
		std::string commandXml = "<name>Mauro</name>";//socket->full_read(msgLen);
		gameManager->execute(commandName, commandXml);
		// crear el commmand
		// command->execute()

/*		for (players_iterator =players.begin();
				players_iterator != players.end();
				++players_iterator) {
			PlayerProxy * playerProxy =  *players_iterator;
			playerProxy->notify(msg);
		}
*/
	}
		

	//   cuando llega el mensaje,
	//   se obtiene un lock sobre el estado.
	//   dependiendo del estado, al cual todos los jugadores acceden
	//   se toma alguna accion, que puede involucrar escribir en todos los demas jugadores
	//   devuelve el lock
	
	//delete[] data;
	return 0;
}
void PlayerProxy::notify(const std::string & msg) {
	socket->write(msg);
}

PlayerProxy::PlayerProxy(Socket * socket, ReferenceCountPtr< GameManager> & gameManager){
	this->gameManager= gameManager;
	this->socket = socket;
}

PlayerProxy::~PlayerProxy(){
	delete(socket);
}

void PlayerProxy::setPlayer(ReferenceCountPtr<Player> & player){
	this->player = player;
}

ReferenceCountPtr<Player> & PlayerProxy::getPlayer(){
	return player;

}

