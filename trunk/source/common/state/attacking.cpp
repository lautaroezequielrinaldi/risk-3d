#include "attacking.h"
#include "../commands/attack.h"
#include "../model/gamemanager.h"

Attacking::Attacking(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Attacking::~Attacking()
{
}


bool Attacking::attack(Attack & command){
			
	bool accionValida = command.validate(this->gameManager);
	
	//si es valido
	if (accionValida){
		//almaceno el ataque en el gameManager
		this->gameManager->setAttack(command);
		
		//cambio a proximo estado
		this->gameManager->setCurrentState("defending");
		
		//notificar del ataque!!!
	}
	else
		//notificar error
	
	return accionValida;	
}



