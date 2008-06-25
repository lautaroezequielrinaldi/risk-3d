#include<sstream>
#include "lose.h"

Lose::Lose(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	
}

Lose::Lose(std::string xml):Command (){

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
	 return "<?xml version=\"1.0\"?>";
}

void* Lose::hydrate(std::string xml){
	
	
	return NULL;
;
	
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


