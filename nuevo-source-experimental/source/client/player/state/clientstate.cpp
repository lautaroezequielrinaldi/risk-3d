#include "clientstate.h"
#include "../gamewindow.h"

ClientState::ClientState(GameWindow& gameWindow): gameWindow(gameWindow), armyCount(0), armyIncrement(-1) {
    // No relaiza ninguna accion.
}

GameWindow& ClientState::getGameWindow() const {
    return gameWindow;
}

void ClientState::selectCountry(ReferenceCountPtr<Pais>& country) {
    if (armyCount == 3) {
        armyIncrement = -1;
    } else {
        armyIncrement = 1;
    }
    armyCount += armyIncrement;
}

void ClientState::executeQuit() {
    if (getGameWindow().getServerProxy() != NULL) {
        Quit quit;
        getGameWindow().getServerProxy()->notify(quit);
        getGameWindow().stopMainLoop();
    }
}

void ClientState::executeSurrender() {
    if (getGameWindow().getServerProxy() != NULL) {
        Surrender surrender;
        getGameWindow().getServerProxy()->notify(surrender);
    }
}

void ClientState::executeNoMore() {
    if (getGameWindow().getServerProxy() != NULL) {
        NoMore noMore;
        getGameWindow().getServerProxy()->notify(noMore);
    }
}

int ClientState::getArmyCount() const {
    return armyCount;
}

void ClientState::setFirstCountry(const ReferenceCountPtr<Pais>& country) {
    firstCountry = country;
}

void ClientState::setSecondCountry(const ReferenceCountPtr<Pais>& country) {
    secondCountry = country;
}

ReferenceCountPtr<Pais> ClientState::getSecondCountry() const {
    return secondCountry;
}

ReferenceCountPtr<Pais> ClientState::getFirstCountry() const {
    return firstCountry;
}

ClientState::~ClientState() {
    // No realiza ninguna accion.
}


