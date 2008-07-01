#include<sstream>
#include "lose.h"
#include "commandobserver.h"

Lose::Lose(std::vector<std::string> & parameterList):Command ()
{


	this->numeroJugador = atoi (parameterList[0].c_str() );
	
}

Lose::Lose(const std::string & xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

Lose::Lose(){

}

Lose::~Lose()
{
	//no realiza ninguna accion
}

std::string Lose::serialize(){
	 return "<?xml version=\"1.0\"?><lose>"+serializeCommon(0,numeroJugador)+"</lose>";
}

		
bool Lose::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void Lose::execute(ReferenceCountPtr<State>& state){
	
	state->lose(*this);
	
}

std::string Lose::getName() {
	return "lose";
}

void Lose::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

