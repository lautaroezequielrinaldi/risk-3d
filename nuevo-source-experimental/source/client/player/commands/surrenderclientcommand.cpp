#include "surrenderclientcommand.h"

SurrenderClientCommand::SurrenderClientCommand(ReferenceCountPtr<Game>& game):
    Surrender(), ClientCommand(game) {
    // No realiza ninguna acciòn.
}

ClientCommand* SurrenderClientCommand::clone() {
    return new SurrenderClientCommand(getGame());
}

void SurrenderClientCommand::execute() {
    ReferenceCountPtr<Player> jugadorSuertudo = getGame()->getPlayer( getTo() );
    ReferenceCountPtr<Player> jugadorRendido =  getGame()->getPlayer(getFrom());

    if (jugadorSuertudo != NULL && jugadorRendido != NULL) {
        //actualiza modelo transfiriendo paises del jugador rendido al jugador suertudo que los gano.
        jugadorSuertudo->transferLandsFrom(jugadorRendido);
    }
}

SurrenderClientCommand::~SurrenderClientCommand() {
    // No realiza ninguna accion.
}

