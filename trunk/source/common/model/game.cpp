#include "game.h"

Game::Game():
    Serializable(),
    mapa(),
    playerList() {
    // No realiza ninguna acciòn.
}

Game::Game(const ReferenceCountPtr<Mapa>& mapa):
    Serializable(),
    mapa(mapa),
    playerList() {
    // No realiza ninguna acciòn.
}

Game::Game(const std::list< ReferenceCountPtr<Player> >& playerList):
    Serializable(),
    mapa(),
    playerList(playerList) {
    // No realiza ninguna acciòn.
}

Game::Game(const ReferenceCountPtr<Mapa>& mapa,
    const std::list< ReferenceCountPtr<Player> >& playerList):
    Serializable(),
    mapa(mapa),
    playerList(playerList) {
    // No realiza ninguna acciòn.
}

void Game::setMapa(const ReferenceCountPtr<Mapa>& mapa) {
    this->mapa = mapa;
}

ReferenceCountPtr<Mapa>& Game::getMapa() {
    return this->mapa;
}

void Game::setPlayerList(
    const std::list< ReferenceCountPtr<Player> >& playerList) {
    this->playerList = playerList;
}

std::list< ReferenceCountPtr<Player> >& Game::getPlayerList() {
    return this->playerList;
}

std::string Game::serialize() {
    std::string resultado;
    return resultado;
}

void* Game::hydrate(std::string filename) {
    return NULL;
}

Game::~Game() {
    // No realiza ninguna acciòn.
}

