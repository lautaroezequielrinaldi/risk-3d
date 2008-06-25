#include "nomore.h"

NoMore::NoMore(){

}

NoMore::~NoMore(){

}

std::string NoMore::serialize(){

	return "unimplemented";
}
bool NoMore::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}
void* NoMore::hydrate(std::string xml){

	return NULL;
}


void NoMore::execute(ReferenceCountPtr<State>& state){
	
	state->noMore(*this);
	
}
std::string NoMore::getName() {
	return "noMore";
}
