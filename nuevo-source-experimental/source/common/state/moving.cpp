#include "moving.h"
#include "stateobserver.h"
#include "../commands/move.h"
#include "../commands/turntopopulate.h"
#include "../model/gamemanager.h"
#include "../model/armybonuscalculator.h"
#include "../model/player.h"
#include <sstream>
#include<iostream>

using namespace std;

Moving::Moving(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Moving::~Moving()
{
}

bool Moving::move(Move & command){
	
	std::ostringstream strComodin,strComodin2;
	
	
	std::cerr << "Evento Moving::move" << std::endl;
	bool accionValida= command.validate ( this->gameManager);
	
	if( accionValida ){

		cout<<"Estado: MOVIENDO"<<endl;
		
		//actualiza modelo:
		ReferenceCountPtr<Game> game = gameManager->getGame();
		ReferenceCountPtr<Mapa> map = game->getMapa();
		ReferenceCountPtr<Pais> paisD = map->obtenerPais(command.getCountryDestination());
		ReferenceCountPtr<Pais> paisO = map->obtenerPais(command.getCountryOrigin());
		
		// elimina la cantidad de ejercitos que mueve del pais origen
		paisO->removeArmies(command.getArmyCount());
		
		// agrega la cantidad de ejercitos que se mueven, al pais destino
		paisD->addArmies(command.getArmyCount());
	
		cout<<"pais origen: "<<paisO->getNombre()<<endl;
		cout<<"ejercitos a mover: "<<command.getArmyCount()<<endl;
		cout<<"pais destino: "<<paisD->getNombre()<<endl;
	

		// -------- Para actualizar modelo y mensajear al cliente--------------
		
		//seteo al commando como valido
		command.setValid(1);
				
		//seteo mje principal
   		strComodin << gameManager->getTurnManager()->getCurrentPlayer();
		strComodin2 << command.getArmyCount() ;
		
		//mje para quien esta jugando y movio ejercitos
		std::string mainMsg = "Moviste "+ strComodin2.str() +" ejercitos desde el pais " + command.getCountryOrigin() +
							  " al pais " + command.getCountryDestination();
				
		command.setMainMsg(mainMsg);
		
		//seteo mje secundario
		std::string secMsg = "El jugador * " +strComodin.str() + "movio "+ strComodin2.str() +" ejercitos desde el pais " + command.getCountryOrigin() +
							  " al pais " + command.getCountryDestination();
			
		command.setSecMsg(secMsg);	
		
		//notifico cambios y mensajes
		gameManager->notify(&command);
		
		//------- fin actualizacion modelo para cliente ------------------------


		//cambio de turno
		this->gameManager->getTurnManager()->changeTurn();
		
		//creo un calculador de bonus 
		ArmyBonusCalculator calculadorBonus;
		
		//obtengo jugador actual ( el que jugara )
		ReferenceCountPtr<Player> playerActual = game->getPlayer( this->gameManager->getTurnManager()->getCurrentPlayer() );
		
		//le asigno al jugador que ahora tiene el turno, el bonus de ejercitos que usara para poblar.
		playerActual->setArmyCount(calculadorBonus.getArmyBonus(this->gameManager));
		
		//cambio a proximo estado
		this->gameManager->setCurrentState("populating");
		
		//preparo parametros para turnToPopulate
		std::vector<string> vecParam;
			
		//conversion de entero a string
		strComodin << gameManager->getTurnManager()->getCurrentPlayer();
			
		//seteo jugador al que le toca jugar.
		vecParam.push_back(strComodin.str());
			
		//creo comando para notificar
		TurnToPopulate turnToPopulate(vecParam);
			
		//seteo los mensajes
		turnToPopulate.setValid(1);
		turnToPopulate.setTo( gameManager->getTurnManager()->getCurrentPlayer());
		turnToPopulate.setFrom(0);
			
		//convierto el bonus en un string.
		strComodin << playerActual->getArmyCount();
		
		mainMsg = "Tenes el turno para poblar. Bonus de ejercitos a ubicar = " + strComodin.str();
		
		turnToPopulate.setMainMsg(mainMsg);
   		
   		//conversion de entero a string para el numero de jugador
		strComodin2 << gameManager->getTurnManager()->getCurrentPlayer();
		
		secMsg = "El jugador * " + strComodin.str() + " * esta poblando";
		
		turnToPopulate.setSecMsg(secMsg);
			
		//notifico 
		gameManager->notify(&turnToPopulate);		
	

		// crear comando turn to populate pasarle el armyCountBonus y el from y el to

		cout<<"HORA DE POBLAR"<<endl;	
		cout<<"Juega el jugador: "<< playerActual->getColor()<<" con bonus: "<<playerActual->getArmyCount()<<endl;
	
	} 
	else {
	
		command.setValid(0);
		
		//seteo mje principal
		std::string mainMsg = "Error! movimiento invalido ";
		command.setMainMsg(mainMsg);
		
		//seteo mje secundario
		strComodin << gameManager->getTurnManager()->getDefenderPlayer();
		
		std::string secMsg = "El jugador * "+ strComodin.str() +" realizo un movimiento invalido";
		command.setSecMsg(secMsg);	
		
		//notifico cambios y mensajes
		gameManager->notify(&command);		
	
		//notificar error en tests
		cout<<"movimiento invalido"<<endl;
	}


	return accionValida;
}


void Moving::accept(StateObserver* observer) {
    observer->stateChanged(*this);
}

