#include "surrender.h"

Surrender::Surrender(){

}

Surrender::~Surrender(){

}

std::string Surrender::serialize(){
	return "<?xml version=\"1.0\"?><surrender><from>$player</from><to>0</to></surrender>";
	
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
std::string Surrender::getName() {
	return "surrender";
}
