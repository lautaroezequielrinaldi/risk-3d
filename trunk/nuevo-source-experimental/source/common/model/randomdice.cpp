#include "randomdice.h"
#include<stdlib.h>
#include <time.h>
#include <stdio.h>

#include <iostream>
using namespace std;

RandomDice::RandomDice():
Dice()
{
}

RandomDice::~RandomDice()
{
}

int RandomDice::roll(){
	
	int valor=0;
	int res=0;
		
	srand(time(NULL));
	
	valor = rand();
	// aplico mod 6  al numero devuelto por random y sumo 1 para que me devuelva un numero entre 1 y 6.
	res = (valor % 6)+1;
	
	return res;
	
	
	
}


int RandomDice::roll(int maxLimit){
	
	int valor=0;
	int res=0;
		
	srand(time(NULL));
	
	valor = rand();
	// aplico mod maxLimit  al numero devuelto por random y sumo 1 para que me devuelva un numero entre 1 y maxLimit
	res = (valor % maxLimit)+1;
	
	cerr<<"Pos random devuelta: "<< res << endl;
	
	return res;
	
}

