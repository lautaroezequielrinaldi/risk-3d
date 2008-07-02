#include "battleresultclientcommand.h"

BattleResultClientCommand::BattleResultClientCommand(ReferenceCountPtr<Game>& game): ClientCommand(game) {
	/// No realiza ninguna accion.
}

void BattleResultClientCommand::execute() {
    ReferenceCountPtr<Mapa> map = this->game->getMapa();
    ReferenceCountptr<Pais> pais = map->obtenerPais(this->paisDestino);
    pais->addArmies(getArmyCount());
}

std::string BattleResultClientCommand::getType() {
	return "BATTLERESULT";
}

ClientCommand* BattleResultClientCommand::clone() {
	return new BattleResultClientCommand(getGame());
}

BattleResultClientCommand::~BattleResultClientCommand() {
	// No realiza ninguna accion.
}

