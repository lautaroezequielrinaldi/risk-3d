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

bool ConquerCountriesGameCard::execute(const ReferenceCountPtr<Player>& player,
    const ReferenceCountPtr<Game>& game) {
    return false;
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


bool ConquerCountriesGameCard::execute(const ReferenceCountPtr<Player>& player, const ReferenceCountPtr<Game>& game){
	
	bool res=false;
	
	// si el jugador tiene la cantidad de paises necesarios para cumplir el objetivo
	if (player->getConqueredLands() ==this->countryCount )
		res=true;
		
	return res;
}


ConquerCountriesGameCard::~ConquerCountriesGameCard() {
    // No realiza ninguna acciòn.
}

