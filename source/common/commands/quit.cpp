#include "quit.h"
#include "commandobserver.h"

Quit::Quit(std::vector<std::string> &parameterList) : Command ()
{

	this->numeroJugador = atoi (parameterList[0].c_str() );
}

Quit::Quit(){

}
Quit::~Quit(){

}

std::string Quit::serialize(){
	return "<?xml version=\"1.0\"?><quit>"+serializeCommon(getFrom(),0)+"</quit>";

}

bool Quit::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}


void Quit::execute(ReferenceCountPtr<State>& state){
	
	state->quit(*this);
	
}
std::string Quit::getName() {
	return "quit";
}

void Quit::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);

}
