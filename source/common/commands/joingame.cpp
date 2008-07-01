#include "joingame.h"
#include "commandobserver.h"

JoinGame::JoinGame(std::vector<std::string> &parameterList) : Command ()
{

	this->numeroJugador = atoi (parameterList[0].c_str() );
}

JoinGame::JoinGame(const std::string & xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

JoinGame::JoinGame(){

}

JoinGame::~JoinGame()
{
}

std::string JoinGame::serialize(){
	return "<?xml version=\"1.0\"?><joingame>"+serializeCommon(0,0)+"</joingame>";

}

bool JoinGame::validate(ReferenceCountPtr<GameManager>& gameManager){
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

std::string JoinGame::getName() {
	return "joinGame";
}

void JoinGame::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

