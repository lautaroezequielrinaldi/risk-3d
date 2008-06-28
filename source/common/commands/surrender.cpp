#include "surrender.h"

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
	return "<?xml version=\"1.0\"?><surrender>"+Command::serialize(numeroJugador,0)+"</surrender>";
	
}
bool Surrender::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}
void* Surrender::hydrate(std::string xml){

	return NULL;
}

void Surrender::execute(ReferenceCountPtr<State>& state){
	
	state->surrender(*this);
	
}
std::string Surrender::getName() {
	return "surrender";
}
