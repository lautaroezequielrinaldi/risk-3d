
#include "attacking.h"
#include "stateobserver.h"
#include "../commands/attack.h"
#include "../Servercommands/serverattack.h"
#include "../model/gamemanager.h"
#include "../commands/turntomove.h"
#include<sstream>


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

bool Attacking::attack(ServerAttack & command){

	std::ostringstream strComodin,strComodin2;

	std::cerr << "Evento Attacking::attack" << std::endl;			
	
	bool accionValida = command.validate(this->gameManager);

	
	//si es valido
	if (accionValida){
		
		cerr<<"Estado: ATACANDO"<<endl;
		cerr<<"Atacante: "<<gameManager->getTurnManager()->getCurrentPlayer()<<endl;
				
		//almaceno el ataque en el gameManager
		this->gameManager->setAttack(command);
	
		std::string paisAtacado =  command.getAttackedLand();
		int defensor = this->gameManager->getGame()->getCountryOwner(paisAtacado );
		//seteo en el turnManager el defensor
		this->gameManager->getTurnManager()->setDefenderPlayer( defensor  );
		
		cerr<<"El pais "<<command.getAttackedLand()<<" fue ATACADO"<<endl;
		cerr<<"Se debe defender el jugador: "<<defensor<<endl;
		
		//cambio a proximo estado
		this->gameManager->setCurrentState("defending");
		
		// -------- Para actualizar modelo y mensajear al cliente--------------
		
		//seteo al commando como valido
		command.setValid(1);
		
		//seteo que el mensaje principal sea para el jugador atacado
		command.setTo(defensor);
		
		//seteo mje principal
   		strComodin << gameManager->getTurnManager()->getCurrentPlayer();
		strComodin2 << defensor;
		
		//mje para el defensor, para TO
		std::string mainMsg = "El jugador * " +strComodin.str() +" * (Pais: " + command.getAttackerLand() + " ) ataco uno de tus paises: " + 
		command.Attack::getAttackedLand() + " Debes defenderte";
		
		command.Attack::setMainMsg(mainMsg);
		
		//seteo mje secundario
		std::string secMsg = "El jugador * " +strComodin.str() + " * (Pais: " + command.getAttackerLand() + " ) ataco al jugador * " +
		strComodin2.str() + " * (Pais: " + command.getAttackedLand() + " )";
		
		command.setSecMsg(secMsg);	
		
		//notifico cambios y mensajes
		gameManager->notify(&command);
		
		//------- fin actualizacion modelo para cliente ------------------------
				
		
	}
	else{
	
		command.setValid(0);
		
		//seteo mje principal
		std::string mainMsg = "Error! Ataque invalido ";
		command.Attack::setMainMsg(mainMsg);
		
		//seteo mje secundario
		strComodin << gameManager->getTurnManager()->getCurrentPlayer();
		std::string secMsg = "El jugador * "+ strComodin.str() +" realizo un ataque invalido";
		command.setSecMsg(secMsg);	
		
		//seteo para quien sera el mensaje principal
		std::string paisAtacante =  command.getAttackerLand();
		int atacante = this->gameManager->getGame()->getCountryOwner( paisAtacante );
		command.setTo(atacante);
		
		//notifico cambios y mensajes
		gameManager->notify(&command);	
		
	
		//notificar error
		cerr<<"ataque invalido......"<<endl;
	}
		
	return accionValida;	
}


bool Attacking::noMore(ServerNoMore & command){
	
	std::ostringstream strComodin;
	
	//cambio a proximo estado : mover
	this->gameManager->setCurrentState("moving");
	
	//preparo parametros para moving
	std::vector<string> vecParam;
			
	//conversion de entero a string
	strComodin << gameManager->getTurnManager()->getCurrentPlayer();
			
	//seteo jugador al que le toca jugar.
	vecParam.push_back(strComodin.str());
			
	//creo comando para notificar
	TurnToMove turnToMove(vecParam);
			
	//seteo los mensajes
	turnToMove.setValid(1);
	turnToMove.setTo(gameManager->getTurnManager()->getCurrentPlayer());
	turnToMove.setFrom(0);
			
	std::string mainMsg = "Hora de Fortificar unidades, podes mover ejercitos de un solo pais hacia otro";
	turnToMove.setMainMsg(mainMsg);
   			
   	//conversion de entero a string para el numero de jugador
	strComodin << gameManager->getTurnManager()->getCurrentPlayer();
	std::string secMsg = "El jugador * " + strComodin.str() + " * esta fortificando unidades";
	turnToMove.setSecMsg(secMsg);
			
	//notifico 
	gameManager->notify(&turnToMove);
	
	
	cerr<<"HORA DE MOVER EJERCITOS"<<endl;
		
}

void Attacking::accept(StateObserver* observer) {
    observer->stateChanged(*this);
}

