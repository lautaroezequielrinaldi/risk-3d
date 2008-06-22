#include "surrender.h"

Surrender::Surrender(){

}

Surrender::~Surrender(){

}

std::string Surrender::serialize(){

	return "unimplemented";
}
bool Surrender::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}
void* Surrender::hydrate(std::string xml){

	return NULL;
}

void Surrender::execute(ReferenceCountPtr<State>& state){
	
	state->surrender(*this);
	
}
