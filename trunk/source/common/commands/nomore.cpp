#include "nomore.h"

NoMore::NoMore(){

}

NoMore::~NoMore(){

}

std::string NoMore::serialize(){
	return "<?xml version=\"1.0\"?><nomore><from>$player</from><to>0</to></nomore>";
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