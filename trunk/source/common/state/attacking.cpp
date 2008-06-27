#include "attacking.h"
#include "../commands/attack.h"
#include "../model/gamemanager.h"



#include<iostream>

using namespace std;

Attacking::Attacking(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Attacking::~Attacking()
{
}


/*
 * Este modo solo recibe attack en el servidor
 *
 */ 

bool Attacking::attack(Attack & command){
	std::cerr << "Evento Attacking::attack" << std::endl;			

	
	bool accionValida = command.validate(this->gameManager);

	
	//si es valido
	if (accionValida){
		
		cout<<"Estado: ATACANDO"<<endl;
		cout<<"Atacante: "<<gameManager->getTurnManager()->getCurrentPlayer()<<endl;
				
		//almaceno el ataque en el gameManager
		this->gameManager->setAttack(command);
	
		int defensor = this->gameManager->getGame()->getCountryOwner( command.getAttackedLand() );
		//seteo en el turnManager el defensor
		this->gameManager->getTurnManager()->setDefenderPlayer( defensor  );
		
		//notificar del ataque!!!
		cout<<"El pais "<<command.getAttackedLand()<<" fue ATACADO"<<endl;
		cout<<"Se debe defender el jugador: "<<defensor<<endl;
		
		//cambio a proximo estado
		this->gameManager->setCurrentState("defending");
		
	}
	else
		//notificar error
		cout<<"ataque invalido"<<endl;
		
		
	return accionValida;	
}



