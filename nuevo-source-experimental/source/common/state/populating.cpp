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
		
		cerr<<"Poblamiento valido..."<<endl;
		
		cerr<<"Jugador: "<<gameManager->getTurnManager()->getCurrentPlayer()<<endl;
		
		//actualiza modelo:
		ReferenceCountPtr<Game> game = gameManager->getGame();
		ReferenceCountPtr<Mapa> map = game->getMapa();
		//obtengo pais a poblar
		ReferenceCountPtr<Pais> paisD = map->obtenerPais(command.getCountryDestination());	
		
		cerr<<"pais destino: "<<paisD->getNombre()<<endl;
		cerr<<"ejercitos antes de poblar: "<<paisD->getArmyCount()<<endl;
		cerr<<"Cantidad de ejercitos a ubicar: "<<command.getArmyCount() <<endl;
		
		std::cerr << "Agregando ejercitos a pais destino..." << std::endl;
		
		//agrego al pais destino la cantidad de ejercitos solicitados
		paisD->addArmies(command.getArmyCount() );
		
		//obtengo jugador actual 
		ReferenceCountPtr<Player> playerActual = game->getPlayer( this->gameManager->getTurnManager()->getCurrentPlayer() );
		
		std::cerr << "Calculando cantidad de ejercitos restantes que tiene para poblar" << std::endl;
		
		//calculo ejercitos restantes del jugador actual, restandole los que se ubucaron en esta ronda.
		int ejercitosRestantes = playerActual->getArmyCount() - command.getArmyCount();
		
		std::cerr << "Seteandole al jugador la cantidad de ejercitos restantes que tiene para poblar" << std::endl;
		
		//seteo al jugador actual la cant de ejercitos que le quedan por ubicar
		playerActual->setArmyCount( ejercitosRestantes );
		
		// -------- mensajear al cliente--------------
		
		std::cerr << "Preparando mensajes para los clientes...." << std::endl;
		
		//seteo al commando como valido
		command.setValid(1);
		command.setTo( playerActual->getColor() );
		command.setFrom(0);
				
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
		
		//------- fin mensajes para cliente ------------------------
		
		//para tests		
		cerr<<"ejercitos despues de poblar: "<<paisD->getArmyCount()<<endl;
		cerr<<"Al jugador "<<playerActual->getColor()<<" le quedan: "<<playerActual->getArmyCount()<<" ejerctos para ubicar"<<endl;
		
		
		// si luego de actualizar cant de ejercitos restantes del jugador, se quedo en cero.
		if ( playerActual->getArmyCount() == 0 ){

			std::cerr << "el jugador se quedo sin ejercitos para poblar..." << std::endl;
			std::cerr << "Cambiando estado a attacking......." << std::endl;

			//cambio al proximo estado: attacking
			gameManager->setCurrentState("attacking");
			
			std::cerr << "Preparando comando turnToAttck para enviar...." << std::endl;
			
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
				
				
			cerr<<"Hora de atacar...."<<endl;
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

