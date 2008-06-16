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
    result["cantidad-paises"] = countryCountStr.str();

    return result;
}

ConquerCountriesGameCard::~ConquerCountriesGameCard() {
    // No realiza ninguna acciòn.
}

