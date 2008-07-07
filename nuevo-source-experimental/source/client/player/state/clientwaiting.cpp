#include "clientwaiting.h"
#include "../gamewindow.h"

ClientWaiting::ClientWaiting(GameWindow& gameWindow):
    ClientState(gameWindow) {
    // No realiza ninguna accion.
}

void ClientWaiting::selectCountry(ReferenceCountPtr<Pais>& country) {
    // No se puede seleccionar pais al estar esperando.
}

ClientWaiting::~ClientWaiting() {
    // No realiza ninguna accion.
}

