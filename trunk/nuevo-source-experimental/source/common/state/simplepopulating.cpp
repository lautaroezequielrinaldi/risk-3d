#include "simplepopulating.h"
#include "stateobserver.h"
#include "../commands/populate.h"
#include "../commands/turntopopulate.h"
#include "../Servercommands/serverpopulate.h"
#include "../model/gamemanager.h"
#include "../model/player.h"
#include "../model/armybonuscalculator.h"
#include <list>
#include<sstream>


#include<iostream>

using namespace std;

SimplePopulating::SimplePopulating(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

SimplePopulating::~SimplePopulating()
{
}


bool SimplePopulating::populate(ServerPopulate & command){
	std::cerr << "Evento SimplePopulating::populate" << std::endl;
	
	std::ostringstream strComodin;
	
	bool accionValida =  command.validate(this->gameManager);
	
	//si la accion es valida
	if ( accionValida){
		
		cerr<<"Estado: simple populating"<<endl;
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
		
		cerr<<"ejercitos despues de poblar: "<<paisD->getArmyCount()<<endl;
		cerr<<"Al jugador "<<playerActual->getColor()<<" le quedan: "<<playerActual->getArmyCount()<<" ejerctos para ubicar"<<endl;
		
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
		gameManager->notify(reinterpret_cast<Command*>(&command));
		
		//------- fin actualizacion modelo para cliente ------------------------
		

		//obtengo lista de jugadores
		std::list< ReferenceCountPtr<Player> > listaJug = game->getPlayerList();
		std::list<ReferenceCountPtr<Player> >::iterator it;	
		bool noMasEjercitos= true;
		it = listaJug.begin();
					
		//verifico si todos los jugadores estan con cero ejercitos para ubicar
		while ( it != listaJug.end() && noMasEjercitos ){
				
			ReferenceCountPtr<Player> playerActual = *it;
			
			//si al jugador actual de la lista le quedan ejercitos por ubicar
			if ( playerActual->getArmyCount() != 0 )
				noMasEjercitos = false;
				
			++it;
		}
			
		// sino hay mas ejercitos en ningun jugador para ubicar
		if ( noMasEjercitos ){
				
			cerr<<"ningun jugador tiene mas ejercitos por ubicar en la etapa inicial"<<endl;
						
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
			turnToPopulate.setTo(gameManager->getTurnManager()->getCurrentPlayer());
			turnToPopulate.setFrom(0);
			
			//convierto el bonus en un string.
			strComodin << playerActual->getArmyCount();
			std::string mainMsg = "Tenes el turno para poblar. Bonus de ejercitos a ubicar = " + strComodin.str();
			turnToPopulate.setMainMsg(mainMsg);
   			
   			//conversion de entero a string para el numero de jugador
			strComodin << gameManager->getTurnManager()->getCurrentPlayer();
			std::string secMsg = "El jugador * " + strComodin.str() + " * esta poblando";
			turnToPopulate.setSecMsg(secMsg);
			
			//notifico 
			gameManager->notify(reinterpret_cast<Command*>(&turnToPopulate));	
			
			
			//para tests
			cerr<<"Turno de poblar juego para el jugador: "<<playerActual->getColor()<<endl;
			cerr<<"El bonus de ejercitos es: "<<playerActual->getArmyCount()<<endl;
		}
		//si todavia quedan jugadores con ejercitos a ubucar
		else{
			
			// si luego de actualizar cant de ejercitos restantes del jugador q  poblo, se quedo en cero.
			if ( playerActual->getArmyCount() == 0 ){

				//cambio de turno
				this->gameManager->getTurnManager()->changeTurn();	
				
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
				turnToFirstPopu.setTo( gameManager->getTurnManager()->getCurrentPlayer() );
				turnToFirstPopu.setFrom(0);				
				
				turnToFirstPopu.setMainMsg("Tenes el turno para poblar tus territorios");
	   			
				std::string secMsg = "El jugador * " + strComodin.str() + " * esta poblando";
				turnToFirstPopu.setSecMsg(secMsg);
				
				//notifico 
				gameManager->notify(reinterpret_cast<Command*>(&turnToFirstPopu));	
				
				//para test			
				cerr<<"Turno de poblar inicial para el jugador: "<<this->gameManager->getTurnManager()->getCurrentPlayer() <<endl;
			}
		}
		//si el jugador actual todavia tiene ejercitos para poblar, no se le notifica nada, se espera que haga el poblar solito.
	}
	//poblamiento invalido
	else{
		
		//para test
		cerr<<"accion invalida"<<endl;

		command.setValid(0);
		
		//seteo mje principal
		std::string mainMsg = "Error! Poblamiento invalido ";
		command.setMainMsg(mainMsg);
		
		//seteo mje secundario
		strComodin << gameManager->getTurnManager()->getCurrentPlayer();
		std::string secMsg = "El jugador * "+ strComodin.str() +" realizo un poblamiento invalido";
		command.setSecMsg(secMsg);	
		
		//notifico cambios y mensajes
		gameManager->notify(reinterpret_cast<Command*>(&command));	
	}
	
	return accionValida;
}

void SimplePopulating::accept(StateObserver* observer) {
    observer->stateChanged(*this);
}

