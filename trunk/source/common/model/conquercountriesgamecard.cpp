#include "conquercountriesgamecard.h"

ConquerCountriesGameCard::ConquerCountriesGameCard(
	const std::string& gameCardName, int countryCount):
    GameCard(gameCardName),
    countryCount(countryCount) {
    // No realiza ninguna acciòn.
}

bool ConquerCountriesGameCard::execute(const ReferenceCountPtr<Player>& player,
    const ReferenceCountPtr<Game>& game) {
    return false;
}

ConquerCountriesGameCard::~ConquerCountriesGameCard() {
    // No realiza ninguna acciòn.
}

