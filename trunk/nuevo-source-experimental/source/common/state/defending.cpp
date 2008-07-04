#include "../model/gamemanager.h"
#include "defending.h"
#include "../commands/defend.h"
#include "../Servercommands/serverattack.h"
#include "../Servercommands/serverdefend.h"
#include "stateobserver.h"
#include "../model/battle.h"


#include<sstream>

#include<iostream>

using namespace std;

Defending::Defending(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Defending::~Defending()
{
}

bool Defending::defend(ServerDefend & command){
	
	std::ostringstream strComodin,strComodin2,strComodin3,strComodin4;
	
	std::cerr << "Evento Defending::defend" << std::endl;
	
	bool accionValida = command.validate(this->gameManager);
	
	//si es valido
	if (accionValida){
		
		ReferenceCountPtr<Pais> paisA = gameManager->getGame()->getMapa()->obtenerPais(command.getDefenderdLand() );
		ReferenceCountPtr<Pais> paisD =  gameManager->getGame()->getMapa()->obtenerPais( gameManager->getAttack().getAttackerLand() );
		
		
		cerr<<"Ejercitos defensores: "<<command.getArmyCount()<<endl;		
		
		cerr<<"ANTES DE LA BATALLA:"<<endl;
		cerr<<"Pais atacado tiene: "<< paisA->getArmyCount() <<" ejercitos"<<endl;
		cerr<<"Pais atacante tiene: "<<paisD->getArmyCount() <<" ejercitos"<<endl;		
				
		//creo batalla
		Battle batalla(this->gameManager->getAttack(),command, this->gameManager->getGame()->getDice());
		
		// inicio batalla. el modelo se actualiza automaticamente.
		BattleResult resultadoBatalla = batalla.start(this->gameManager);
		
		//notifico resultado batalla
	
		cerr<<"RESULTADO DE LA BATALLA:"<<endl;
		
		cerr<<"Atacante perdio: "<< resultadoBatalla.getAttackerResult()<<" ejercitos"<<endl;
		
		cerr<<"Defensor perdio: "<< resultadoBatalla.getDefenderResult()<<" ejercitos"<<endl;	
		
		
		cerr<<"DESPUES DE LA BATALLA:"<<endl;
 		cerr<<"Pais atacado tiene: "<< paisA->getArmyCount() <<" ejercitos"<<endl;
		cerr<<"Pais atacante tiene: "<<paisD->getArmyCount() <<" ejercitos"<<endl;				
		
		//cambio a estado atacar nuevamente para que el jugador inicie nuevo ataque si asi lo desea.
		this->gameManager->setCurrentState("attacking");
		
		cerr<<"PUEDE ATACAR NUEVAMENTE O TERMINAR AHORA."<<endl;
		
		// --------completo battleResult  Para mensajear al cliente--------------
		
			
		//seteo los mensajes
		resultadoBatalla.setValid(1);
		resultadoBatalla.setTo(gameManager->getTurnManager()->getCurrentPlayer());//atacante
		resultadoBatalla.setFrom(0);

				
		//seteo mje principal
		strComodin2 <<  resultadoBatalla.getAttackerResult();
		strComodin4 <<  resultadoBatalla.getDefenderResult();
		
		//mje para todos
		std::string mainMsg = "Resultado de la batalla: "+ this->gameManager->getAttack().getAttackerLand() +
							  " perdio "+ strComodin2.str() + " ejercitos. " + command.getDefenderdLand() +
							  " perdio "+ strComodin4.str() + " ejercitos";
		
		//si hubo conquista concateno al mensaje, esta notificacion.
		if ( resultadoBatalla.getConquest() != 0 ){
			
			//obtengo cantidad de ejercitos q se movieron al pais conquistado
			strComodin3 << resultadoBatalla.getConquest();
			strComodin << gameManager->getTurnManager()->getCurrentPlayer(); // del atacante
			
			mainMsg += "El jugador * " +  strComodin.str() + " * conquisto el pais " + command.getDefenderdLand()+".Se movieron "+
					 	strComodin3.str() + " ejercitos al pais conquistado.";
			
		}
				
		resultadoBatalla.setMainMsg(mainMsg);
		
		//no hay mensaje secundario
		resultadoBatalla.setSecMsg("");	
		
		//notifico cambios y mensajes --manda un commandResultadoBatalla
		gameManager->notify(&resultadoBatalla);
		
		//------- fin notificacion al cliente ------------------------
	
	}
	//defensa invalida
	else {
		
		command.setValid(0);
		//command.setTo(gameManager->getTurnManager()->getDefenderPlayer());//al defensor
		//command.setFrom(0);
		
		//seteo mje principal
		std::string mainMsg = "Error! Defensa invalida ";
		command.setMainMsg(mainMsg);
		
		//seteo mje secundario
		strComodin << gameManager->getTurnManager()->getDefenderPlayer();
		
		std::string secMsg = "El jugador * "+ strComodin.str() +" realizo una defensa invalida";
		command.setSecMsg(secMsg);	
		
		//notifico cambios y mensajes
		gameManager->notify(&command);	
		
	}
	
	return accionValida;	
}

void Defending::accept(StateObserver* observer) {
    observer->stateChanged(*this);
}

