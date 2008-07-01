#include "surrender.h"
#include "commandobserver.h"

Surrender::Surrender(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->numeroJugador = atoi (parameterList[0].c_str() );
}

Surrender::Surrender(){

}

Surrender::~Surrender(){

}

std::string Surrender::serialize(){
	return "<?xml version=\"1.0\"?><surrender>"+serializeCommon(numeroJugador,0)+"</surrender>";
	
}
bool Surrender::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}


void Surrender::execute(ReferenceCountPtr<State>& state){
	
	state->surrender(*this);
	
}
std::string Surrender::getName() {
	return "surrender";
}

int Surrender::getSurrenderPlayer(){
	return this->numeroJugador;
}

void Surrender::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}
