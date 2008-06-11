#include "gamecard.h"

GameCard::GameCard(const std::string& name):
    name(name) {
    // No realiza ninguna acciòn.
}

void GameCard::setName(const std::string& name) {
    this->name = name;
}

std::string GameCard::getName() {
    return this->name;
}

GameCard::~GameCard() {
    // No realiza ninguna acciòn.
}

