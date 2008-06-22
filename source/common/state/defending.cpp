#include "defending.h"
#include "../model/battle.h"

Defending::Defending(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Defending::~Defending()
{
}

bool Defending::defend(Defend & command){
	
	bool accionValida = command.validate(this->gameManager);
	
	//si es valido
	if (accionValida){
		//creo batalla
		Battle batalla(this->gameManager->getAttack(),command, this->gameManager->getGame()->getDice());
		// inicio batalla. el modelo se actualiza automaticamente.
		BattleResult resultadoBatalla = batalla.start(this->gameManager);
				
		//cambio a proximo estado : mover
		this->gameManager->setCurrentState("moving");
		
		//notifico resultado batalla!!!!!!

	}
	else
		//notificar error
	
	return accionValida;	
}

