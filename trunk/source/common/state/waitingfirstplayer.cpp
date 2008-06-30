#include "waitingfirstplayer.h"
#include <iostream>
#include <sstream>

#include "../model/gamemanager.h"
#include "../commands/youare.h"
#include "../commands/maplist.h"

WaitingFirstPlayer::WaitingFirstPlayer(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

WaitingFirstPlayer::~WaitingFirstPlayer()
{
}



bool WaitingFirstPlayer::joinGame(JoinGame & command){
	std::cout << "Evento WaitingFirstPlayer::joinGame" << std::endl;

/*
	std::vector<std::string> v;
	v.push_back("1");

	YouAre * youare = new YouAre(v);
	this->gameManager->notify(youare,1);
	delete(youare);
*/

	this->gameManager->getTurnManager()->changeTurn(1);

	std::vector<std::string> v;

	v.push_back("mapa1");
	v.push_back("mapa2");
	v.push_back("mapa3");
	

	MapList * mapList = new MapList(v);
	this->gameManager->notify(mapList);
	delete(mapList);

	this->gameManager->getStateMachine()->setState("waitingMapSelection");
	return false;
}



