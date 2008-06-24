#include "defending.h"
#include "../model/battle.h"

#include<iostream>

using namespace std;

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
		
		cout<<"Ejercitos defensores: "<<command.getArmyCount()<<endl;		
		
		//creo batalla
		Battle batalla(this->gameManager->getAttack(),command, this->gameManager->getGame()->getDice());
		
		// inicio batalla. el modelo se actualiza automaticamente.
		BattleResult resultadoBatalla = batalla.start(this->gameManager);
	
		//notifico resultado batalla
		cout<<"RESULTADO DE LA BATALLA:"<<endl;
		
		if ( resultadoBatalla.getAttackerResult() < 0 )
			cout<<"Atacante perdio: "<<abs ( resultadoBatalla.getAttackerResult() )<<" ejercitos"<<endl;
		
		if ( resultadoBatalla.getDefenderResult() < 0 )
			cout<<"Defensor perdio: "<< abs( resultadoBatalla.getDefenderResult() )<<" ejercitos"<<endl;	
				
		//cambio a proximo estado : mover
		this->gameManager->setCurrentState("moving");
	

	}
	else
		//notificar error
	
	return accionValida;	
}

