#include "quit.h"


Quit::Quit(std::vector<std::string> &parameterList) : Command ()
{

	this->numeroJugador = atoi (parameterList[0].c_str() );
}

Quit::Quit(){

}
Quit::~Quit(){

}

std::string Quit::serialize(){
	return "<?xml version=\"1.0\"?><quit>"+Command::serialize(numeroJugador,0)+"</quit>";
}
bool Quit::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}
void* Quit::hydrate(std::string xml){

	return NULL;
}

void Quit::execute(ReferenceCountPtr<State>& state){
	
	state->quit(*this);
	
}
std::string Quit::getName() {
	return "quit";
}
