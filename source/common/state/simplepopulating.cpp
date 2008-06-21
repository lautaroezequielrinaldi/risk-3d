#include "simplepopulating.h"

SimplePopulating::SimplePopulating(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

SimplePopulating::~SimplePopulating()
{
}


bool SimplePopulating::populate(Populate & command){

        return false;
}

