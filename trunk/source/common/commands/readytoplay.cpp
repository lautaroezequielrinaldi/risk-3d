#include "readytoplay.h"

ReadyToPlay::ReadyToPlay(std::vector<std::string> &parameterList) : Command ()
{
}

ReadyToPlay::ReadyToPlay(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}
ReadyToPlay::ReadyToPlay(){

}

ReadyToPlay::~ReadyToPlay()
{
}

std::string ReadyToPlay::serialize(){
	std::string result("");	
    
    
    return result;
  
}

void* ReadyToPlay::hydrate(std::string xml){
	

    return 0;	
}

bool ReadyToPlay::validate(ReferenceCountPtr<GameManager>& gameManager){
    return false;
	
}

void ReadyToPlay::execute(ReferenceCountPtr<State>& state){
    state->readyToPlay(*this);
    // pasar al state correspondiente
    // cambiar a ready al player
    // si !todos ready
    //     notificar que uno mas esta listo
    //     return
    // cambiar estado a populating 	
}



