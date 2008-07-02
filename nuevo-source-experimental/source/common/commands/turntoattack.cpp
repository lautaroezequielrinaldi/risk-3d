#include<sstream>
#include "turntoattack.h"
#include "commandobserver.h"

TurnToAttack::TurnToAttack(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/

	this->numeroJugador = atoi (parameterList[0].c_str() );
}

TurnToAttack::TurnToAttack(const std::string &xml):Command (){

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
	 return "<?xml version=\"1.0\"?><turntoattack>"+serializeCommon(0,numeroJugador)+"</turntoattack>";
}


		

std::string TurnToAttack::getName() {
	return "turnToAttack";
}



void TurnToAttack::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

