#include "defending.h"
#include "../model/battle.h"

Defending::Defending(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Defending::~Defending()
{
}

bool Defending::defend(Defend & command){
	
	bool accionValida=false;

	//se le pide al comando que se valide
	accionValida = command.validate(this->gameManager);
	
	//si es valido
	if (accionValida){
		//creo e inicio batalla
		Battle batalla(this->gameManager->getAttack(),command, this->gameManager->getGame()->getDice());
		
		BattleResult resultadoBatalla = batalla.start(this->gameManager);
		
		//cambio a proximo estado : mover
		this->gameManager->setCurrentState("moving");
		
		//actualizo modelo
		
		//notifico resultado batalla

	}
	
	return accionValida;	
}

