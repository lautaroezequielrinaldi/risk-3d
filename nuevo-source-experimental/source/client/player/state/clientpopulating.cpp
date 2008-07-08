#include "clientpopulating.h"
#include "../gamewindow.h"

ClientPopulating::ClientPopulating(GameWindow& gameWindow):
    ClientState(gameWindow) {
    // No realiza ninguna accion.
}

void ClientPopulating::selectCountry(ReferenceCountPtr<Pais>& country) {
    if (getGameWindow().getServerProxy() != NULL) {
        std::vector<std::string> parameters;
        std::ostringstream playerStr;

        playerStr << getGameWindow().getServerProxy()->getMe();

        parameters.push_back(country->getNombre());
        parameters.push_back("1");
        parameters.push_back(playerStr.str());

        Populate populate(parameters);
        getGameWindow().getServerProxy()->notify(populate);
    }
}

ClientPopulating::~ClientPopulating() {
    // No realiza ninguna accion.
}

