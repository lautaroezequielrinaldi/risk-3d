#include<sstream>
#include "turntooccuppy.h"

TurnToOccuppy::TurnToOccuppy(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	
}

TurnToOccuppy::TurnToOccuppy(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

TurnToOccuppy::TurnToOccuppy(){

}

TurnToOccuppy::~TurnToOccuppy()
{
	//no realiza ninguna accion
}

std::string TurnToOccuppy::serialize(){
	 return "<?xml version=\"1.0\"?>";
}

void* TurnToOccuppy::hydrate(std::string xml){
	
	
	return NULL;
;
	
}
		
bool TurnToOccuppy::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void TurnToOccuppy::execute(ReferenceCountPtr<State>& state){
	
	state->turnToOccuppy(*this);
	
}



