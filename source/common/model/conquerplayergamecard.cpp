#include "conquerplayergamecard.h"

ConquerPlayerGameCard::ConquerPlayerGameCard(const std::string& gameCardName,
    int color):
    GameCard(gameCardName),
    color(color) {
    // No realiza ninguna acciòn.
}

int ConquerPlayerGameCard::getColor() {
    return this->color;
}

bool ConquerPlayerGameCard::execute(const ReferenceCountPtr<Player>& player,
    const ReferenceCountPtr<Game>& game) {
    return false;
}

std::map<std::string, std::string> ConquerPlayerGameCard::toString() {
    std::ostringstream playerStr;
    playerStr << getColor();
    std::map<std::string, std::string> result;
    result["tipo"] = "CONQUERPLAYERGAMECARD";
    result["nombre"] = getName();
    result["jugador"] = playerStr.str();

    return result;
}

ConquerPlayerGameCard::~ConquerPlayerGameCard() {
    // No realiza ninguna acciòn.
}

