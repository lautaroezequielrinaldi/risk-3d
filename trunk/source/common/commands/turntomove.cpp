#include<sstream>
#include "turntomove.h"

TurnToMove::TurnToMove(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	
}

TurnToMove::TurnToMove(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

TurnToMove::TurnToMove(){

}

TurnToMove::~TurnToMove()
{
	//no realiza ninguna accion
}

std::string TurnToMove::serialize(){
	 return "<?xml version=\"1.0\"?><turntomove><from>0</from><to>$player</to></turntomove>";
}

void* TurnToMove::hydrate(std::string xml){
	
	
	return NULL;
;
	
}
		
bool TurnToMove::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void TurnToMove::execute(ReferenceCountPtr<State>& state){
	
	state->turnToMove(*this);
	
}
std::string TurnToMove::getName() {
	return "turnToMove";
}



