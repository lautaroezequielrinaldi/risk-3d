#include "noroom.h"

NoRoom::NoRoom(){

}
NoRoom::~NoRoom(){

}

std::string NoRoom::serialize(){
	return "<?xml version=\"1.0\"?><NoRoom>"+Command::serialize(0,0)+"</NoRoom>";
}
bool NoRoom::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}


void NoRoom::execute(ReferenceCountPtr<State>& state){
	
	state->noRoom(*this);
	
}

std::string NoRoom::getName() {
	return "NoRoom";
}
