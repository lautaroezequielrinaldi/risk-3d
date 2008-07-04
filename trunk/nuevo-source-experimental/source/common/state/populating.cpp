#include "populating.h"
#include "stateobserver.h"
#include "../commands/turntopopulate.h"
#include "../commands/turntoattack.h"
#include "../commands/populate.h"
#include "../Servercommands/serverpopulate.h"
#include "../model/gamemanager.h"
#include "../model/player.h"
#include<sstream>

#include<iostream>

using namespace std;

Populating::Populating(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Populating::~Populating()
{
}
bool Populating::populate(ServerPopulate & command){

	std::ostringstream strComodin;
		
	
	std::cerr << "Evento Populating::populate" << std::endl;
	
	bool accoinValida = command.validate(this->gameManager);
	
	//si la accion es valida
	if (accoinValida){
		
		cerr<<"Estado: populating"<<endl;
		cerr<<"Jugador: "<<gameManager->getTurnManager()->getCurrentPlayer()<<endl;
		
		//actualiza modelo:
		ReferenceCountPtr<Game> game = gameManager->getGame();
		ReferenceCountPtr<Mapa> map = game->getMapa();
		//obtengo pais a poblar
		ReferenceCountPtr<Pais> paisD = map->obtenerPais(command.getCountryDestination());	
		
		cerr<<"pais destino: "<<paisD->getNombre()<<endl;
		cerr<<"ejercitos antes de poblar: "<<paisD->getArmyCount()<<endl;
		cerr<<"Cantidad de ejercitos a ubicar: "<<command.getArmyCount() <<endl;
		
		//agrego al pais destino la cantidad de ejercitos solicitados
		paisD->addArmies(command.getArmyCount() );
		
		//obtengo jugador actual 
		ReferenceCountPtr<Player> playerActual = game->getPlayer( this->gameManager->getTurnManager()->getCurrentPlayer() );
		
		//calculo ejercitos restantes del jugador actual, restandole los que se ubucaron en esta ronda.
		int ejercitosRestantes = playerActual->getArmyCount() - command.getArmyCount();
		
		//seteo al jugador actual la cant de ejercitos que le quedan por ubicar
		playerActual->setArmyCount( ejercitosRestantes );
		
		// -------- Para actualizar modelo y mensajear al cliente--------------
		
		//seteo al commando como valido
		command.setValid(1);
		
		//seteo mje principal
		std::ostringstream strEjer;
		strEjer << command.getArmyCount();
		
		std::string mainMsg = "Se poblo el pais : "+command.getCountryDestination() +" con "+strEjer.str() + " ejercitos" ;
		command.setMainMsg(mainMsg);
		
		//seteo mje secundario
   		strComodin << playerActual->getColor();
		std::string secMsg = "El jugador * " +strComodin.str() +" * poblo el pais: "+command.getCountryDestination()+" con "+strEjer.str() + " ejercitos";
		command.setSecMsg(secMsg);	
		
		//notifico cambios y mensajes
		gameManager->notify(&command);
		
		//------- fin actualizacion modelo para cliente ------------------------
		
		//para tests		
		cerr<<"ejercitos despues de poblar: "<<paisD->getArmyCount()<<endl;
		cerr<<"Al jugador "<<playerActual->getColor()<<" le quedan: "<<playerActual->getArmyCount()<<" ejerctos para ubicar"<<endl;
		
		
		// si luego de actualizar cant de ejercitos restantes del jugador, se quedo en cero.
		if ( playerActual->getArmyCount() == 0 ){

			//cambio al proximo estado: attacking
			gameManager->setCurrentState("attacking");
			
			//preparo parametros para turnToPopulate  ( simple )
			std::vector<string> vecParam;
								
			//seteo jugador al que le toca jugar.
			vecParam.push_back(strComodin.str());
				
			//creo comando para notificar
			TurnToAttack turnToAttack(vecParam);
				
			//seteo los mensajes
			turnToAttack.setValid(1);
			turnToAttack.setTo(gameManager->getTurnManager()->getCurrentPlayer());
			turnToAttack.setFrom(0);
			turnToAttack.setMainMsg("Hora de atacar");
	   			
			std::string secMsg = "El jugador * " + strComodin.str() + " * esta etacando";
			turnToAttack.setSecMsg(secMsg);
				
			//notifico 
			gameManager->notify(&turnToAttack);	
				
			cerr<<"HORA DE ATACAR"<<endl;
		}
		
	}
	//populate invalido
	else{
		
		command.setValid(0);
		
		//seteo mje principal
		std::string mainMsg = "Error! Poblamiento invalido ";
		command.setMainMsg(mainMsg);
		
		//seteo mje secundario
		strComodin << gameManager->getTurnManager()->getCurrentPlayer();
		std::string secMsg = "El jugador * "+ strComodin.str() +" realizo un poblamiento invalido";
		command.setSecMsg(secMsg);	
		
		//notifico cambios y mensajes
		gameManager->notify(&command);	
		
		
		//notificar error test
		cerr<<"poblamiento invalido"<<endl;	
	}	
	
	
	return accoinValida;	
}

void Populating::accept(StateObserver* observer) {
    observer->stateChanged(*this);
}

