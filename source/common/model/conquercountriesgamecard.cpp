#include "conquercountriesgamecard.h"

ConquerCountriesGameCard::ConquerCountriesGameCard(
	const std::string& gameCardName, int countryCount):
    GameCard(gameCardName),
    countryCount(countryCount) {
    // No realiza ninguna acciòn.
}

int ConquerCountriesGameCard::getCountryCount() {
    return this->countryCount;
}

std::map<std::string, std::string> ConquerCountriesGameCard::toString() {
    std::map<std::string, std::string> result;
    std::ostringstream countryCountStr;
    countryCountStr << getCountryCount();

    result["tipo"] = "CONQUERCOUNTRIESGAMECARD";
    result["nombre"] = getName();
    result["cantidad"] = countryCountStr.str();

    return result;
}

bool ConquerCountriesGameCard::execute(ReferenceCountPtr<GameManager>& gameManager){
	
	bool res=false;
	ReferenceCountPtr<TurnManager> turnManeger = gameManager->getTurnManager();
	ReferenceCountPtr<Player> currentPlayer = gameManager->getGame()->getPlayer(turnManeger->getCurrentPlayer() );
	
	// si el jugador actual tiene la cantidad de paises necesarios para cumplir el objetivo

	if ( currentPlayer->getConqueredLands() == this->countryCount )
		res=true;
	
	return res;
}


ConquerCountriesGameCard::~ConquerCountriesGameCard() {
    // No realiza ninguna acciòn.
}

