#include "clientstate.h"
#include "clientwaiting.h"
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
        quit.setFrom(getGameWindow().getServerProxy()->getMe());
    
        getGameWindow().getServerProxy()->notify(quit);
        getGameWindow().stopMainLoop();
    }
    getGameWindow().stopMainLoop();
}

void ClientState::executeSurrender() {
    if (getGameWindow().getServerProxy() != NULL) {
        Surrender surrender;
        surrender.setFrom(getGameWindow().getServerProxy()->getMe());
        getGameWindow().getServerProxy()->notify(surrender);
        ReferenceCountPtr<ClientState> waiting = new ClientWaiting(getGameWindow());
        getGameWindow().setState(waiting);
    }
}

void ClientState::executeNoMore() {
    if (getGameWindow().getServerProxy() != NULL) {

        std::vector<std::string> parameters;
        std::ostringstream playerNrStr;
        playerNrStr << getGameWindow().getServerProxy()->getMe();
        parameters.push_back(playerNrStr.str());

        NoMore noMore(parameters);
        noMore.setFrom(getGameWindow().getServerProxy()->getMe());
        getGameWindow().getServerProxy()->notify(noMore);
        ReferenceCountPtr<ClientState> waiting = new ClientWaiting(getGameWindow());
        getGameWindow().setState(waiting);
    }
}

void ClientState::executeDidIWin() {
    if (getGameWindow().getServerProxy() != NULL) {
        DidIWin didIWin;
        didIWin.setFrom(getGameWindow().getServerProxy()->getMe());
        getGameWindow().getServerProxy()->notify(didIWin);
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


