#include "serverJoingame.h"

ServerJoinGame::ServerJoinGame() : JoinGame()
{
}

ServerJoinGame::~ServerJoinGame(const std::string & xml) : JoinGame ( xml )
{
}
bool ServerJoinGame::validate(ReferenceCountPtr<GameManager>& gameManager){
    // evaluar si hay lugar	
		return false;
	
}

void ServerJoinGame::execute(ReferenceCountPtr<State>& state){
    state->joinGame(*this);

    // pasar al state correspondiente
    // suscribir jugador
    // si es el primer jugador cambiar estado a "esperandoSeleccionMapa"
    //    enviar comando "offerMaps" a este jugador
    //    return
    //
    // si no hay mas lugar hacer auto listos
    //     return
    // enviar message("aguardando jugadores")


	
}


