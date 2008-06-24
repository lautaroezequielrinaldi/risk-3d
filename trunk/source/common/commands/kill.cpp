#include<sstream>
#include "kill.h"

Kill::Kill(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	
}

Kill::Kill(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

Kill::Kill(){

}

Kill::~Kill()
{
	//no realiza ninguna accion
}

std::string Kill::serialize(){
	 return "<?xml version=\"1.0\"?>";
}

void* Kill::hydrate(std::string xml){
	
	
	return NULL;
;
	
}
		
bool Kill::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void Kill::execute(ReferenceCountPtr<State>& state){
	
	state->kill(*this);
	
}



