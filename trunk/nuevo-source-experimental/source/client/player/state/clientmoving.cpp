#include "clientmoving.h"
#include "../gamewindow.h"

ClientMoving::ClientMoving(GameWindow& gameWindow): ClientState(gameWindow) {
    // No realiza ninguna accion.
}

ClientMoving::~ClientMoving() {
    // No realiza ninguna accion.
}

void ClientMoving::selectCountry(ReferenceCountPtr<Pais>& country) {
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

                armyCountStr << getArmyCount();
                firstPlayerStr << getGameWindow().getServerProxy()->getMe();
            
                parameters.push_back(getFirstCountry()->getNombre());
                parameters.push_back(getSecondCountry()->getNombre());
                parameters.push_back(armyCountStr.str());
                parameters.push_back(firstPlayerStr.str());

                Move move(parameters);
                move.setFrom(getGameWindow().getServerProxy()->getMe());
                getGameWindow().getServerProxy()->notify(move);
                ReferenceCountPtr<ClientState> waiting = new ClientWaiting(getGameWindow());
                getGameWindow().setState(waiting);
            }
        }
    }       
}

