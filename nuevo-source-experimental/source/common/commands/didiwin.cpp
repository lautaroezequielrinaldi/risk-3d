#include "didiwin.h"
#include "commandobserver.h"

DidIWin::DidIWin(std::vector<std::string> &parameterList) : Command ()
{

	this->numeroJugador = atoi (parameterList[0].c_str() );
}

DidIWin::DidIWin(){

}
DidIWin::DidIWin(const std::string& xml): Command() {
    hydrate(xml);
}

DidIWin::~DidIWin(){

}

std::string DidIWin::serialize(){
	return "<?xml version=\"1.0\"?><didiwin>"+serializeCommon(getFrom(),getTo())+"</didiwin>";
}


std::string DidIWin::getName() {
	return "didIWin";
}

void DidIWin::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

