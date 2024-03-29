#include "noroom.h"
#include "commandobserver.h"

NoRoom::NoRoom(){

}
NoRoom::~NoRoom(){

}

std::string NoRoom::serialize(){
	return "<?xml version=\"1.0\"?><NoRoom>"+serializeCommon(0,0)+"</NoRoom>";
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

void NoRoom::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

