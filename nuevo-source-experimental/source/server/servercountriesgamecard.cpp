#include "servercountriesgamecard.h"

ServerCountriesGameCard::ServerCountriesGameCard(
	const std::string& gameCardName, int countryCount):
    GameCardValidator(),
    ConquerCountriesGameCard(gameCardName, countryCount) {
    // No realiza ninguna acciòn.
}

bool ServerCountriesGameCard::validate(ReferenceCountPtr<GameManager>& gameManager){
	
	bool res=false;
	ReferenceCountPtr<TurnManager> turnManeger = gameManager->getTurnManager();
	ReferenceCountPtr<Player> currentPlayer = gameManager->getGame()->getPlayer(turnManeger->getCurrentPlayer() );
	
	// si el jugador actual tiene la cantidad de paises necesarios para cumplir el objetivo

	if ( currentPlayer->getServeredLands() == this->getCountryCount() )
		res=true;
	
	return res;
}


ServerCountriesGameCard::~ServerCountriesGameCard() {
    // No realiza ninguna acciòn.
}

