#include<sstream>
#include "youare.h"

YouAre::YouAre(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->numeroJugador = 1; //parameterList[0];
}

YouAre::YouAre(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

YouAre::YouAre(){
	
}

YouAre::~YouAre()
{
	//no realiza ninguna accion
}

std::string YouAre::serialize(){
	 return "<?xml version=\"1.0\"?><youare><from>0</from><to>$player</to></youare>";
}

void* YouAre::hydrate(std::string xml){
	
	
	return NULL;
;
	
}
		
bool YouAre::validate(ReferenceCountPtr<GameManager>& gameManager){
	return true;
}

void YouAre::execute(ReferenceCountPtr<State>& state){
	
	state->youAre(*this);
	
}
std::string YouAre::getName() {
	return "youAre";
}



