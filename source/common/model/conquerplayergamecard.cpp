#include "conquerplayergamecard.h"

ConquerPlayerGameCard::ConquerPlayerGameCard(const std::string& gameCardName,
    int color):
    GameCard(gameCardName),
    color(color) {
    // No realiza ninguna acciòn.
}

int ConquerPlayerGameCard::getColor() {
    return this->color;
}

std::map<std::string, std::string> ConquerPlayerGameCard::toString() {
    std::ostringstream playerStr;
    playerStr << getColor();
    std::map<std::string, std::string> result;
    result["tipo"] = "CONQUERPLAYERGAMECARD";
    result["nombre"] = getName();
    result["jugador"] = playerStr.str();

    return result;
}

bool ConquerPlayerGameCard::execute(ReferenceCountPtr<GameManager>& gameManager){
	
	bool res = false;
	ReferenceCountPtr<TurnManager> turnManeger = gameManager->getTurnManager();
	
	// si el jugador que se debe eliminar, ya no esta activo en la lista de turnos del juego
	if ( ! turnManeger->isPlayerActive( this->color ) )
		// el objetivo se cumplio
		res= true;
	
	return res;	

}


ConquerPlayerGameCard::~ConquerPlayerGameCard() {
    // No realiza ninguna acciòn.
}

