#include<sstream>
#include "setowner.h"

SetOwner::SetOwner(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	
}

SetOwner::SetOwner(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

SetOwner::SetOwner(){

}

SetOwner::~SetOwner()
{
	//no realiza ninguna accion
}

std::string SetOwner::serialize(){
	 return "<?xml version=\"1.0\"?>";
}

void* SetOwner::hydrate(std::string xml){
	
	
	return NULL;
;
	
}
		
bool SetOwner::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void SetOwner::execute(ReferenceCountPtr<State>& state){
	
	state->setOwner(*this);
	
}



