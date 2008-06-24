#include<sstream>
#include "turntoocuppy.h"

TurnToOcuppy::TurnToOcuppy(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	
}

TurnToOcuppy::TurnToOcuppy(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

TurnToOcuppy::TurnToOcuppy(){

}

TurnToOcuppy::~TurnToOcuppy()
{
	//no realiza ninguna accion
}

std::string TurnToOcuppy::serialize(){
	 return "<?xml version=\"1.0\"?>";
}

void* TurnToOcuppy::hydrate(std::string xml){
	
	
	return NULL;
;
	
}
		
bool TurnToOcuppy::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void TurnToOcuppy::execute(ReferenceCountPtr<State>& state){
	
	state->turnToOcuppy(*this);
	
}



