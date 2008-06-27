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
	std::cerr << "Evento Defending::defend" << std::endl;
	bool accionValida = command.validate(this->gameManager);
	
	//si es valido
	if (accionValida){
		
		ReferenceCountPtr<Pais> paisA = gameManager->getGame()->getMapa()->obtenerPais(command.getDefenderdLand() );
		ReferenceCountPtr<Pais> paisD =  gameManager->getGame()->getMapa()->obtenerPais( gameManager->getAttack().getAttackerLand() );
		
		
		cout<<"Ejercitos defensores: "<<command.getArmyCount()<<endl;		
		
		cout<<"ANTES DE LA BATALLA:"<<endl;
		cout<<"Pais atacado tiene: "<< paisA->getArmyCount() <<" ejercitos"<<endl;
		cout<<"Pais atacante tiene: "<<paisD->getArmyCount() <<" ejercitos"<<endl;		
				
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
		
		
		cout<<"DESPUES DE LA BATALLA:"<<endl;
 		cout<<"Pais atacado tiene: "<< paisA->getArmyCount() <<" ejercitos"<<endl;
		cout<<"Pais atacante tiene: "<<paisD->getArmyCount() <<" ejercitos"<<endl;				
		
		//cambio a estado atacar nuevamente para que el jugador inicie nuevo ataque si asi lo desea.
		this->gameManager->setCurrentState("attacking");
		cout<<"PUEDE ATACAR NUEVAMENTE O TERMINAR AHORA."<<endl;
	

	} else {
		//notificar error
	}
	
	return accionValida;	
}

