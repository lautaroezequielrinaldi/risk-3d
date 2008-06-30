#include<sstream>
#include "youare.h"

YouAre::YouAre(std::vector<std::string> & parameterList):Command ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->numeroJugador = atoi (parameterList[0].c_str() );
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
	 return "<?xml version=\"1.0\"?><youare>"+Command::serialize(0,numeroJugador)+"</youare>";
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

int YouAre::getJugador() {
	return numeroJugador;
}
