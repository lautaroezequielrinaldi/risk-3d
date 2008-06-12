#include "conquerplayergamecard.h"

ConquerPlayerGameCard::ConquerPlayerGameCard(const std::string& gameCardName,
    int color):
    GameCard(gameCardName),
    color(color) {
    // No realiza ninguna acciòn.
}

bool ConquerPlayerGameCard::execute(const ReferenceCountPtr<Player>& player,
    const ReferenceCountPtr<Game>& game) {
    return false;
}

ConquerPlayerGameCard::~ConquerPlayerGameCard() {
    // No realiza ninguna acciòn.
}

