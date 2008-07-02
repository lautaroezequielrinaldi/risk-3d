#include<sstream>
#include "win.h"
#include "commandobserver.h"

Win::Win(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->numeroJugador = atoi (parameterList[0].c_str() );
}

Win::Win(const std::string & xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

Win::Win(){

}

Win::~Win()
{
	//no realiza ninguna accion
}

std::string Win::serialize(){
	 return "<?xml version=\"1.0\"?><win>"+serializeCommon(0,numeroJugador)+"</win>";
}

	

std::string Win::getName() {
	return "win";
}


void Win::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

