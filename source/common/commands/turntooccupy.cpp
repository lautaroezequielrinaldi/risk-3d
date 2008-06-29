#include<sstream>
#include "turntooccupy.h"

TurnToOccupy::TurnToOccupy(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->numeroJugador = atoi (parameterList[0].c_str() );
}

TurnToOccupy::TurnToOccupy(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

TurnToOccupy::TurnToOccupy(){

}

TurnToOccupy::~TurnToOccupy()
{
	//no realiza ninguna accion
}

std::string TurnToOccupy::serialize(){
	 return "<?xml version=\"1.0\"?>"+Command::serialize(0,numeroJugador)+" </turntooccupy>";
}


		
bool TurnToOccupy::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void TurnToOccupy::execute(ReferenceCountPtr<State>& state){
	
	state->turnToOccupy(*this);
	
}
std::string TurnToOccupy::getName() {
	return "turnToOccupy";
}



