#include "turnmanager.h"
#include<stdlib.h>

TurnManager::TurnManager()
{
	this->jugadorActual = -1;
	//this->cantEjercitosBonus 
}

TurnManager::~TurnManager()
{
}

void TurnManager::setTurnOrder(int firstPlayerColor){
	
	//seteo el jugador actual con el color del jugador que jugara 1ero.
	this->jugadorActual = firstPlayerColor;
	/*
	std::vector<int> vecAuxColores;
	bool seguir = true;
	int posRand;
	
	
		
	// inicializo vecAuxColores con los numeros que representan a cada color de un jugador.
	for(int i=0;i<playerCount;i++)
		vecAuxColores[i] = i+1;
	
	for(int j=0;j<playerCount;j++){
		
		do{
			// pido un entero aleatorio, entre 1 y playerCount
			posRand = random();
			posRand = ( posRand % playerCount ) +1;
			
			// si no se asigno la poscion obtenida con random
			if ( this->orden.at(j) == -1 ){
				seguir = false;
				//asigno al vector que contiene el orden de los turnos, un color de jugador
				this->orden[posRand] = vecAuxColores[j];
			}
			
		}while(seguir);
		
	}
		*/
}

int TurnManager::getCurrentPlayer(){
	return this->jugadorActual;	
}

void TurnManager::changeTurn(){
	this->jugadorActual = getNextPlayerTurn();
}

int TurnManager::getNextPlayerTurn(){
	
	bool encontro=false;
	unsigned int i=0;
	int nextPlayer=0;
	
	while( i<this->orden.size() && !encontro){
		
		if ( this->orden.at(i) == this->jugadorActual ){
			
			encontro= true;
			
			// si es el ultimo jugador de la ronda
			if ( i+1 == this->orden.size() )
				//asigno a nextPlayer el primer jugador
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




