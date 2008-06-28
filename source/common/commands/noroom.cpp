#include "noroom.h"

NoRoom::NoRoom(){

}
NoRoom::~NoRoom(){

}

std::string NoRoom::serialize(){
	return "<?xml version=\"1.0\"?><NoRoom><from>0</player><to>0</to><msg>$message></msg></NoRoom>";
}
bool NoRoom::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}
void* NoRoom::hydrate(std::string xml){

	return NULL;
}

void NoRoom::execute(ReferenceCountPtr<State>& state){
	
	state->noRoom(*this);
	
}

std::string NoRoom::getName() {
	return "NoRoom";
}
