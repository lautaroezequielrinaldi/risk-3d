#include "occupying.h"

Occupying::Occupying(ReferenceCountPtr<GameManager>&gameManager):State(gameManager)
{
}

Occupying::~Occupying()
{
}

bool Occupying::populate(Populate & command){

        return false;
}

