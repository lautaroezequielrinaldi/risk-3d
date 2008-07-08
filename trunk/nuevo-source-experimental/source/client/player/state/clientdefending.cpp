#include "clientdefending.h"
#include "../gamewindow.h"

ClientDefending::ClientDefending(GameWindow& gameWindow, const std::string& attackedCountry, const int& attackerId):
    ClientState(gameWindow),
    attackedCountry(attackedCountry),
    attackerId(attackerId) {
    // No realiza ninguna accion.ç
}

void ClientDefending::selectCountry(ReferenceCountPtr<Pais>& country) {
    if (country != NULL) {
        if (country->getNombre() == attackedCountry) {
            setFirstCountry(country);
            ClientState::selectCountry(country);
        }
    }
}

void ClientDefending::executeNoMore() {
    if (getGameWindow().getServerProxy() != NULL) {
        std::vector<std::string> parameters;
        std::ostringstream armyCountStr;
        std::ostringstream firstPlayerStr;
        std::ostringstream secondPlayerStr;

        armyCountStr << getArmyCount();
        firstPlayerStr << getGameWindow().getServerProxy()->getMe();
        secondPlayerStr << attackerId;

        parameters.push_back(attackedCountry);
        parameters.push_back(armyCountStr.str());
        parameters.push_back(firstPlayerStr.str());
        parameters.push_back(secondPlayerStr.str());

        Defend defend(parameters);
        defend.setFrom(getGameWindow().getServerProxy()->getMe());
        defend.setTo(attackerId);
        getGameWindow().getServerProxy()->notify(defend);
    }
}

ClientDefending::~ClientDefending() {
    // No realiza ninguna accion.
}

