#include "turntopopulate.h"
#include<sstream>
#include "commandobserver.h"

TurnToPopulate::TurnToPopulate()
{
	//no realiza ninguna accion
}

TurnToPopulate::~TurnToPopulate()
{
	//no realiza ninguna accion
}

TurnToPopulate::TurnToPopulate(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->numeroJugador = atoi (parameterList[0].c_str() );
}

TurnToPopulate::TurnToPopulate(const std::string & xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

std::string TurnToPopulate::serialize(){
	 return "<?xml version=\"1.0\"?>"+serializeCommon(0,numeroJugador)+" </turntopopulate>";
}
		

std::string TurnToPopulate::getName() {
	return "turnToPopulate";
}

void TurnToPopulate::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

