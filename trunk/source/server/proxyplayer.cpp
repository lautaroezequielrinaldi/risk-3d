
#include "proxyplayer.h"
void * PlayerProxy::run() {
	// while jugando {
	//   se bloquea leyendo el socket
	//   cuando llega el mensaje,
	//   se obtiene un lock sobre el estado.
	//   dependiendo del estado, al cual todos los jugadores acceden
	//   se toma alguna accion, que puede involucrar escribir en todos los demas jugadores
	//   devuelve el lock
	// }

	return 0;
}

PlayerProxy::PlayerProxy(Socket * socket){
	this->socket = socket;
}

PlayerProxy::~PlayerProxy(){
	delete(socket);
}

