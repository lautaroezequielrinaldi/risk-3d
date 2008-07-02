#include "battleresultclientcommand.h"

BattleResultClientCommand::BattleResultClientCommand(ReferenceCountPtr<Game>& game): ClientCommand(game) {
	/// No realiza ninguna accion.
}

void BattleResultClientCommand::execute() {
    
    ReferenceCountPtr<Mapa> map = this->getGame()->getMapa();
    ReferenceCountPtr<Pais> paisAtacante = map->obtenerPais( getAttackerLand() );
    ReferenceCountPtr<Pais> paisDefensor = map->obtenerPais( getDefenderLand() );

    ReferenceCountPtr<Player> playerAtacante = game->getPlayer( getAttackercolor() );
    ReferenceCountPtr<Player> playerDefensor = game->getPlayer( getDefenderColor() );

    paisAtacante->removeArmies(getAttackerResult());
    paisDefensor->removeArmies(getDefenderResult());

    if ( paisDefensor->getArmyCount() == 0  ){
        std::string defLand = getDefenderLand();
        playerDefensor->removeConqueredLand(defLand);

        playerAtacante->addConqueredLand(defLand );
        paisAtacante->removeArmies( getConquest() );
        paisDefensor->addArmies(  getConquest() );
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

