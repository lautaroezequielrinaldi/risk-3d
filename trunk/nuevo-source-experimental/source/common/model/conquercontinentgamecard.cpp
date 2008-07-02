#include "conquercontinentgamecard.h"

ConquerContinentGameCard::ConquerContinentGameCard(
    const std::string& name, const std::string& continentName):
    GameCard(name),
    continentName(continentName) {
    // No realiza ninguna acciòn.
}

std::string ConquerContinentGameCard::getContinentName() {
    return this->continentName;
}

std::map<std::string, std::string> ConquerContinentGameCard::toString() {
    std::map<std::string, std::string> result;
    result["tipo"] = "CONQUERCONTINENTGAMECARD";
    result["nombre"] = getName();
    result["continente"] = getContinentName();

    return result;
}

ConquerContinentGameCard::~ConquerContinentGameCard() {
    // No realiza ninguna acciòn.
}

