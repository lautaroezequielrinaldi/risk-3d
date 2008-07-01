#include<sstream>
#include "win.h"

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
	 return "<?xml version=\"1.0\"?><win>"+Command::serialize(0,numeroJugador)+"</win>";
}

		
bool Win::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void Win::execute(ReferenceCountPtr<State>& state){
	
	state->win(*this);
	
}

std::string Win::getName() {
	return "win";
}


