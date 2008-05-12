int main (int argc, char ** argv) {
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

}
