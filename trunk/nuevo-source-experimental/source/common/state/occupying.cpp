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
	
	std::cerr << "Evento Occupyinhg::populate" << std::endl;	
	
	std::ostringstream strComodin;

	bool accionValida = command.validateOccupy(this->gameManager);
		
	
	if ( accionValida ){

		//actualiza modelo:
		ReferenceCountPtr<Game> game = gameManager->getGame();
		ReferenceCountPtr<Mapa> map = game->getMapa();
		//obtengo pais a poblar
		ReferenceCountPtr<Pais> paisD = map->obtenerPais(command.getCountryDestination());	
		
		std::cerr << "Ocupamiento valido....." << std::endl;	
		
		cerr<<"pais destino: "<<paisD->getNombre()<<endl;
		cerr<<"ejercitos antes de ocupar: "<<paisD->getArmyCount()<<endl;
		
		std::cerr << "Agregando ejercitos al pais destino...." << std::endl;	
		//agrego al pais destino la cantidad de ejercitos solicitados
		paisD->addArmies(command.getArmyCount() );
		
		cerr<<"ejercitos despues de ocupar: "<<paisD->getArmyCount()<<endl;
		
		//obtengo jugador actual 
		ReferenceCountPtr<Player> playerActual = game->getPlayer( this->gameManager->getTurnManager()->getCurrentPlayer() );
		
		//agrego a la lista de paises del jugador, el pais ocupado.
		std::cerr << "Agregando pais ocupado a la lista de paises del jugador....." << std::endl;
		std::string p = command.getCountryDestination();
		playerActual->addConqueredLand(p);
		
		//disminuyo en 1 la cant de ejercitos a ubicar
		std::cerr << "Disminuyendo 1 armada de las disponibles para ocupar......" << std::endl;
		playerActual->setArmyCount( playerActual->getArmyCount() - 1 );
		
		cerr<<"Cantidad de paises ocupados por el jugador "<<playerActual->getColor()<<" :"<<playerActual->getConqueredLands()<<endl;;
	
		// --------mensajear al cliente--------------
		
		std::cerr << "Armando mensajes para el cliente....." << std::endl;
		
		//seteo al commando como valido
		command.setValid(1);
		command.setTo( gameManager->getTurnManager()->getCurrentPlayer() );
		
		//seteo mje principal
		std::string mainMsg = "Pais Ocupado: "+command.getCountryDestination();
		command.setMainMsg(mainMsg);
		
		//seteo mje secundario
   		strComodin << playerActual->getColor();
		std::string secMsg = "El jugador * " +strComodin.str() +" * ocupo el pais: "+command.getCountryDestination();
		command.setSecMsg(secMsg);	
		
		//notifico cambios y mensajes
		gameManager->notify(&command);
		
		std::cerr << "Clientes notificados...." << std::endl;
		//------- fin actualizacion para cliente ------------------------
		
		
		// si ya se habitaron todos los paises del mapa
		if ( !map->areUninhabitedCountries() ){
			
			std::cerr << "Todos los paises del mapa ya fueron ocupados" << std::endl;
			
			std::cerr << "Cambiando a estado SimplePopulating......" << std::endl;
			
			// cambio alproximo estado: simplePopulating
			this->gameManager->setCurrentState("simplePopulating");
			
			std::cerr << "Cambiando el turno al primer jugador de la ronda......" << std::endl;
			
			//cambio de turno al 1er jugador
			this->gameManager->getTurnManager()->changeTurn( this->gameManager->getTurnManager()->getFirstPlayer() );
					
			std::cerr << "Armando comando TurnToPopulate Simple......." << std::endl;
					
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
			gameManager->notify(&turnToFirstPopu);	
			
			std::cerr << "Clientes notificados sobre turnToPopulate inicial" << std::endl;
			
			cerr<<"HORA DE POBLAR INICIAL"<<endl;	
		}
		else{
			
			std::cerr << "Cambiando turno al proximo jugador....." << std::endl;
			
			//cambio de turno 
			this->gameManager->getTurnManager()->changeTurn();

			//preparo parametros para turnToOccupy
			std::vector<string> vecParam;
		
			//conversion de entero a string
			strComodin << gameManager->getTurnManager()->getCurrentPlayer();
			
			//seteo jugador al que le toca jugar.
			vecParam.push_back(strComodin.str());

			std::cerr << "Creando comando TurnToOccuupy para enviar al cliente......" << std::endl;

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
			gameManager->notify(&turnToOc);	
			
			std::cerr << "Clientes notificados de turnToOccupy....." << std::endl;

		}
	}
	//comando invalido
	else{
		
		command.setValid(0);
		command.setTo( gameManager->getTurnManager()->getCurrentPlayer() );
		
		//seteo mje principal
		std::string mainMsg = "Error! Ocupamiento invalido ";
		command.setMainMsg(mainMsg);
		
		//seteo mje secundario
		strComodin << gameManager->getTurnManager()->getCurrentPlayer();
		std::string secMsg = "El jugador * "+ strComodin.str() +" realizo un ocupamiento invalido";
		command.setSecMsg(secMsg);	
		
		//notifico cambios y mensajes
		gameManager->notify(&command);	
		
		std::cerr << "Ocupamiento invalido..." << std::endl;
	}
		
	return accionValida;        
        
}

void Occupying::accept(StateObserver* observer) {
    observer->stateChanged(*this);
}

