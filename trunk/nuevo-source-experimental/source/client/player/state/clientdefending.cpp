#include "clientdefending.h"
#include "../gamewindow.h"

ClientDefending::ClientDefending(GameWindow& gameWindow, const std::string& attackedCountry):
    ClientState(gameWindow),
    attackedCountry(attackedCountry) {
    // No realiza ninguna accion.ç
}

void ClientDefending::selectCountry(ReferenceCountPtr<Pais>& country) {
    if (country != NULL) {
        if (country->getNombre() == attackedCountry) {
            ClientState::selectCountry(country);
        }
    }
}

void ClientDefending::executeNoMore() {
    if (getGameWindow().getServerProxy() != NULL) {
        Defend defend;
        getGameWindow().getServerProxy()->notify(defend);
    }
}

ClientDefending::~ClientDefending() {
    // No realiza ninguna accion.
}

