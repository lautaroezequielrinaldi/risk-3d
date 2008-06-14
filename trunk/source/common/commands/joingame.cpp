#include "joingame.h"


JoinGame::JoinGame(std::vector<std::string> &parameterList) : Command ()
{
}

JoinGame::JoinGame(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

JoinGame::~JoinGame()
{
}

std::string JoinGame::serialize(){
	std::string result("");	
    
    
    return result;
  
}

void* JoinGame::hydrate(std::string xml){
	

    return 0;	
}

bool JoinGame::validate(ReferenceCountPtr<GameManager>& gameMAnager){
    // evaluar si hay lugar	
		return false;
	
}

void JoinGame::execute(ReferenceCountPtr<State>& state){
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



