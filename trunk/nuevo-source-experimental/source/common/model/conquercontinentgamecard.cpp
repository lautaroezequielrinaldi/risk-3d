#include "conquercontinentgamecard.h"

ConquerContinentGameCard::ConquerContinentGameCard(
    const std::string& name, const std::string& continentName):
    GameCard(name),
    continentName(continentName) {
    // No realiza ninguna acciòn.
}

std::string ConquerContinentGameCard::getContinentName() {
    return this->continentName;
}

/* deshabilitado por Charli para compilar
bool ConquerContinentGameCard::execute(const ReferenceCountPtr<Player>& player,
    const ReferenceCountPtr<Game>& game) {
    return false;
}
*/

std::map<std::string, std::string> ConquerContinentGameCard::toString() {
    std::map<std::string, std::string> result;
    result["tipo"] = "CONQUERCONTINENTGAMECARD";
    result["nombre"] = getName();
    result["continente"] = getContinentName();

    return result;
}

ConquerContinentGameCard::~ConquerContinentGameCard() {
    // No realiza ninguna acciòn.
}

bool ConquerContinentGameCard::execute(ReferenceCountPtr<GameManager>& gameManager){
	
	bool res=false;
	ReferenceCountPtr<TurnManager> turnManeger = gameManager->getTurnManager();
	ReferenceCountPtr<Player> currentPlayer = gameManager->getGame()->getPlayer(turnManeger->getCurrentPlayer() );
	
	
	std::string cont = this->continentName;
	// si el jugador conquisto todo el continente
	if ( currentPlayer->continentOwner( cont ) )
		res=true;
		
	return res;
	
}

