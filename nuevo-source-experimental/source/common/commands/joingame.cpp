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



std::string JoinGame::getName() {
	return "joinGame";
}

void JoinGame::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

