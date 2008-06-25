#include "selectmap.h"

SelectMap::SelectMap(std::vector<std::string> &parameterList) : Command ()
{
}

SelectMap::SelectMap(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}
SelectMap::SelectMap() {

}

SelectMap::~SelectMap()
{
}

std::string SelectMap::serialize(){
	std::string result("");	
    
    
    return result;
  
}

void* SelectMap::hydrate(std::string xml){
	

    return 0;	
}

bool SelectMap::validate(ReferenceCountPtr<GameManager>& gameManager){
    // evaluar que el mapa exista	
		return false;
	
}

void SelectMap::execute(ReferenceCountPtr<State>& state){
    state->selectMap(*this);
    // pasar a la implementacion apropiada de state
    // seleccionar el mapa enviado
    // cambiar estado a "esperando listos"
    // notificar "aguardando jugadores"	
	
}
std::string SelectMap::getName() {
	return "selectMap";
}



