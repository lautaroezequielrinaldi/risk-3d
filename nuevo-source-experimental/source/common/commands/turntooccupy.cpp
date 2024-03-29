#include<sstream>
#include "turntooccupy.h"
#include "commandobserver.h"

TurnToOccupy::TurnToOccupy(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->numeroJugador = atoi (parameterList[0].c_str() );
}

TurnToOccupy::TurnToOccupy(const std::string & xml):Command (){

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
	 return "<?xml version=\"1.0\"?><turntooccupy>"+serializeCommon(0,numeroJugador)+"</turntooccupy>";
}



std::string TurnToOccupy::getName() {
	return "turnToOccupy";
}



void TurnToOccupy::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

