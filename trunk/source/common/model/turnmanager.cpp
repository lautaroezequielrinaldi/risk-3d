#include "turnmanager.h"
#include<stdlib.h>

TurnManager::TurnManager()
{
	this->jugadorActual = 0;
	this->jugadorDefensor = 0;
	this->ultimoJugador=0;
	//this->cantEjercitosBonus 
}

TurnManager::~TurnManager()
{
}

void TurnManager::setTurnOrder(int firstPlayerColor){
	
	bool encontrado=false;
	int i=0;
	
	//seteo el jugador actual con el color del jugador que jugara 1ero.
	this->jugadorActual = firstPlayerColor;
	
	//busco pos en vector del firstPlayerColor	
	while ( i< this->orden.size() && !encontrado) {
	
		if (this->orden.at(i) == firstPlayerColor )
			encontrado=true;
		else
			i++;
	}
	
	// si el primer jugador esta en la pos 0 del vec
	if ( i== 0)
		// el ultimo esta en la ultima pos del vector
		this->ultimoJugador = this->orden.back();
	else
		//el ultimo esta en una pos atras del 1ero
		this->ultimoJugador = this->orden.at(i - 1);

}

int TurnManager::getCurrentPlayer(){
	return this->jugadorActual;	
}

void TurnManager::changeTurn(){
	this->jugadorActual = getNextPlayerTurn();
}

void TurnManager::changeTurn(int color){
	this->jugadorActual = color;
}


int TurnManager::getNextPlayerTurn(){
	
	bool encontro=false;
	unsigned int i=0;
	int nextPlayer=0;
	
	while( i<this->orden.size() && !encontro){
		
		if ( this->orden.at(i) == this->jugadorActual ){
			
			encontro= true;
			
			// si es el ultimo jugador del vec
			if ( i+1 == this->orden.size() )
				//asigno a nextPlayer el primer jugador del vec
				nextPlayer = this->orden.at(0);
			else
				//asigno a nextPlayer el siguiente a i.
				nextPlayer = this->orden.at(i+1);
		}
		else
			i++;
		
	}
	
	return nextPlayer;
 
}

void TurnManager::addPlayer(int color){
	
	// agrego color del jugador en el vector de colores que almacenara el orden 
	this->orden.push_back(color);
	
}

void TurnManager::deletePlayer(int color){
	
	std::vector<int>::iterator it;	
	bool encontrado = false;
	int colorActual;
	
	//si se quiere eliminar el jugador que posee el turno
	if ( color == this->jugadorActual )
		// hago un cambio de turno antes de eliminar al jugador
		changeTurn();
		
	it = this->orden.begin();
	// busco al jugador que se desea eliminar para confirmar que exista en la lista de players activos.
	while ( it != this->orden.end() && !encontrado) {
		
		colorActual = *it;
		// si se encontro el color buscado
		if ( colorActual == color ){
			// elimino al jugador del vector.
			this->orden.erase(it);
			encontrado = true;
		}
		else
			++it;
	
	}	
	
}

int TurnManager::getLastPlayer(){
	return this->ultimoJugador;	
}

int TurnManager::getDefenderPlayer(){
	return this->jugadorDefensor;
}

void TurnManager::setDefenderPlayer(int color){
	this->jugadorDefensor = color;
}

bool TurnManager::isPlayerActive(int color){
	
	int colorActual= -1;
	std::vector<int>::iterator it;
	
	it = this->orden.begin();
	//busco el jugador indicado en vector orden 
	while ( it != this->orden.end()) {
		
		colorActual = *it;
		// si se encontro el color buscado
		if ( colorActual == color )
			return true;
	
	}
	
	return false;	
	
}


