#include "simplepopulating.h"

SimplePopulating::SimplePopulating(ReferenceCountPtr<GameManager>&gameManager):State(gameManager)
{
}

SimplePopulating::~SimplePopulating()
{
}


bool SimplePopulating::populate(Populate & command){

        return false;
}

