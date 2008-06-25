#include "quit.h"

Quit::Quit(){

}
Quit::~Quit(){

}

std::string Quit::serialize(){

	return "unimplemented";
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
