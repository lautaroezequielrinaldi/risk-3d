#include "battleresultclientcommand.h"

BattleResultClientCommand::BattleResultClientCommand(ReferenceCountPtr<Game>& game): ClientCommand(game) {
	/// No realiza ninguna accion.
}

void BattleResultClientCommand::execute() {
    ReferenceCountPtr<Game> game = this->gameManager->getGame();
    ReferenceCountPtr<Mapa> map = game->getMapa();
    ReferenceCountPtr<Pais> paisAtacante = map->obtenerPais( command.getAttackerLand() );
    ReferenceCountPtr<Pais> paisDefensor = map->obtenerPais( command.getDefenderLand() );

    ReferenceCountPtr<Player> playerAtacante = game->getPlayer( command.getAttackercolor() );
    ReferenceCountPtr<Player> playerDefensor = game->getPlayer( command.getDefenderColor() );

    paisAtacante->removeArmies(command.getAttackerResult());
    paisDefensor->removeArmies(command.getDefenderResult());

    if ( paisDefensor->getArmyCount() == 0  ){
        std::string defLand = command.getDefenderLand();
        playerDefensor->removeConqueredLand(defLand);

        playerAtacante->addConqueredLand(defLand );
        paisAtacante->removeArmies( command.getConquest() );
        paisDefensor->addArmies(  command.getConquest() );
        std::vector<std::string> vecContinentes = game->conformContinent(playerAtacante->getConqueredLandList() );
        for ( unsigned int i=0; i<vecContinentes.size();i++){
            //si playerAtacante no es dueño todavia de uno de los continentes conquistados segun vecContinentes
            if ( !playerAtacante->continentOwner( vecContinentes[i] ) )
                //seteo al continente actual como conquistado por el player atacante
                playerAtacante->addConqueredContinent(vecContinentes[i] );
        }
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

