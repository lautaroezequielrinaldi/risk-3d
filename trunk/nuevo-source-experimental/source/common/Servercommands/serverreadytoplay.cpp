#include "serverreadytoplay.h"

ServerReadyToPlay::ServerReadyToPlay()
{
}

ServerReadyToPlay::~ServerReadyToPlay()
{
}

bool ServerReadyToPlay::validate(ReferenceCountPtr<GameManager>& gameManager){
    return false;
	
}

void ServerReadyToPlay::execute(ReferenceCountPtr<State>& state){
    state->readyToPlay(*this);
    // pasar al state correspondiente
    // cambiar a ready al player
    // si !todos ready
    //     notificar que uno mas esta listo
    //     return
    // cambiar estado a populating 	
}


