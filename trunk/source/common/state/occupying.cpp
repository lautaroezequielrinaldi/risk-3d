#include "occupying.h"

Occupying::Occupying(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Occupying::~Occupying()
{
}

bool Occupying::populate(Populate & command){

        return false;
}

