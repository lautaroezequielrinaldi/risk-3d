#include "populating.h"

Populating::Populating(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Populating::~Populating()
{
}
bool Populating::populate(Populate & command){

	return false;
}
