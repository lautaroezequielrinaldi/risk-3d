#include "quit.h"

Quit::Quit(){

}
Quit::~Quit(){

}

std::string Quit::serialize(){
	return "<?xml version=\"1.0\"?><quit><from>$player></from><to>0</to></quit>";
}
bool Quit::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}
void* Quit::hydrate(std::string xml){

	return NULL;
}

void Quit::execute(ReferenceCountPtr<State>& state){
	
	state->quit(*this);
	
}
std::string Quit::getName() {
	return "quit";
}
