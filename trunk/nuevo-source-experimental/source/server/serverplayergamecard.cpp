#include "serverplayergamecard.h"

ServerPlayerGameCard::ServerPlayerGameCard(const std::string& gameCardName,
    int color):
    GameCardValidator(),
    GameCard(gameCardName, color) {
    // No realiza ninguna acciòn.
}

bool ServerPlayerGameCard::validate(ReferenceCountPtr<GameManager>& gameManager){
	
	bool res = false;
	ReferenceCountPtr<TurnManager> turnManeger = gameManager->getTurnManager();
	
	// si el jugador que se debe eliminar, ya no esta activo en la lista de turnos del juego
	if ( ! turnManeger->isPlayerActive( this->color ) )
		// el objetivo se cumplio
		res= true;
	
	return res;	

}


ServerPlayerGameCard::~ConquerPlayerGameCard() {
    // No realiza ninguna acciòn.
}

