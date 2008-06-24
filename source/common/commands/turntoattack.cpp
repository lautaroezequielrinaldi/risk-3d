#include<sstream>
#include "turntoattack.h"

TurnToAttack::TurnToAttack(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	
}

TurnToAttack::TurnToAttack(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

TurnToAttack::TurnToAttack(){

}

TurnToAttack::~TurnToAttack()
{
	//no realiza ninguna accion
}

std::string TurnToAttack::serialize(){
	 return "<?xml version=\"1.0\"?>";
}

void* TurnToAttack::hydrate(std::string xml){
	
	
	return NULL;
;
	
}
		
bool TurnToAttack::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void TurnToAttack::execute(ReferenceCountPtr<State>& state){
	
	state->turnToAttack(*this);
	
}



