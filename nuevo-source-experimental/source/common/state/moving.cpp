#include "moving.h"
#include "stateobserver.h"
#include "../commands/move.h"
#include "../commands/turntopopulate.h"
#include "../Servercommands/servermove.h"
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

bool Moving::move(ServerMove & command){
	
	std::ostringstream strComodin,strComodin2;
	
	
	std::cerr << "Evento Moving::move" << std::endl;
	bool accionValida= command.validate ( this->gameManager);
	
	if( accionValida ){

		cerr<<"Movimiento valido, actualizando modelo....."<<endl;
		
		//actualiza modelo:
		ReferenceCountPtr<Game> game = gameManager->getGame();
		ReferenceCountPtr<Mapa> map = game->getMapa();
		ReferenceCountPtr<Pais> paisD = map->obtenerPais(command.getCountryDestination());
		ReferenceCountPtr<Pais> paisO = map->obtenerPais(command.getCountryOrigin());
		
		cerr<<"pais origen: "<<paisO->getNombre()<<endl;
		cerr<<"ejercitos a mover: "<<command.getArmyCount()<<endl;
		cerr<<"pais destino: "<<paisD->getNombre()<<endl;
		
		// elimina la cantidad de ejercitos que mueve del pais origen
		cerr<<" Eliminando ejercitos del pais origen....."<<endl;
		paisO->removeArmies(command.getArmyCount());
		
		// agrega la cantidad de ejercitos que se mueven, al pais destino
		cerr<<"Agregando ejercitos al pais destino....."<<endl;
		paisD->addArmies(command.getArmyCount());
	
		
		// ----- mensajear al cliente--------------
		cerr<<"Preparando mensajes para notificar al cliente....."<<endl;
		
		//seteo al commando como valido
		command.setValid(1);
		//seteo a quien se envia el mensaje principal
		command.setTo( gameManager->getTurnManager()->getCurrentPlayer() );
				
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
		
		cerr<<"Notificando al cliente sobre el movimiento....."<<endl;
		//notifico cambios y mensajes
		gameManager->notify(&command);
		
		//------- fin mensaje para cliente -------------


		cerr<<"Cambiando de turno....."<<endl;
		//cambio de turno
		this->gameManager->getTurnManager()->changeTurn();
		
		//creo un calculador de bonus 
		ArmyBonusCalculator calculadorBonus;
		
		//obtengo jugador actual ( el que jugara )
		ReferenceCountPtr<Player> playerActual = game->getPlayer( this->gameManager->getTurnManager()->getCurrentPlayer() );
		
		cerr<<"Seteandole al jugador N°"<< calculadorBonus.getArmyBonus(this->gameManager) << " ejercitos de bonus....."<<endl;
		
		//le asigno al jugador que ahora tiene el turno, el bonus de ejercitos que usara para poblar.
		playerActual->setArmyCount(calculadorBonus.getArmyBonus(this->gameManager));
		
		cerr<< "Cambiando de estado a Populating....." <<endl;
		//cambio a proximo estado
		this->gameManager->setCurrentState("populating");
		
		//preparo parametros para turnToPopulate
		std::vector<string> vecParam;
			
		//conversion de entero a string
		strComodin << gameManager->getTurnManager()->getCurrentPlayer();
			
		//seteo jugador al que le toca jugar.
		vecParam.push_back(strComodin.str());
			
		cerr<<"Preparando comando TurnToPopulate para enviar al cliente....."<<endl;
			
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
		cerr<<"Notificando al cliente sobre el TurnToPoplate......."<<endl; 
		gameManager->notify(&turnToPopulate);		
	

		// crear comando turn to populate pasarle el armyCountBonus y el from y el to

		cout<<"Hora de poblar....."<<endl;	
		cout<<"Juega el jugador: "<< playerActual->getColor()<<" con bonus: "<<playerActual->getArmyCount()<<endl;
	
	} 
	else {
	
		
		
		command.setValid(0);
		command.setTo( gameManager->getTurnManager()->getCurrentPlayer() );
		
		//seteo mje principal
		std::string mainMsg = "Error! movimiento invalido ";
		command.setMainMsg(mainMsg);
		
		//seteo mje secundario
		strComodin << gameManager->getTurnManager()->getCurrentPlayer();
		
		std::string secMsg = "El jugador * "+ strComodin.str() +" realizo un movimiento invalido";
		command.setSecMsg(secMsg);	
				
		//notifico cambios y mensajes
		gameManager->notify(&command);		
		
		cerr<<"Movimiento invalido...."<<endl;
	
	}


	return accionValida;
}


void Moving::accept(StateObserver* observer) {
    observer->stateChanged(*this);
}

