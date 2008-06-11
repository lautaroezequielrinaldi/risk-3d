#include "randomdice.h"
#include<stdlib.h>

RandomDice::RandomDice():
Dice()
{
}

RandomDice::~RandomDice()
{
}

int RandomDice::roll(){
	
	int valor=0;
	
	// pido un numero aleatorio
	valor = random();
		
	// aplico mod 6  al numero devuelto por random y sumo 1 para que me devuelva un numero entre 1 y 6.
	return ( valor % 6 ) + 1; 
	
}

