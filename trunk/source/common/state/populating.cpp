#include "populating.h"

Populating::Populating(ReferenceCountPtr<GameManager>&gameManager):State(gameManager)
{
}

Populating::~Populating()
{
}
bool Populating::populate(Populate & command){

	return false;
}
