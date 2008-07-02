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


std::string ReadyToPlay::getName() {
	return "readyToPlay";
}

void ReadyToPlay::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}


