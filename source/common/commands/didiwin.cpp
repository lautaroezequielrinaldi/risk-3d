#include "didiwin.h"


DidIWin::DidIWin(std::vector<std::string> &parameterList) : Command ()
{

	this->numeroJugador = atoi (parameterList[0].c_str() );
}

DidIWin::DidIWin(){

}
DidIWin::~DidIWin(){

}

std::string DidIWin::serialize(){
	return "<?xml version=\"1.0\"?><didiwin>"+Command::serialize(numeroJugador,0)+"</didiwin>";
}
bool DidIWin::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}

void DidIWin::execute(ReferenceCountPtr<State>& state){
	
	state->didIWin(*this);
	
}

std::string DidIWin::getName() {
	return "didIWin";
}