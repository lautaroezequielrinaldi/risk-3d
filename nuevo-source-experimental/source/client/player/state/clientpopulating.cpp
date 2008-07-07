#include "clientpopulating.h"
#include "../gamewindow.h"

ClientPopulating::ClientPopulating(GameWindow& gameWindow):
    ClientState(gameWindow) {
    // No realiza ninguna accion.
}

void ClientPopulating::selectCountry(ReferenceCountPtr<Pais>& country) {
    if (getGameWindow().getServerProxy() != NULL) {
        Populate populate;
        getGameWindow().getServerProxy()->notify(populate);
    }
}

ClientPopulating::~ClientPopulating() {
    // No realiza ninguna accion.
}

