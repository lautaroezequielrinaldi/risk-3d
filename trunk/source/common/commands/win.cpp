#include<sstream>
#include "win.h"

Win::Win(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	
}

Win::Win(std::string xml):Command (){

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
	 return "<?xml version=\"1.0\"?><win><from>0</from><to>$player</to></win>";
}

void* Win::hydrate(std::string xml){
	
	
	return NULL;
;
	
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


