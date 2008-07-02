#include "servercontinentgamecard.h"

ServerContinentGameCard::ServerContinentGameCard(
    const std::string& name, const std::string& continentName):
    GameCardValidator(),
    ConquerContinentGameCard(name, continentName) {
    // No realiza ninguna acciòn.
}

ServerContinentGameCard::~ServerContinentGameCard() {
    // No realiza ninguna acciòn.
}

bool ServerContinentGameCard::validate(ReferenceCountPtr<GameManager>& gameManager){
	
	bool res=false;
	ReferenceCountPtr<TurnManager> turnManeger = gameManager->getTurnManager();
	ReferenceCountPtr<Player> currentPlayer = gameManager->getGame()->getPlayer(turnManeger->getCurrentPlayer() );
	
	
	std::string cont = this->getContinentName();
	// si el jugador conquisto todo el continente
	if ( currentPlayer->continentOwner( cont ) )
		res=true;
		
	return res;
	
}

