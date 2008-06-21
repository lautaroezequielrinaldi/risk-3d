#include "defending.h"

Defending::Defending(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Defending::~Defending()
{
}

bool Defending::defend(Defend & command){
	
	
}

