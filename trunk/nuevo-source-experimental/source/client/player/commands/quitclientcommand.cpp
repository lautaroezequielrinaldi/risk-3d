#include "quitclientcommand.h"

QuitClientCommand::QuitClientCommand(ReferenceCountPtr<Game>& game): Quit(), ClientCommand(game) {
    // No realiza ninguna accion.
}

void QuitClientCommand::execute() {
    ReferenceCountPtr<Player> jugadorSuertudo = getGame()->getPlayer( getTo() );
    ReferenceCountPtr<Player> jugadorRendido =  getGame()->getPlayer(getFrom());

    //actualiza modelo transfiriendo paises del jugador rendido al jugador suertudo que los gano.
    jugadorSuertudo->transferLandsFrom(jugadorRendido);
    // Remueve al jugador del juego.
    getGame()->removePlayer(jugadorRendido);
}

ReferenceCountPtr<ClientCommand> QuitClientCommand::clone() {
    return new QuitClientCommand(getGame());
}

QuitClientCommand::~QuitClientCommand() {
    // No realiza ninguna accion.
}

