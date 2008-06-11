	// carga de mapas existentes
	// creacion de server socket
	// aguardamos una conexion
	// 	si es un editor subiendo un mapa, lo tomamos y cortamos
	// 	si es un jugador y no hay un mapa le echamos
	// 	es el primer jugador, que elija el mapa 
	// 	para cada nueva conexion, un nuevo thread
	
	// estados del servidor
	// no existe mapa -> solo conexion de editor para subir mapa -> next
	//        threaded socket editorListener
	// existe mapa y no hay juego abierto -> un jugador que selecciona mapa -> next
	//        threaded socket initListener
	// hay juego abierto -> entran jugadores hasta que todos digan ok -> next
	//        threaded socket playerListener
	// hay juego iniciado -> loop de turnos hasta que alguien gana o todos pierden -> next
	// termino el juego, se le pregunta al ganador cual es el proximo mapa si lo hay 
	// y asi hasta que todos los jugadores se desconecten     
	
	// necesitamos un estado, que se consulta desde el creador de conexiones, debe estar mutexado



	// me parece que en esta parte ani tiene la palabra
	// loop de turnos:
	// foreach aliveplayers as player
	// 	player->TurnToAttack()
	//	attack = player->getAttack()
	//	attack->validate()
	//	defender = attack->getTarget()
	//	defender->TurnToDefend()
	//	defence = defender->getDefence()
	//	result = attack(defence)->getResult()
	//	update = world->update(result)
	//	players->broadcast(update)
	//	deadplayers = world->getDeadPlayers()
	//	world->remove(deadplayers)
	// 	deadplayers->broadcast(bye)
	//	players->broadcast(news)
	//	if anyobjective is reached...



#include "proxyplayer.h"
#include "../common/net/sockets/socket.h"

#include <iostream>
#include <vector>

int main (int argc, char** argv) {
/*
	std::cerr<< "x1x";
	Socket socket("localhost",25);
	std::cerr<< "x2x";
	socket.write("quit\n",6);
	std::cerr<< "x3x";
	socket.close();
	std::cerr<< "x4x";
*/
	std::vector<PlayerProxy *> players;
	Socket socket(2000,4);
	PlayerProxy * playerProxy;
	// mientras 
	// juego no iniciado
	// juego no lleno 
	// aceptar nuevos jugadores
	for (int i=0; i<4; i++) {
		std::cerr << "Antes de new con i = " << i << "\n" << std::endl;
		playerProxy = new PlayerProxy(socket.accept(), players);
		std::cerr << "Despues de new...\n" << std::endl;

		playerProxy->start();
		players.push_back(playerProxy);
	}

	playerProxy->join();
	// bloquearse esperando a que el juego termine
if (true) {
        std::vector<PlayerProxy *>::iterator players_iterator;
        players_iterator = players.begin();
        while( players_iterator != players.end() ) {
		PlayerProxy * playerProxy =  *players_iterator;
		playerProxy->join();
		++players_iterator;
		delete(playerProxy);
	}
}


	return 0;
}
