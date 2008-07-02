#include "occupying.h"
#include "stateobserver.h"
#include "../commands/populate.h"
#include "../commands/turntooccupy.h"
#include "../commands/turntopopulate.h"
#include "../Servercommands/serverpopulate.h"
#include "../model/gamemanager.h"
#include "../model/player.h"
#include <list>
#include <sstream>

#include<iostream>
using namespace std;

Occupying::Occupying(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Occupying::~Occupying()
{
}

bool Occupying::populate(ServerPopulate & command){
	
	std::ostringstream strComodin;

	bool accionValida = command.validateOccupy(this->gameManager);
		
	
	if ( accionValida ){

		//actualiza modelo:
		ReferenceCountPtr<Game> game = gameManager->getGame();
		ReferenceCountPtr<Mapa> map = game->getMapa();
		//obtengo pais a poblar
		ReferenceCountPtr<Pais> paisD = map->obtenerPais(command.getCountryDestination());	
		
		cout<<"Estado: OCUPANDO"<<endl;
		cout<<"pais destino: "<<paisD->getNombre()<<endl;
		cout<<"ejercitos antes de ocupar: "<<paisD->getArmyCount()<<endl;
		
		//agrego al pais destino la cantidad de ejercitos solicitados
		paisD->addArmies(command.getArmyCount() );
		
		cout<<"ejercitos despues de ocupar: "<<paisD->getArmyCount()<<endl;
		
		//obtengo jugador actual 
		ReferenceCountPtr<Player> playerActual = game->getPlayer( this->gameManager->getTurnManager()->getCurrentPlayer() );
		
		//agrego a la lista de paises del jugador, el pais ocupado.
		std::string p = command.getCountryDestination();
		playerActual->addConqueredLand(p);
		
		//disminuyo en 1 la cant de ejercitos a ubicar
		playerActual->setArmyCount( playerActual->getArmyCount() - 1 );
		
		cout<<"Cantidad de paises conquistados por el jugador "<<playerActual->getColor()<<" :"<<playerActual->getConqueredLands()<<endl;;
	
		// -------- Para actualizar y mensajear al cliente--------------
		
		//seteo al commando como valido
		command.setValid(1);
		
		//seteo mje principal
		std::string mainMsg = "Pais Ocupado: "+command.getCountryDestination();
		command.setMainMsg(mainMsg);
		
		//seteo mje secundario
   		strComodin << playerActual->getColor();
		std::string secMsg = "El jugador * " +strComodin.str() +" * ocupo el pais: "+command.getCountryDestination();
		command.setSecMsg(secMsg);	
		
		//notifico cambios y mensajes
		gameManager->notify(reinterpret_cast<Command*>(&command));
		
		//------- fin actualizacion para cliente ------------------------
		
		
		// si ya se habitaron todos los paises del mapa
		if ( !map->areUninhabitedCountries() ){
			
			// cambio alproximo estado: simplePopulating
			this->gameManager->setCurrentState("simplePopulating");
			
			//cambio de turno al 1er jugador
			this->gameManager->getTurnManager()->changeTurn( this->gameManager->getTurnManager()->getFirstPlayer() );
					
			//preparo parametros para turnToPopulate  ( simple )
			std::vector<string> vecParam;
			
			//conversion de entero a string
			strComodin << gameManager->getTurnManager()->getCurrentPlayer();
			
			//seteo jugador al que le toca jugar.
			vecParam.push_back(strComodin.str());
			
			//creo comando para notificar
			TurnToPopulate turnToFirstPopu(vecParam);
			
			//seteo los mensajes
			turnToFirstPopu.setValid(1);
			turnToFirstPopu.setTo(gameManager->getTurnManager()->getCurrentPlayer());
			turnToFirstPopu.setFrom(0);
			
			turnToFirstPopu.setMainMsg("Tenes el turno para poblar");
   			
			std::string secMsg = "Todos los Paises fueron ocupados. El jugador * " + strComodin.str() + " * esta poblando";
			turnToFirstPopu.setSecMsg(secMsg);
			
			//notifico 
			gameManager->notify(reinterpret_cast<Command*>(&turnToFirstPopu));	
			
			cerr<<"HORA DE POBLAR INICIAL"<<endl;	
		}
		else{
			//cambio de turno 
			this->gameManager->getTurnManager()->changeTurn();

			//preparo parametros para turnToOccupy
			std::vector<string> vecParam;
		
			//conversion de entero a string
			strComodin << gameManager->getTurnManager()->getCurrentPlayer();
			
			//seteo jugador al que le toca jugar.
			vecParam.push_back(strComodin.str());

			//creo comando para notificar
			TurnToOccupy turnToOc(vecParam);
			
			//seteo los mensajes
			turnToOc.setValid(1);
			turnToOc.setTo(gameManager->getTurnManager()->getCurrentPlayer());
			turnToOc.setFrom(0);
			
			turnToOc.setMainMsg("Tenes el turno para ocupar un territorio");
			strComodin << gameManager->getTurnManager()->getCurrentPlayer();
			std::string secMsg = "El jugador * "+ strComodin.str() +" * esta ocupando un territorio";
			turnToOc.setSecMsg(secMsg);
			
			//notifico 
			gameManager->notify(reinterpret_cast<Command*>(&turnToOc));	

		}
	}
	//comando invalido
	else{
		command.setValid(0);
		
		//seteo mje principal
		std::string mainMsg = "Error! Ocupamiento invalido ";
		command.setMainMsg(mainMsg);
		
		//seteo mje secundario
		strComodin << gameManager->getTurnManager()->getCurrentPlayer();
		std::string secMsg = "El jugador * "+ strComodin.str() +" realizo un ocupamiento invalido";
		command.setSecMsg(secMsg);	
		
		//notifico cambios y mensajes
		gameManager->notify(reinterpret_cast<Command*>(&command));	
	}
		
	return accionValida;        
        
}

void Occupying::accept(StateObserver* observer) {
    observer->stateChanged(*this);
}

