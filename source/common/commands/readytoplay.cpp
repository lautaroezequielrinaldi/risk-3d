#include "readytoplay.h"
#include "commandobserver.h"

ReadyToPlay::ReadyToPlay(std::vector<std::string> &parameterList) : Command ()
{
	this->numeroJugador = atoi (parameterList[0].c_str() );
}

ReadyToPlay::ReadyToPlay(const std::string & xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}
ReadyToPlay::ReadyToPlay(){

}

ReadyToPlay::~ReadyToPlay()
{
}

std::string ReadyToPlay::serialize(){

    	return "<?xml version=\"1.0\"?><readytoplay>"+serializeCommon(getFrom(),getTo())+"</readytoplay>";
}


bool ReadyToPlay::validate(ReferenceCountPtr<GameManager>& gameManager){
    return false;
	
}

void ReadyToPlay::execute(ReferenceCountPtr<State>& state){
    state->readyToPlay(*this);
    // pasar al state correspondiente
    // cambiar a ready al player
    // si !todos ready
    //     notificar que uno mas esta listo
    //     return
    // cambiar estado a populating 	
}

std::string ReadyToPlay::getName() {
	return "readyToPlay";
}

void ReadyToPlay::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}


