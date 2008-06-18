
#include "playerproxy.h"

#include <iostream>
void * PlayerProxy::run() {
	std::string msg("bienvenido\n");
//	std::vector<PlayerProxy *>::iterator players_iterator;
	socket->write(msg);
	//char * data = new(char[5]);
/*	while (true) {
		//socket->full_read(data,5);
		
		msg=socket->full_read(5);
		std::cerr << msg << std::endl;
		for (players_iterator =players.begin();
				players_iterator != players.end();
				++players_iterator) {
			PlayerProxy * playerProxy =  *players_iterator;
			playerProxy->notify(msg);
		}
	}
*/		

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

PlayerProxy::PlayerProxy(Socket * socket, ReferenceCountPtr< GameManager> & gamemanager){
	this->gamemanager= gamemanager;
	this->socket = socket;
}

PlayerProxy::~PlayerProxy(){
	delete(socket);
}

void PlayerProxy::setPlayer(ReferenceCountPtr<Player> & player){
	this->player = player;
}

