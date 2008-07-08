#include "clientattacking.h"
#include "../gamewindow.h"

ClientAttacking::ClientAttacking(GameWindow& gameWindow): ClientState(gameWindow) {
    // No realiza ninguna accion.
}

ClientAttacking::~ClientAttacking() {
    // No realiza ninguna accion.
}

void ClientAttacking::selectCountry(ReferenceCountPtr<Pais>& country) {
    if (country != NULL) {
        if (getFirstCountry() == NULL) {
            setFirstCountry(country);
            ClientState::selectCountry(country);
        } else if (getFirstCountry()->getNombre() == country->getNombre()) {
            ClientState::selectCountry(country);
        } else {
            if (getGameWindow().getServerProxy() != NULL) {
                setSecondCountry(country);
                std::vector<std::string> parameters;
                std::ostringstream armyCountStr;
                std::ostringstream firstPlayerStr;
                std::ostringstream secondPlayerStr;

                armyCountStr << getArmyCount();
                firstPlayerStr << getGameWindow().getServerProxy()->getMe();
                secondPlayerStr << getGameWindow().getServerProxy()->getGame()->getCountryOwner(getSecondCountry()->getNombre());
            
                parameters.push_back(getFirstCountry()->getNombre());
                parameters.push_back(getSecondCountry()->getNombre());
                parameters.push_back(armyCountStr.str());
                parameters.push_back(firstPlayerStr.str());
                parameters.push_back(secondPlayerStr.str());

                Attack attack(parameters);
                attack.setFrom(getGameWindow().getServerProxy()->getMe());
                attack.setTo(getGameWindow().getServerProxy()->getGame()->getCountryOwner(getSecondCountry()->getNombre()));
                getGameWindow().getServerProxy()->notify(attack);
                ReferenceCountPtr<ClientState> waiting = new ClientWaiting(getGameWindow());
                getGameWindow().setState(waiting);
            }
        }
    }       
}

