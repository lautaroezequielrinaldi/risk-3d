#include "attacking.h"

Attacking::Attacking(ReferenceCountPtr<GameManager>&gameManager):State(gameManager)
{
}

Attacking::~Attacking()
{
}


bool Attacking::attack(Attack & command){
	
	return false;
}



