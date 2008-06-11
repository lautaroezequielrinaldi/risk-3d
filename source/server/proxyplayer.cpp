
#include "proxyplayer.h"

#include <iostream>
void * PlayerProxy::run() {
	std::string msg("bienvenido\n");
	socket->write(msg);
	while (true) {
		msg=socket->full_read(5);
		std::cerr << msg << std::endl;
	        std::vector<PlayerProxy *>::iterator players_iterator;
		players_iterator = players.begin();
		while( players_iterator != players.end() ) {
			PlayerProxy * playerProxy =  *players_iterator;
			playerProxy->notify(msg);
			++players_iterator;
		}
	//   cuando llega el mensaje,
	//   se obtiene un lock sobre el estado.
	//   dependiendo del estado, al cual todos los jugadores acceden
	//   se toma alguna accion, que puede involucrar escribir en todos los demas jugadores
	//   devuelve el lock
	}

	return 0;
}
void PlayerProxy::notify(const std::string & msg) {
	socket->write(msg);
}

PlayerProxy::PlayerProxy(Socket * socket, std::vector<PlayerProxy *> & players):players(players){
	this->socket = socket;
}

PlayerProxy::~PlayerProxy(){
	delete(socket);
}

