#include "conquercontinentgamecard.h"

ConquerContinentGameCard::ConquerContinentGameCard(
    const std::string& continentName):
    GameCard(),
    continentName(continentName) {
    // No realiza ninguna acciòn.
}

bool ConquerContinentGameCard::execute(const ReferenceCountPtr<Player>& player,
    const ReferenceCountPtr<Game>& game) {
    return false;
}

ConquerContinentGameCard::~ConquerContinentGameCard() {
    // No realiza ninguna acciòn.
}

