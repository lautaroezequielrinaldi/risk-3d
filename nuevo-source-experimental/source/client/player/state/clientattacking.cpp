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
                Attack attack;
                getGameWindow().getServerProxy()->notify(attack);
            }
        }
    }       
}

