#include<sstream>
#include "turntomove.h"
#include "commandobserver.h"

TurnToMove::TurnToMove(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->numeroJugador = atoi (parameterList[0].c_str() );
}

TurnToMove::TurnToMove(const std::string & xml):Command (){

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
	 return "<?xml version=\"1.0\"?><turntomove>"+serializeCommon(0,numeroJugador)+"</turntomove>";
}

std::string TurnToMove::getName() {
	return "turnToMove";
}



void TurnToMove::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

