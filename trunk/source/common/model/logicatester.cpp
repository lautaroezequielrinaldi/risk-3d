#include "logicatester.h"
#include "../smartpointer/referencecountptr.h"
#include "mapposition.h"
#include "pais.h"
#include "continente.h"
#include "mapa.h"
#include "turnmanager.h"
#include "player.h"
#include "dice.h"
#include "filedicebattle.h"
#include "filediceplayerturn.h"
#include "randomdice.h"
#include "gamemanager.h"
#include "../commands/command.h"
#include "../commands/populate.h"
#include "../commands/attack.h"
#include "../commands/defend.h"
#include "../commands/move.h"
#include "../commands/nomore.h"
#include "../commands/commandhydrator.h"

#include "../state/occupying.h"

#include<iostream>

using namespace std;

LogicaTester::LogicaTester()
{
}

LogicaTester::~LogicaTester()
{
}

void LogicaTester::iniciarTest(){

	//creo mapa
	ReferenceCountPtr<Mapa> mapa = new Mapa();
		

	//creo posiciones de mapa
	MapPosition pos1(1,1);
	MapPosition pos2(1,2);
	MapPosition pos3(1,3);
	MapPosition pos4(3,1);
	MapPosition pos5(3,2);
	MapPosition pos6(5,1);
	MapPosition pos7(5,2);
	MapPosition pos8(5,3);
	MapPosition pos9(4,2);
	MapPosition pos10(3,3);
	MapPosition pos11(2,3);
	MapPosition pos12(2,4);
	MapPosition pos13(5,5);
	MapPosition pos14(4,5);
	
	//creo paises
	ReferenceCountPtr<Pais> pais1= new Pais("pais1",pos1);
	ReferenceCountPtr<Pais> pais2= new Pais("pais2",pos2);
	ReferenceCountPtr<Pais> pais3= new Pais("pais3",pos3);
	ReferenceCountPtr<Pais> pais4= new Pais("pais4",pos4);
	ReferenceCountPtr<Pais> pais5= new Pais("pais5",pos5);
	ReferenceCountPtr<Pais> pais6= new Pais("pais6",pos6);
	ReferenceCountPtr<Pais> pais7= new Pais("pais7",pos7);
	ReferenceCountPtr<Pais> pais8= new Pais("pais8",pos8);
	ReferenceCountPtr<Pais> pais9= new Pais("pais9",pos9);
	ReferenceCountPtr<Pais> pais10= new Pais("pais10",pos10);
	ReferenceCountPtr<Pais> pais11= new Pais("pais11",pos11);
	ReferenceCountPtr<Pais> pais12= new Pais("pais12",pos12);
	ReferenceCountPtr<Pais> pais13= new Pais("pais13",pos13);
	ReferenceCountPtr<Pais> pais14= new Pais("pais14",pos14);
	
	//asocio paises adyacentes - tomo como adyacentes dos paises con distancia 1 en X o distancia 1 en Y.
	// toda la agregacion de paises adyacentes pierden memoria.
	
	pais1->agregarAdyacente(pais2);
	pais1->agregarAdyacente(pais5);
	
	pais2->agregarAdyacente(pais1);
	pais2->agregarAdyacente(pais3);
	
	pais3->agregarAdyacente(pais2);
	pais3->agregarAdyacente(pais11);
	
	pais4->agregarAdyacente(pais5);
	
	pais5->agregarAdyacente(pais4);
	pais5->agregarAdyacente(pais9);
	pais5->agregarAdyacente(pais10);
	
	pais6->agregarAdyacente(pais7);
	
	pais7->agregarAdyacente(pais6);
	pais7->agregarAdyacente(pais8);
	pais7->agregarAdyacente(pais9);
	
	pais8->agregarAdyacente(pais7);
	
	pais9->agregarAdyacente(pais5);
	pais9->agregarAdyacente(pais7);
	
	pais10->agregarAdyacente(pais5);
	pais10->agregarAdyacente(pais11);
	
	pais11->agregarAdyacente(pais3);
	pais11->agregarAdyacente(pais10);
	pais11->agregarAdyacente(pais12);
	
	pais12->agregarAdyacente(pais11);
	
	pais13->agregarAdyacente(pais14);
	
	pais14->agregarAdyacente(pais13);
	
	
	//creo continentes
	ReferenceCountPtr<Continente> continente1 = new Continente ("cont1",60);
	ReferenceCountPtr<Continente> continente2 = new Continente ("cont2",40);
	ReferenceCountPtr<Continente> continente3 = new Continente ("cont3",20);
	ReferenceCountPtr<Continente> continente4 = new Continente ("cont4",10);
	ReferenceCountPtr<Continente> continente5 = new Continente ("cont5",20);
		
	//asocio paises con continentes
	continente1->agregarPais(pais1);
	continente1->agregarPais(pais2);
	continente1->agregarPais(pais3);
	
	continente2->agregarPais(pais11);
	continente2->agregarPais(pais12);
	
	continente3->agregarPais(pais5);
	continente3->agregarPais(pais10);
		
	continente4->agregarPais(pais4);
	continente4->agregarPais(pais9);
	
	continente5->agregarPais(pais6);
	continente5->agregarPais(pais7);
	continente5->agregarPais(pais8);
	continente5->agregarPais(pais13);
	continente5->agregarPais(pais14);
	
	//agrego todos los paises al mapa
	mapa->agregarPais(pais1);
	mapa->agregarPais(pais2);
	mapa->agregarPais(pais3);
	mapa->agregarPais(pais4);
	mapa->agregarPais(pais5);
	mapa->agregarPais(pais6);
	mapa->agregarPais(pais7);
	mapa->agregarPais(pais8);
	mapa->agregarPais(pais9);
	mapa->agregarPais(pais10);
	mapa->agregarPais(pais11);
	mapa->agregarPais(pais12);
	mapa->agregarPais(pais13);
	mapa->agregarPais(pais14);
	
	//agrego continentes al mapa
	mapa->agregarContinente(continente1);
	mapa->agregarContinente(continente2);
	mapa->agregarContinente(continente3);
	mapa->agregarContinente(continente4);
	mapa->agregarContinente(continente5);
	
	//// 1er testeo : informe sobre continentes que tiene el mapa y paises de cada continente
	if ( mapa->areUninhabitedCountries() )
		cout<<" HAY PAISES SIN HABITAR" <<endl;
		
	Mapa::IteradorContinente itConti;
	//recorro lista de continentes del mapa
	for( itConti= mapa->primerContinente();itConti != mapa->ultimoContinente();++itConti){
		
		ReferenceCountPtr<Continente> cActual = *itConti;
		cout<<"Continente: "<<cActual->getNombre()<<" Bonus: "<<cActual->getArmyBonus()<<endl;
		cout<<"Paises que lo conforman:"<<endl;
		
		Continente::Iterador itPaises;
		//recorro todos los paises del continente
		for ( itPaises = cActual->primerPais(); itPaises != cActual->ultimoPais();++itPaises){
			
			ReferenceCountPtr<Pais> paisActual = *itPaises;
			cout<<"- "<<paisActual->getNombre()<<endl;	
			
		}
	}
	
	
	//------------------- fin test mapa.
	
	// creo dado para ver q jugador comienza
	const std::string dadito = "dadito";
	Dice * dadoEmpezar = new FileDicePlayerTurn(dadito);
	//creo dado para la batalla
	const std::string dado = "dado";
	Dice * dadoJuego = new FileDiceBattle("dados");
	//creo jugadores
	int bonusInicial = 7;
	
	ReferenceCountPtr<Player> jug1= new Player(1,bonusInicial);
	ReferenceCountPtr<Player> jug2= new Player(2,bonusInicial);
	ReferenceCountPtr<Player> jug3= new Player(3,bonusInicial);
	ReferenceCountPtr<Player> jug4= new Player(4,bonusInicial);
	
	//creo lista de players y los agrego
	std::list< ReferenceCountPtr<Player> > listaJugadores;
	listaJugadores.push_back(jug1);
	listaJugadores.push_back(jug2);
	listaJugadores.push_back(jug3);
	listaJugadores.push_back(jug4);


	//creo turnManager
	ReferenceCountPtr<TurnManager> turnManager = new TurnManager();
	turnManager->addPlayer(1);
	turnManager->addPlayer(2);
	turnManager->addPlayer(3);
	turnManager->addPlayer(4);
	
	
	//turnManager->setTurnOrder(dadoEmpezar->roll());
	turnManager->setTurnOrder(1);
	cout<<"----------------------------------------------------------------------------"<<endl;
	cout<<"Empieza el jugador numero: "<<turnManager->getCurrentPlayer()<<endl;
	cout<<"Ultimo jugador de la ronda: "<<turnManager->getLastPlayer()<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
	
	//creo game
	ReferenceCountPtr<Game> game = new Game(mapa, listaJugadores, *dadoJuego);
	
	//creo gameManager
	ReferenceCountPtr<GameManager> gameManager = new GameManager(game, turnManager);
	
	//creo stateMachine
	ReferenceCountPtr<StateMachine> stateMachine = new StateMachine(gameManager); 
		
	//seteo al gameManager la stateMachine
	gameManager->setStateMachine(stateMachine);
		
	// -------------------- fin preparacion del juego --------------------------------------------------------

	//--- inicio del juego

	//seteo estado inicial deljuego
	gameManager->setCurrentState("occupying");
	std::vector<std::string> vecParametros;
	std::list<ReferenceCountPtr<Pais> > listaPaises= mapa->getCountryList();
	std::list<ReferenceCountPtr<Pais> >::iterator it;
	
	//recorroo lista de paises y los ocupo x un jugador
	for( it = listaPaises.begin() ; it != listaPaises.end(); ++it){
		
		ReferenceCountPtr<Pais> paisActual = *it;
		
		vecParametros.push_back(paisActual->getNombre());
		vecParametros.push_back("1");
		Command * occupy = new Populate(vecParametros);
		
		ReferenceCountPtr<State> currentSt = gameManager->getCurrentState();
		occupy->execute(currentSt);

		vecParametros.clear();
		delete occupy;
	}

	//first populate:
		
		//termina de ocuppar jugador 1 con 3 ejercitos q le quedaron
		vecParametros.push_back("pais1");
		vecParametros.push_back("3");
		Command * occupy = new Populate(vecParametros);
		ReferenceCountPtr<State> currentSt = gameManager->getCurrentState();
		occupy->execute(currentSt);

		vecParametros.clear();
		delete occupy;
		
		//intenta seguir poblando el jugador 1 y da error
		vecParametros.push_back("pais1");
		vecParametros.push_back("6");
		occupy = new Populate(vecParametros);
		currentSt = gameManager->getCurrentState();
		occupy->execute(currentSt);

		vecParametros.clear();
		delete occupy;
		/*
		//ocupa el jugador 2
		vecParametros.push_back("pais2");
		vecParametros.push_back("2");
		occupy = new Populate(vecParametros);
		currentSt = gameManager->getCurrentState();
		occupy->execute(currentSt);

		vecParametros.clear();
		delete occupy;
		*/
		//ocupa otra vez el jugador 2
		vecParametros.push_back("pais10");
		vecParametros.push_back("3");
		occupy = new Populate(vecParametros);
		currentSt = gameManager->getCurrentState();
		occupy->execute(currentSt);

		vecParametros.clear();
		delete occupy;
	
		//ocupa el jugador 3 INVALIDAMENTE XQ NO TIENE 5 EJERCITOS, SINO 4
		vecParametros.push_back("pais11");
		vecParametros.push_back("5");
		occupy = new Populate(vecParametros);
		currentSt = gameManager->getCurrentState();
		occupy->execute(currentSt);

		vecParametros.clear();
		delete occupy;
	
		//ocupa el jugador 3 tdos los q le quedan
		vecParametros.push_back("pais11");
		vecParametros.push_back("4");
		occupy = new Populate(vecParametros);
		currentSt = gameManager->getCurrentState();
		occupy->execute(currentSt);

		vecParametros.clear();
		delete occupy;
		
		
		//ocupa el jugador 3 tdos los q le quedan
		vecParametros.push_back("pais12");
		vecParametros.push_back("4");
		occupy = new Populate(vecParametros);
		currentSt = gameManager->getCurrentState();
		occupy->execute(currentSt);

		vecParametros.clear();
		delete occupy;
		
		//--------------------- fin etapa inicial de poblamiento.-----------------------

		
		//ocupa el jugador 3 con todo el bonus
		vecParametros.push_back("pais1");
		vecParametros.push_back("3");
		occupy = new Populate(vecParametros);
		currentSt = gameManager->getCurrentState();
		occupy->execute(currentSt);

		vecParametros.clear();
		delete occupy;
		
		//intenta seguir poblando el jugador1 cuando el juego ya esta en estado de ATAQUE		
		vecParametros.push_back("pais1");
		vecParametros.push_back("3");
		occupy = new Populate(vecParametros);
		currentSt = gameManager->getCurrentState();
		occupy->execute(currentSt);

		vecParametros.clear();
		delete occupy;
		
		//ATAQUE
		
		//pais atacante
		vecParametros.push_back("pais1");
		//pais defensor
		vecParametros.push_back("pais2");
		//ejercitos para atacar
		vecParametros.push_back("3");
		
		Attack *ataque = new Attack( vecParametros );
		currentSt = gameManager->getCurrentState();
		ataque->execute(currentSt);
		vecParametros.clear();
		
		// se intenta defender con un pais propio del jugador atacado pero que no fue el atacado.
		vecParametros.push_back("pais10");
		vecParametros.push_back("2");
		Defend *defensa = new Defend(vecParametros);
		currentSt = gameManager->getCurrentState();
		defensa->execute(currentSt);
		vecParametros.clear();
		delete defensa;
		
		//se intenta defender con un pais que NO es suyo.
		vecParametros.push_back("pais1");
		vecParametros.push_back("2");
		defensa = new Defend(vecParametros);
		currentSt = gameManager->getCurrentState();
		defensa->execute(currentSt);
		vecParametros.clear();
		delete defensa;
		
		
		//defiende bien
		vecParametros.push_back("pais2");
		vecParametros.push_back("1");
		defensa = new Defend(vecParametros);
		currentSt = gameManager->getCurrentState();
		defensa->execute(currentSt);
		vecParametros.clear();
		delete ataque;
		delete defensa;
		//nuevo ataque
			
		//noMore attack
		
		NoMore *noMoreAttack = new NoMore();
		currentSt = gameManager->getCurrentState();
		noMoreAttack->execute(currentSt);
		
		
		//movimiento de ejercitos cpon pais destino invalid
		vecParametros.push_back("pais1");
		vecParametros.push_back("pais5");
		vecParametros.push_back("3");
		Move *movimiento = new Move(vecParametros);
		currentSt = gameManager->getCurrentState();
		movimiento->execute(currentSt);
		vecParametros.clear();
		/*
		vecParametros.push_back("pais1");
		vecParametros.push_back("pais2");
		vecParametros.push_back("6");
		Move *movimiento = new Move(vecParametros);
		currentSt = gameManager->getCurrentState();
		movimiento->execute(currentSt);
		vecParametros.clear();
		*/
		
		
		
	delete dadoJuego;
	delete dadoEmpezar;
	
}


